

## cmake project
----
#### [install vcpkg (package manager)](https://github.com/microsoft/vcpkg#)

* Run "*.bat" in the vcpkg folder

* Run "vcpkg intergate" in the vcpkg folder

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

#### The Beginning
* The program sets a task description for the model. 

#### The User's activity
* The user conducts a dialogue with the model as part of this task.

#### The Model's answers
* The model provides a structured response with options for possible events as a response.

## The Program Modules

* ModelCommunication - the main module, with the interaction of query modules and ai module
* RequestProcessing - the module for processing incoming requests from ai model
* ProgramRequests - the initial task request for the model
* UserRequests - requests from the user to interact with the model
* AIModel - he module that sends requests to the AI model

