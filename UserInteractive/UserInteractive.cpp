#include "UserInteractive.h"

#include "ConsoleInput.h"
#include "ScriptInput.h"

UserInteractive::UserInteractive(std::string inputType) {
	if (inputType == "script") {
		inputAction = std::make_unique<ScriptInput>();
	}
	else {
		inputAction = std::make_unique<ConsoleInput>();
	}
	
}

std::string UserInteractive::GetUserAction() {
	return inputAction->GetAction();
}