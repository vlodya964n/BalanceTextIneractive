#include "ActionsNRulesInput.h"

#include <fstream>
#include <string>
#include <sstream>
#include <memory>

#include "../ModelCommunication/Config.h"


ActionsNRulesInput::ActionsNRulesInput() :
    actionsFilePath{"actions.txt"},
    rulesFilePath{"rules.txt"} {
    std::unique_ptr<Config> config = std::make_unique<Config>();

    std::string actNRulesPath = config->GetCurrentSettingsPath();
    actionsFilePath = actNRulesPath + actionsFilePath;
    rulesFilePath = actNRulesPath + rulesFilePath;

    InputActions();
    InputRules();
}

std::vector<Action> ActionsNRulesInput::GetActions() {
    return std::move(actions);
}

std::vector<Rule> ActionsNRulesInput::GetRules() {
    return std::move(actionsRules);
}

void ActionsNRulesInput::InputActions() {
    std::ifstream file(actionsFilePath);
    if (!file.is_open()) throw std::runtime_error("Cannot open actions file");

    std::string line;
    int id = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, description;

        if (std::getline(iss, name, ':')) {
            std::getline(iss, description);
            if (!description.empty() && description[0] == ' ')
                description = description.substr(1);

            actions.push_back({ id, name, description });
            ++id;
        }
    }

    file.close();
}

void ActionsNRulesInput::InputRules() {
    std::ifstream file(rulesFilePath);
    if (!file.is_open()) throw std::runtime_error("Cannot open rules file");

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Rule rule;
        std::string word;
        std::vector<std::string> tokens;

        while (iss >> word) {
            tokens.push_back(word);
        }

        if (tokens.size() < 2) continue;

        try {
            if (tokens.back() == "good") {
                rule.isGoodRule = true;
            }
            else if (tokens.back() == "bad") {
                rule.isGoodRule = false;
            }
            else {
                throw std::runtime_error("Invalid rule");
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
        
        // rule.isGoodRule = tokens.back() == "good" ? true : false;  // последний элемент — good или bad
        for (int i = 0; i < tokens.size() - 1; ++i) {
            try {
                rule.actionSequence.push_back(std::stoi(tokens[i]));
            }
            catch (...) {
                std::cerr << "Invalid action ID in rule: " << tokens[i] << "\n";
            }
        }

        if (!rule.actionSequence.empty()) {
            actionsRules.push_back(rule);
        }
    }

    file.close();
}


