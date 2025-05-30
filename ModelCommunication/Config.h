#pragma once

#include <iostream>

class Config
{
public:
	Config();
	~Config() = default;

	std::string GetWorkType();
	int GetTreeDepth();
	std::string GetInteractiveType();
	std::string GetCurrentSettingsPath();
private:
	void InputData();
	std::string filePath;
	std::string workType;
	int treeDepth;
	std::string interactiveType;

	std::string currentSettingsPath;
};
