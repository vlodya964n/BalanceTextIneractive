#include "BalancingTree.h"

#include <unordered_set>
#include <sstream>
#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

BalancingTree::BalancingTree(int depth_) : maxDepth{ depth_ } {
    
    actionsNRules = std::make_unique<ActionsnNRules>();
    root = std::make_shared<Node>();
    root->depth = 0;
    current = root;

    for (const auto& actionId : actionsNRules->GetActionIds()) {
        std::shared_ptr<Node> child = std::make_shared<Node>();
        child->path.push_back(actionId);
        child->depth = 1;
        child->action_id = actionId;
        root->children.push_back(child);
        BuildTree(child);
    }

    ComputeProbabilities(root);
}

void BalancingTree::BuildTree(std::shared_ptr<Node> node) {
    int reward = actionsNRules->CompareWithRules(node->path);
    if (node->depth == maxDepth || reward != 0) {
        node->is_leaf = true;
        if (reward < 0) {
            node->good_prob = 0.0f;
            node->neut_prob = 0.0f;
            node->bad_prob = 1.0f;
        }
        else if (reward > 0) {
            node->good_prob = 1.0f;
            node->neut_prob = 0.0f;
            node->bad_prob = 0.0f;
        }
        else {
            node->good_prob = 0.0f;
            node->neut_prob = 1.0f;
            node->bad_prob = 0.0f;
        }
        return;
    }

    for (auto i : actionsNRules->GetActionIds()) {
        std::shared_ptr<Node> child = std::make_shared<Node>();
        child->path = node->path;
        child->path.push_back(i);
        child->depth = node->depth + 1;
        child->action_id = i;
        node->children.push_back(child);
        BuildTree(child);
    }
}

void BalancingTree::ComputeProbabilities(std::shared_ptr<Node>& node) {
    if (node->is_leaf) return;

    float total_good = 0.0f, total_neut = 0.0f, total_bad = 0.0f;

    for (auto& child : node->children) {
        ComputeProbabilities(child);
        total_good += child->good_prob;
        total_neut += child->neut_prob;
        total_bad += child->bad_prob;
    }

    float total = total_good + total_neut + total_bad;
    if (total > 0.0f) {
        node->good_prob = total_good / total;
        node->neut_prob = total_neut / total;
        node->bad_prob = total_bad / total;
    }
}

bool BalancingTree::IsCurrentNodeLeaf() {
    return current->is_leaf;
}

void BalancingTree::NavigateToAction(std::string action_) {
    int id = actionsNRules->GetActionIdByName(action_);
    try {
        for (const auto& child : current->children) {
            if (child->action_id == id) {
                current = child;
                return;
            }
        }
        current = nullptr;
    }
    catch (...) {
        std::cerr << "current node does not accept actions\n";
    }
}

std::string BalancingTree::GetJsonState() {
    nlohmann::json result;
    result["current_action"] = current->action_id >= 0 ? actionsNRules->GetActionNameById(current->action_id) : "root";
    result["maximum_remaining_moves"] = std::to_string(maxDepth - 1 - current->depth) + "/" + std::to_string(maxDepth - 1);

    result["next_actions"] = json::array();
    for (const auto& child : current->children) {
        json item;
        std::ostringstream oss_good, oss_neut, oss_bad;
        item["action"] = actionsNRules->GetActionNameById(child->action_id);
        oss_good << std::setprecision(2) << std::fixed << child->good_prob;
        oss_neut << std::setprecision(2) << std::fixed << child->neut_prob;
        oss_bad << std::setprecision(2) << std::fixed << child->bad_prob;
        item["good_prob"] = oss_good.str();
        item["neut_prob"] = oss_neut.str();
        item["bad_prob"] = oss_bad.str();
        result["next_actions"].push_back(item);
    }
    return result.dump(4);
}

std::string BalancingTree::GetRewardProbabilities() {
      std::ostringstream oss;
      oss << std::setprecision(2) << std::fixed
          << std::setw(30) << "Root Reward Probabilities"
          << std::endl
          << std::setw(10) << "Good"
          << std::setw(10) << "Neutral"
          << std::setw(10) << "Bad"
          << std::endl
          << std::setw(10) << root->good_prob
          << std::setw(10) << root->neut_prob
          << std::setw(10) << root->bad_prob
          << std::endl;
    return oss.str();
}

std::string BalancingTree::GetActions() {
    return actionsNRules->GetActionsToJson();
}