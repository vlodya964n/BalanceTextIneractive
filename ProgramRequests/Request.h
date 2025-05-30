#pragma once

#include <iostream>

struct Request {
	std::string task;
	std::string inputDescription;
	std::string situation;
	std::string endings;
	std::string previousActions;
	std::string actionsNames;
	std::string currentState;
	std::string currentAction;
	std::string outputFormat;
};