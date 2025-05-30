#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include "ActionsnNRules.h"

struct Node {
    std::vector<std::shared_ptr<Node>> children;
    std::vector<int> path;
    int depth;
    float good_prob = 0.0f;
    float neut_prob = 0.0f;
    float bad_prob = 0.0f;
    bool is_leaf = false;
    int action_id = -1;
};

class BalancingTree
{
public:
    BalancingTree(int);
    void NavigateToAction(std::string);
    std::string GetJsonState();
    std::string GetActions();
    std::string GetRewardProbabilities();
    bool IsCurrentNodeLeaf();
private:
    int maxDepth;
    std::unique_ptr<ActionsnNRules> actionsNRules;
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> current;
    void BuildTree(std::shared_ptr<Node>);
    void ComputeProbabilities(std::shared_ptr<Node>&);
};
