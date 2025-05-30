#pragma once

#include <iostream>

#include "Request.h"

class RequestStructureSource {
public:
	virtual ~RequestStructureSource() = default;
	virtual Request GetData() = 0;
};