#pragma once

#include <vector>

#include "Action.h"
#include "Rule.h"
#include "ActionsNRulesSource.h"


class ActionsNRulesInput : public ActionsNRulesSource
{
public:
	ActionsNRulesInput();
	~ActionsNRulesInput() = default;
	std::vector<Action> GetActions() override;
	std::vector<Rule> GetRules() override;

private:
	std::vector<Action> actions;
	std::vector<Rule> actionsRules;

	void InputActions();
	void InputRules();

	std::string actionsFilePath;
	std::string rulesFilePath;
};
