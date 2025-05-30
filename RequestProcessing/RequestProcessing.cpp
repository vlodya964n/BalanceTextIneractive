#include "RequestProcessing.h"

#include <iostream>

namespace req_proc {
    bool RequestProcessing::ParseResponse(const std::string& jsonStr) {
        try {
            std::string str = jsonStr;
            // Удаление префикса
            std::string prefix = "```json";
            if (str.compare(0, prefix.size(), prefix) == 0) {
                str.erase(0, prefix.size());
            }

            // Удаление суффикса
            std::string suffix = "```";
            size_t pos = str.rfind(suffix);
            if (pos != std::string::npos && pos == str.size() - suffix.size()) {
                str.erase(pos, suffix.size());
            }

            // Также можно убрать начальные/конечные переводы строки или пробелы
            while (!str.empty() && (str.front() == '\n' || str.front() == ' '))
                str.erase(str.begin());
            while (!str.empty() && (str.back() == '\n' || str.back() == ' '))
                str.pop_back();


            parsedJson = nlohmann::json::parse(str);

            // Проверка на наличие всех нужных полей
            if (parsedJson.contains("action") &&
                parsedJson.contains("user_action") &&
                parsedJson.contains("incident") &&
                parsedJson["action"].is_string() &&
                parsedJson["user_action"].is_string() &&
                parsedJson["incident"].is_string()) {
                isValid = true;
            }
            else {
                isValid = false;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "json parsing fail: " << e.what() << std::endl;
            isValid = false;
        }

        return isValid;
    }

    std::string RequestProcessing::GetResponse() const {
        if (isValid)
            return parsedJson.dump(4); 
        else
            return "{}";
    }

    std::string RequestProcessing::GetIncident() const {
        if (isValid)
            return parsedJson["incident"].get<std::string>();
        else
            return "";
    }

    std::string RequestProcessing::GetAction() const {
        if (isValid)
            return parsedJson["action"].get<std::string>();
        else
            return "";
    }
}
