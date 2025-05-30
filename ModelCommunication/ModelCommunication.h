#pragma once

#include<memory>

#include "../AIModel/AIModel.h"
#include "../ProgramRequests/ProgramRequests.h"
#include "../RequestProcessing/RequestProcessing.h"
#include "../BalancingTree/BalancingTree.h"
#include "../PreviousActions/PreviousActions.h"
#include "../UserInteractive/UserInteractive.h"
#include "../UserInteractive/OutputData.h"

#include "Config.h"

namespace communicate {
	class ModelCommunication
	{
	public:
		ModelCommunication();
		~ModelCommunication() = default;
		
		void Start();
	private:
		void StartDialogue();
		void ViewTreeRewards();

		std::unique_ptr<aim::AIModel> aiModel;
		std::unique_ptr<prog_req::ProgramRequests> currentRequest;
		std::unique_ptr<req_proc::RequestProcessing> requestProcessing;
		std::unique_ptr<PreviousActions> previousActions;
		std::unique_ptr<UserInteractive> userInteractive;
		std::unique_ptr<OutputData> outputData;
		std::unique_ptr<BalancingTree> tree;

		std::unique_ptr<Config> config;
	};

}

