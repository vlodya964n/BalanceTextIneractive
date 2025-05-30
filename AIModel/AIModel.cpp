#include "AIModel.h"

using json = nlohmann::json;

static std::string api_key = "BOGnY8rz1uSJTHgtjAOv0j4KpcyM2Cqr";
static std::string mistal_models_url = "https://api.mistral.ai/v1/models";
static std::string mistal_chat_url = "https://api.mistral.ai/v1/chat/completions";

namespace aim {
    AIModel::AIModel() : modelType{ "mistral-small-latest" } {}

    nlohmann::json AIModel::GenerateRequestBody(std::string requestText) {

        // Формируем JSON-запрос
        nlohmann::json request_body = {
            {"model", modelType},
            {"messages", {
                {{"role", "user"}, {"content", requestText}}
            }}
        };
        return request_body;
    }

    void AIModel::SendRequest(std::string requestText) {

        // Формируем JSON-запрос
        nlohmann::json request_body = {
            {"model", modelType},
            {"messages", {
                {{"role", "user"}, {"content", requestText}}
            }}
        };

        // Отправка POST-запроса
        cpr::Response Response = cpr::Post(
            cpr::Url{ mistal_chat_url },
            cpr::Header{
                {"Authorization", "Bearer " + api_key},
                {"Content-Type", "application/json"}
            },
            cpr::Body{ request_body.dump(4) }
        );
        statusCode = Response.status_code;

        nlohmann::json jsonResponse = nlohmann::json::parse(Response.text);

        currentResponse = jsonResponse["choices"][0]["message"]["content"];
    }

    void AIModel::GetInfo() {
        std::cout << "Status Code: " << statusCode << std::endl;
        std::cout << "Message: " << currentResponse << std::endl;
    }

    std::string AIModel::GetResponse() {
        return currentResponse;
    }
}
