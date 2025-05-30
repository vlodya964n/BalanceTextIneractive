#pragma once

#include <iostream>
#include <vector>

#include "InputData.h"

class ScriptInput : public InputData
{
public:
	ScriptInput();
	~ScriptInput() = default;
	std::string GetAction() override;
private:
	std::vector<std::string> actions;
	void InputData();
	std::string filePath;
};
