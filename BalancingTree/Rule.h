#pragma once

#include <vector>

struct Rule {
    std::vector<int> actionSequence;
    bool isGoodRule{0}; // "good" или "bad"
};