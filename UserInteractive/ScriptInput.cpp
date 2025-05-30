#include "ScriptInput.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>

#include "../ModelCommunication/Config.h"

ScriptInput::ScriptInput() : filePath{ "ScriptActions.txt" } {

    std::unique_ptr<Config> config = std::make_unique<Config>();

    filePath = config->GetCurrentSettingsPath() + filePath;

    InputData();
}
std::string ScriptInput::GetAction() {
    std::string currentAction = "";
    if (!actions.empty()) {
        currentAction = actions.back();
        actions.pop_back(); 
    }
    else {
        currentAction = "I've finished";
    }

    std::cout << std::endl << currentAction << std::endl;

    return currentAction;
}

void ScriptInput::InputData() {
    std::ifstream file(filePath);
    std::string line;
    std::stringstream actionBuffer;
    if (!file.is_open()) {
        std::cerr << "Connot open Action Script File: " << filePath << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        if (line.empty()) {
            if (!actionBuffer.str().empty()) {
                actions.push_back(actionBuffer.str());
                actionBuffer.str(""); // очистить буфер
                actionBuffer.clear(); // сбросить флаги
            }
        }
        else {
            actionBuffer << line << "\n";
        }
    }

    // Добавить последний абзац, если он есть
    if (!actionBuffer.str().empty()) {
        actions.push_back(actionBuffer.str());
    }

    std::reverse(actions.begin(), actions.end());

    file.close();
}