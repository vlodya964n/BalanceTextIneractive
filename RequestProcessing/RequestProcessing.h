#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace req_proc {
	class RequestProcessing
	{
	public:
		RequestProcessing() = default;
		~RequestProcessing() = default;
		bool ParseResponse(const std::string& jsonStr);

		std::string GetResponse() const;

		std::string GetIncident() const;

		std::string GetAction() const;
	private:
		nlohmann::json parsedJson;
		bool isValid = false;
	};
}

