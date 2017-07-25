#pragma once
#include "controllers\genericController\GenericController.h"

class GenericProblemController :
	public GenericController
{
public:
	GenericProblemController() = default;
	virtual ~GenericProblemController() = default;

	void loadFromFile();

	virtual void parseFileHeader(std::string header) = 0;
	virtual void parseFileData(std::string line) = 0;
};

