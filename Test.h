#pragma once

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
//#include <curl/curl.h>

#include <iostream>

#include "ModelCommunication/ModelCommunication.h"


using json = nlohmann::json;

static std::string api_key = "BOGnY8rz1uSJTHgtjAOv0j4KpcyM2Cqr";
static std::string mistal_models_url = "https://api.mistral.ai/v1/models";
static std::string mistal_chat_url = "https://api.mistral.ai/v1/chat/completions";

void mistral_request() {

    // Формируем JSON-запрос
    nlohmann::json request_body = {
        {"model", "mistral-small-latest"}, // или другой доступный: mistral-small, mistral-medium
        {"messages", {
            {{"role", "user"}, {"content", "Hello! Tell me a joke."}}
        }}
    };

    // Отправка POST-запроса
    cpr::Response response = cpr::Post(
        cpr::Url{ mistal_chat_url },
        cpr::Header{
            {"Authorization", "Bearer " + api_key},
            {"Content-Type", "application/json"}
        },
        cpr::Body{ request_body.dump() }
    );

    // После запроса:
    // 
    // Вывод ответа
    std::cout << "Status: " << response.status_code << std::endl;

    auto json_response = nlohmann::json::parse(response.text);

    // Безопасно достаём ответ ассистента
    if (json_response.contains("choices") && !json_response["choices"].empty()) {
        std::string reply = json_response["choices"][0]["message"]["content"];
        std::cout << "Response: " << reply << std::endl;
    }
    else {
        std::cout << "Fail: answer is empty or not contains 'choices'" << std::endl;
    }
}

void mistral_test() {
    cpr::Response r = cpr::Get(
        cpr::Url{ mistal_models_url },
        cpr::Header{ {"Authorization", "Bearer " + api_key} }
    );

    std::cout << "Status code: " << r.status_code << std::endl;
    std::cout << "Response: " << r.text << std::endl;
}

void cpr_requests_test() {
    cpr::Response r = cpr::Get(cpr::Url{ "https://api.github.com/repos/whoshuu/cpr/contributors" },
        cpr::Authentication{ "user", "pass", cpr::AuthMode::BASIC },
        cpr::Parameters{ {"anon", "true"}, {"key", "value"} });
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;

    json json_r = json::parse(r.text);

    for (auto x : json_r) {
        std::cout << x << std::endl;
    }
}

//#include "BalanceTree.h"


//void do_tree() {
//    make_tree();
//}

#include "BalancingTree/ActionsnNRules.h"

void actions_ruls_test() {
    std::unique_ptr<ActionsnNRules> actsNRuls = std::make_unique<ActionsnNRules>();

    std::cout
        << actsNRuls->GetActionIdByName("exploration") << " " << actsNRuls->GetActionNameById(0) << " "
        << actsNRuls->GetActionIdByName("conflict") << " " << actsNRuls->GetActionNameById(1) << " "
        << actsNRuls->GetActionIdByName("diplomacy") << " " << actsNRuls->GetActionNameById(2) << " "
        << actsNRuls->GetActionIdByName("aggression") << " " << actsNRuls->GetActionNameById(3) << " "
        << actsNRuls->GetActionIdByName("gumption") << " " << actsNRuls->GetActionNameById(4) << " "
        << actsNRuls->GetActionIdByName("stupidity") << " " << actsNRuls->GetActionNameById(5) << " "
        << actsNRuls->GetActionIdByName("active_action") << " " << actsNRuls->GetActionNameById(6) << " "
        << std::endl << std::endl;

    std::cout
        << actsNRuls->GetActionsToJson()
        << std::endl << std::endl;

    std::cout
        << actsNRuls->GetRulesAsWords()
        << std::endl << std::endl;

    for (auto n : actsNRuls->GetActionIds()) {
        std::cout << n << " ";
    }
    std::vector<int> path1{ 0, 1, 3, 2, 5 };
    std::vector<int> path2{ 3, 1, 3, 2, 3 };
    std::vector<int> path3{ 0, 1, 4, 6, 5 };
    std::vector<int> path4{ 2, 5, 3, 2, 5 };
    std::vector<int> path5{ 0, 2 };
    std::vector<int> path6{ 3, 3, 3 };
    std::vector<int> path7{ 1, 4, 6 };
    std::vector<int> path8{ 2, 5, 5 };
    std::vector<int> path9{ 6, 1, 2, 3, 4, 5, 6 };
    std::vector<int> path10{ 1 };
    std::cout << actsNRuls->CompareWithRules(path1) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path2) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path3) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path4) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path5) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path6) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path7) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path8) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path9) << std::endl;
    std::cout << actsNRuls->CompareWithRules(path10) << std::endl;
}

#include "BalancingTree/BalancingTree.h"

