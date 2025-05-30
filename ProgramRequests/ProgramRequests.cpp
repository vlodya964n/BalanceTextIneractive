#include "ProgramRequests.h"

#include <memory>
#include <sstream>

#include "RequestStrcutureSource.h"
#include "RequestStructureInput.h"

namespace prog_req {
    ProgramRequests::ProgramRequests() {
        std::unique_ptr<RequestStructureSource> dataInput = std::make_unique<RequestStructureInput>();
        beginingRequestElements = dataInput->GetData();
    }

    void ProgramRequests::SetPreviousActions(std::string previousActions_) {
        changingRequestElements.previousActions = previousActions_;
    }

    void ProgramRequests::SetActionsNames(std::string actionsNames_) {
        changingRequestElements.actionsNames = actionsNames_;
    }

    void ProgramRequests::SetCurrentState(std::string currentState_) {
        changingRequestElements.currentState = currentState_;
    }

    void ProgramRequests::SetCurrentAction(std::string currentAction_) {
        changingRequestElements.currentAction = currentAction_;
    }

    std::string ProgramRequests::GetRequest() {
        std::ostringstream oss;
        oss 
            << beginingRequestElements.task
            << beginingRequestElements.inputDescription
            << beginingRequestElements.situation
            << beginingRequestElements.endings
            << beginingRequestElements.previousActions
            << "```\n" << changingRequestElements.previousActions << "```\n"
            << beginingRequestElements.actionsNames
            << "```\n" << changingRequestElements.actionsNames << "```\n"
            << beginingRequestElements.currentState
            << "```\n" << changingRequestElements.currentState << "```\n"
            << beginingRequestElements.currentAction
            << "```\n" << changingRequestElements.currentAction << "```\n"
            << beginingRequestElements.outputFormat;
        return oss.str();
    }
}
