# CMakeList.txt: проект CMake для CMakeProject2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeProject2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeProject2 
"CMakeProject2.cpp" 
"CMakeProject2.h" 
"ModelCommunication/ModelCommunication.h" 
"ModelCommunication/ModelCommunication.cpp"
"ModelCommunication/Config.h" 
"ModelCommunication/Config.cpp"

 "ProgramRequests/ProgramRequests.h" 
 "ProgramRequests/ProgramRequests.cpp" 
 "ProgramRequests/RequestStrcutureSource.h" 
 "ProgramRequests/RequestStructureInput.h" 
 "ProgramRequests/RequestStructureInput.cpp" 
 "ProgramRequests/Request.h"

 "AIModel/AIModel.h" 
 "AIModel/AIModel.cpp" 

 "RequestProcessing/RequestProcessing.h" 
 "RequestProcessing/RequestProcessing.cpp" 
  
  
  
 "BalancingTree/BalancingTree.h" 
 "BalancingTree/BalancingTree.cpp" 
 "BalancingTree/ActionsnNRules.h" 
 "BalancingTree/ActionsnNRules.cpp" 
 "BalancingTree/ActionsNRulesSource.h" 
 "BalancingTree/ActionsNRulesSource.cpp" 
 "BalancingTree/ActionsNRulesInput.h" 
 "BalancingTree/ActionsNRulesInput.cpp" 
 "BalancingTree/Action.h" 
 "BalancingTree/Rule.h" 
 
 "PreviousActions/PreviousActions.h" 
 "PreviousActions/PreviousActions.cpp"

 "UserInteractive/UserInteractive.h" 
 "UserInteractive/UserInteractive.cpp"
 "UserInteractive/OutputData.h" 
 "UserInteractive/OutputData.cpp"
 "UserInteractive/InputData.h" 
 "UserInteractive/ConsoleInput.h" 
 "UserInteractive/ConsoleInput.cpp" 
 "UserInteractive/ScriptInput.h" 
 "UserInteractive/ScriptInput.cpp" 
 
  "Test.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
find_package(cpr CONFIG REQUIRED)
target_link_libraries(CMakeProject2 PRIVATE cpr::cpr)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(CMakeProject2 PRIVATE nlohmann_json::nlohmann_json)
