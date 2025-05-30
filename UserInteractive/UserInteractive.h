#pragma once

#include <memory>
#include <iostream>

#include "InputData.h"


class UserInteractive
{
public:
	UserInteractive(std::string);
	~UserInteractive() = default;
	std::string GetUserAction();

private:
	std::unique_ptr<InputData> inputAction;
};
