#pragma once

#include <iostream>
#include <vector>

#include "Action.h"
#include "Rule.h"

class ActionsNRulesSource
{
public:
	virtual ~ActionsNRulesSource() = default;
	virtual std::vector<Action> GetActions() = 0;
	virtual std::vector<Rule> GetRules() = 0;
};
