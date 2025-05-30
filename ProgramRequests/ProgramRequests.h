#pragma once

#include <iostream>

#include "Request.h"

struct ChangesRequest {
	std::string previousActions;
	std::string actionsNames;
	std::string currentState;
	std::string currentAction;
};

namespace prog_req {
	class ProgramRequests
	{
	private:
		Request beginingRequestElements;
		ChangesRequest changingRequestElements;
	public:
		ProgramRequests();
		std::string GetRequest();
		void SetPreviousActions(std::string);
		void SetActionsNames(std::string);
		void SetCurrentState(std::string);
		void SetCurrentAction(std::string);
	};
}
