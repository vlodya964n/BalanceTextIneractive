#include "ModelCommunication.h"

#include<iostream>

namespace communicate {
	ModelCommunication::ModelCommunication() {
		config = std::make_unique<Config>();

		aiModel = std::make_unique<aim::AIModel>();
		currentRequest = std::make_unique<prog_req::ProgramRequests>();
		requestProcessing = std::make_unique<req_proc::RequestProcessing>();
		previousActions = std::make_unique<PreviousActions>();
		userInteractive = std::make_unique<UserInteractive>(config->GetInteractiveType());
		outputData = std::make_unique<OutputData>();
		tree = std::make_unique<BalancingTree>(config->GetTreeDepth());
	}

	void ModelCommunication::StartDialogue() {
		while (!tree->IsCurrentNodeLeaf()) {
			currentRequest->SetActionsNames(tree->GetActions());
			currentRequest->SetCurrentState(tree->GetJsonState());

			currentRequest->SetPreviousActions(previousActions->GetPrevActions());

			currentRequest->SetCurrentAction(userInteractive->GetUserAction());

			aiModel->SendRequest(currentRequest->GetRequest());
			while (!requestProcessing->ParseResponse(aiModel->GetResponse())) {
				aiModel->SendRequest(currentRequest->GetRequest());
			}

			previousActions->SetPrevAction(requestProcessing->GetResponse());
			previousActions->SavePrevActions();
			
			outputData->PrintIncident(requestProcessing->GetIncident());

			tree->NavigateToAction(requestProcessing->GetAction());
		}
	}

	void ModelCommunication::ViewTreeRewards() {
		std::cout << tree->GetRewardProbabilities();
	}

	void ModelCommunication::Start() {
		if (config->GetWorkType() == "dialogue") {
			StartDialogue();
		}
		else if (config->GetWorkType() == "view_rewards") {
			ViewTreeRewards();
		}
		else {
			std::cerr << "Incorrect work type from config.json\n";
		}
	}
}
