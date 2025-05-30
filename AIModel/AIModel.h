#pragma once

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
namespace aim {

	class AIModel
	{
	private:
		std::string modelType;
		std::string currentResponse;
		std::string statusCode;
		nlohmann::json GenerateRequestBody(std::string);
	public:
		AIModel();
		void SendRequest(std::string);
		std::string GetResponse();
		void GetInfo();
	};
}

