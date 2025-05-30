#include "Config.h"

#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Config::Config() : filePath{"Config/config.json"} {
    InputData();
}

void Config::InputData() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open config.json\n";
        return;
    }

    json config;
    try {
        file >> config;
    }
    catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << '\n';
        return;
    }

    // —читываем параметры
    workType = config.value("job_type", "undefined");
    treeDepth = config.value("tree_depth", -1);
    interactiveType = config.value("interacive_type", "undefined");
    currentSettingsPath = config.value("current_settings_path", "undefined");
}

std::string Config::GetWorkType() {
    return workType;
}

int Config::GetTreeDepth() {
    return treeDepth;
}

std::string Config::GetInteractiveType() {
    return interactiveType;
}

std::string Config::GetCurrentSettingsPath() {
    return currentSettingsPath;
}