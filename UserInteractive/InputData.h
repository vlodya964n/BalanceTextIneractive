#pragma once

#include<iostream>

class InputData
{
public:
	virtual ~InputData() = default;
	virtual std::string GetAction() = 0;
};
