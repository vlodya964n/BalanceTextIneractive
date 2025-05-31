

## cmake project
----
#### [install vcpkg (package manager)](https://github.com/microsoft/vcpkg#)

* Run "*.bat" in the vcpkg folder

* Run "vcpkg intergate install" in the vcpkg folder

* Add to CmakeSettings TOOLCHAIN path to vcpkg.cmake
----
#### Add dependencies
* Run: "vcpkg "@.\vcpkg_rf.txt"" in the project folder

* Add to CmakeList:
	find_package
	target_link_libraries
----
----
## Task Description
* Make the program for interactive communication with AI model
* A description of the results that are currently ready can be found in the Description folder.

#### The Beginning
* The program sets a task description for the model. 

#### The User's activity
* The user conducts a dialogue with the model as part of this task.

#### The Model's answers
* The model provides a structured response with options for possible events as a response.

## The Program Modules

* AIModel - he module that sends requests to the AI model
* BalancingTree - The module is responsible for building the balancing tree.
  	* ActionsnNRules - actions and rules for actions that are set by the user and according to which the balancing tree is built
	* ActionsNRulesSource, ActionsNRulesInput - They are responsible for entering actions and rules that the user has set
   	* BalancingTree - all work with the balancing tree, building, calculating the balance, a one-time pass through the tree
* ProgramRequests - generates queries for the model at each step of the narrative (with each user action)
  	* Request - request structure
  	* RequestStrcutureSource, RequestStructureInput - entering a request
  	* ProgramRequests - complete preparation and issuance of a ready-made request
* RequestProcessing - the module for processing incoming requests from ai model
* PreviousActions - saves the history of the conversation between the neural network and the user (past narration steps)
* UserInteractive - program interaction with the user
  	* InputData, ConsoleInput, ScriptInput - methods of conducting a dialogue with the user, through the console and through the script - preset responses.
  	* OutputData - output of neural network responses to the console.
  	* UserInteractive - complete organization of interaction.
* ModelCommunication - the main module, with the interaction of query modules and ai module

