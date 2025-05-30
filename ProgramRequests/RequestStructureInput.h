#pragma once

#include <iostream>
#include <vector>

#include "RequestStrcutureSource.h"
#include "Request.h"


class RequestStructureInput : public RequestStructureSource
{
public:
	RequestStructureInput();
	~RequestStructureInput() = default;
	Request GetData() override;
private:
	void InputData();
	Request dataStructure;
	std::string filePath;
	std::vector<std::string> structureFilePaths;
};
