#include "PreviousActions.h"

#include <string>
#include <fstream>
#include <memory>

#include <nlohmann/json.hpp>

#include "../ModelCommunication/Config.h"

using json = nlohmann::json;

PreviousActions::PreviousActions() : PreviousActionsFilePath{ "SavesPreviousActions.txt" } {
	std::unique_ptr<Config> config = std::make_unique<Config>();

	PreviousActionsFilePath = config->GetCurrentSettingsPath() + PreviousActionsFilePath;
}

std::string PreviousActions::GetPrevActions() {
	nlohmann::json result;

	int index = 1;
	for (auto action : actions) {
		result[std::to_string(index)] = json::parse(action);
		index++;
	}

	if (!actions.empty()) {
		return result.dump(4);
	}
	else {
		return "{}";
	}
	
}

void PreviousActions::SetPrevAction(std::string action_) {
	actions.push_back(action_);
}

void PreviousActions::SavePrevActions() {
	std::ofstream out;
	out.open(/*"SavesPreviousActions/SavesPreviousActions.txt"*/ PreviousActionsFilePath);
	if (out.is_open())
	{
		out << GetPrevActions() << std::endl;
	}
	out.close();
}