#pragma once
#include <iostream>
#include<memory>
#include <vector>
#include <unordered_map>

#include "Action.h"
#include "Rule.h"


class ActionsnNRules
{
public:
    ActionsnNRules();
    ~ActionsnNRules() = default;
    int GetActionIdByName(const std::string&) const;
    std::string GetActionNameById(int) const;
    std::string GetActionsToJson() const;
    std::string GetRulesAsWords() const;
    int CompareWithRules(const std::vector<int>&);
    std::vector<int> GetActionIds();
private:
    std::vector<Action> actions;
    std::unordered_map<std::string, int> actionNameToId;
    std::unordered_map<int, std::string> idToActionName;
    std::vector<Rule> actionsRules;
};
