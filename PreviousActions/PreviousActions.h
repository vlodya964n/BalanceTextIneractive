#pragma once

#include <iostream>
#include <vector>

class PreviousActions
{
public:
	PreviousActions();
	~PreviousActions() = default;
	std::string GetPrevActions();
	void SetPrevAction(std::string);
	void SavePrevActions();
private:
	std::vector<std::string> actions;
	std::string PreviousActionsFilePath;
};