void balancing_tree_test() {
    BalancingTree* tree = new BalancingTree(7);
    std::string input;

    while (true) {
        std::string state = tree->GetJsonState();
        std::cout << state << "\n";

        if (tree->IsCurrentNodeLeaf()) {
            std::cout << "\nReached leaf node. Exiting.\n";
            break;
        }

        std::cout << "Enter action: ";
        std::cin >> input;

        tree->NavigateToAction(input);
    }

    delete tree;
}


#include "ProgramRequests/Request.h"
#include "ProgramRequests/RequestStrcutureSource.h"
#include "ProgramRequests/RequestStructureInput.h"

void input_request_data_test() {
    std::unique_ptr<RequestStructureSource> dataInput = std::make_unique<RequestStructureInput>();
    Request data = dataInput->GetData();

    std::cout
        << data.task
        << data.inputDescription
        << data.situation
        << data.endings
        << data.previousActions
        << data.actionsNames
        << data.currentState
        << data.currentAction
        << data.outputFormat;

}


#include "PreviousActions/PreviousActions.h"

void test_prev_actions() {
    std::unique_ptr<PreviousActions> prevActions = std::make_unique<PreviousActions>();

    std::cout << prevActions->GetPrevActions() << std::endl;

    for (int i = 0; i < 7; ++i) {
        nlohmann::json action;
        action["action"] = "aggressive";
        action["user_action"] = "text";
        action["incident"] = "text";

        prevActions->SetPrevAction(action.dump(4));
        std::cout << prevActions->GetPrevActions() << std::endl;
    }
}

#include "UserInteractive/UserInteractive.h"

void test_user_action() {
    std::unique_ptr<UserInteractive> userInteractive = std::make_unique<UserInteractive>("console");

    std::cout << userInteractive->GetUserAction() << std::endl;

    std::cout << userInteractive->GetUserAction() << std::endl;

    std::cout << userInteractive->GetUserAction() << std::endl;
}

#include "AIModel/AIModel.h"
#include "ProgramRequests/ProgramRequests.h"
#include "RequestProcessing/RequestProcessing.h"
#include "BalancingTree/BalancingTree.h"
#include "PreviousActions/PreviousActions.h"
#include "UserInteractive/UserInteractive.h"
#include "UserInteractive/OutputData.h"

void test_response() {
    std::unique_ptr<aim::AIModel> aiModel = std::make_unique<aim::AIModel>();
    std::unique_ptr<prog_req::ProgramRequests> currentRequest = std::make_unique<prog_req::ProgramRequests>();
    std::unique_ptr<req_proc::RequestProcessing> requestProcessing = std::make_unique<req_proc::RequestProcessing>();
    std::unique_ptr<PreviousActions> previousActions = std::make_unique<PreviousActions>();
    std::unique_ptr<UserInteractive> userInteractive = std::make_unique<UserInteractive>("console");
    std::unique_ptr<OutputData> outputData = std::make_unique<OutputData>();
    std::unique_ptr<BalancingTree> tree = std::make_unique<BalancingTree>(7);

    currentRequest->SetActionsNames(tree->GetActions());
    currentRequest->SetCurrentState(tree->GetJsonState());

    currentRequest->SetPreviousActions(previousActions->GetPrevActions());

    currentRequest->SetCurrentAction(userInteractive->GetUserAction());

    aiModel->SendRequest(currentRequest->GetRequest());

    std::cout << aiModel->GetResponse() << std::endl;

    std::cout << requestProcessing->ParseResponse(aiModel->GetResponse()) << std::endl;

    previousActions->SetPrevAction(requestProcessing->GetResponse());

    std::cout << previousActions->GetPrevActions() << std::endl;

    previousActions->SavePrevActions();

    outputData->PrintIncident(requestProcessing->GetIncident());

    std::cout << requestProcessing->GetAction() << std::endl;

    tree->NavigateToAction(requestProcessing->GetAction());

    std::cout << tree->GetJsonState() << std::endl;

}


void test_request() {
    std::unique_ptr<aim::AIModel> aiModel = std::make_unique<aim::AIModel>();
    std::unique_ptr<prog_req::ProgramRequests> currentRequest = std::make_unique<prog_req::ProgramRequests>();
    std::unique_ptr<PreviousActions> previousActions = std::make_unique<PreviousActions>();
    std::unique_ptr<UserInteractive> userInteractive = std::make_unique<UserInteractive>("console");
    std::unique_ptr<BalancingTree> tree = std::make_unique<BalancingTree>(7);

    currentRequest->SetActionsNames(tree->GetActions());
    currentRequest->SetCurrentState(tree->GetJsonState());

    currentRequest->SetPreviousActions(previousActions->GetPrevActions());

    currentRequest->SetCurrentAction(userInteractive->GetUserAction());


    std::cout << currentRequest->GetRequest() << std::endl;
}

void test_ai_model() {
    std::unique_ptr<aim::AIModel> aiModel = std::make_unique<aim::AIModel>();
    aiModel->SendRequest("Hi");

    aiModel->GetInfo();

}