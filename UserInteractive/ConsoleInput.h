#pragma once

#include "InputData.h"
#include <iostream>

class ConsoleInput : public InputData
{
public:
	ConsoleInput() = default;
	~ConsoleInput() = default;
	std::string GetAction() override;
};
