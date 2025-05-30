#include "ConsoleInput.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string ConsoleInput::GetAction() {
    std::string line;
    std::stringstream buffer;

    std::cout << "Do action:\n";

    while (std::getline(std::cin, line)) {
        if (line.empty()) break; 
        buffer << line << '\n';
    }

    std::string fullText = buffer.str();
	return fullText;
}