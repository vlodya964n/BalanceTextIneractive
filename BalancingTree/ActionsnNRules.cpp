#include "ActionsnNRules.h"



#include <nlohmann/json.hpp>

#include "ActionsNRulesSource.h"
#include "ActionsNRulesInput.h"

ActionsnNRules::ActionsnNRules() {
    std::unique_ptr<ActionsNRulesSource> source = std::make_unique<ActionsNRulesInput>();
    actions = std::move(source->GetActions());
    actionsRules = std::move(source->GetRules());

    for (auto action : actions) {
        actionNameToId[action.name] = action.id;
        idToActionName[action.id] = action.name;
    }
}

int ActionsnNRules::GetActionIdByName(const std::string& name) const {
    auto it = actionNameToId.find(name);
    if (it != actionNameToId.end()) {
        return it->second;
    }
    else {
        throw std::runtime_error("Action name not found: " + name);
    }
}

std::string ActionsnNRules::GetActionNameById(int id) const {
    auto it = idToActionName.find(id);
    if (it != idToActionName.end()) {
        return it->second;
    }
    else {
        throw std::runtime_error("Action id not found: " + id);
    }
}

std::vector<int> ActionsnNRules::GetActionIds() {
    std::vector<int> ids;
    for (auto action : actions) {
        ids.push_back(action.id);
    }
    return ids;
}

int ActionsnNRules::CompareWithRules(const std::vector<int>& path) {
    for (const auto& rule : actionsRules) {
        int rule_index = 0;
        for (int action : path) {
            if (action == rule.actionSequence[rule_index]) {
                rule_index++;
                if (rule_index == rule.actionSequence.size()) {
                    if (rule.isGoodRule) {
                        return 1;
                    }
                    else {
                        return -1;
                    }
                }
            }
        }
    }
    return 0;
}

std::string ActionsnNRules::GetActionsToJson() const {
    nlohmann::json j;
    for (const auto& action : actions) {
        j.push_back({
            {"name", action.name},
            {"description", action.description}
            });
    }
    return j.dump(4);
}

std::string ActionsnNRules::GetRulesAsWords() const {
    nlohmann::json j;

    std::vector<std::vector<std::string>> good_rules;
    std::vector<std::vector<std::string>> bad_rules;

    for (const auto& rule : actionsRules) {
        std::vector<std::string> words;
        for (int id : rule.actionSequence) {
            if (id >= 0 && id < actions.size()) {
                words.push_back(actions[id].name);
            }
            else {
                words.push_back("[UNKNOWN_ID_" + std::to_string(id) + "]");
            }
        }
        if (rule.isGoodRule == true) {
            good_rules.push_back(words);
        }
        else {
            bad_rules.push_back(words);
        }
    }

    j["good_ending"] = good_rules;
    j["bad_ending"] = bad_rules;

    return j.dump(4);
}