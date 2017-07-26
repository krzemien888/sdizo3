#pragma once
#include "controllers\genericController\GenericController.h"

class GenericProblemController :
	public GenericController
{
public:
	GenericProblemController() = default;
	virtual ~GenericProblemController() = default;

	virtual void loadFromFile() final;

	virtual void parseFileHeader(const std::string &header) = 0;
	virtual void parseFileData(const std::string &line) = 0;

};

