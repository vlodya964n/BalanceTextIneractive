#include "RequestStructureInput.h"

#include <fstream>
#include <string>

RequestStructureInput::RequestStructureInput() : 
	filePath{"RequestStructure/StructureElementPaths.txt"} {
	InputData();
}

Request RequestStructureInput::GetData() {
    return dataStructure;
}

void RequestStructureInput::InputData() {
    
    std::ifstream file(filePath);
    if (!file.is_open()) throw std::runtime_error("Cannot open structure element paths file");

    std::string line;
    while (std::getline(file, line)) {
        structureFilePaths.push_back(line);
    }

    file.close();

    std::vector<std::string> structureElements;
    for (auto path : structureFilePaths) {
        file.open(path);
        if (!file.is_open()) throw std::runtime_error("Cannot open structure element file");

        std::string element ="";
        while (std::getline(file, line)) {
            element += line + "\n";
        }
        file.close();
        structureElements.push_back(element);
    }


    try {
        dataStructure.task = structureElements[0];
        dataStructure.inputDescription = structureElements[1];
        dataStructure.situation = structureElements[2];
        dataStructure.endings = structureElements[3];
        dataStructure.previousActions = structureElements[4];
        dataStructure.actionsNames = structureElements[5];
        dataStructure.currentState = structureElements[6];
        dataStructure.currentAction = structureElements[7];
        dataStructure.outputFormat = structureElements[8];
    }
    catch (...) {
        std::cerr << "Cannot input structure elements";
    }
}
