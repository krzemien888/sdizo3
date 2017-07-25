#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
class BackpackController final :
	public GenericProblemController
{
public:
	BackpackController();
	virtual ~BackpackController() = default;

	void parseFileHeader(std::string header) override;
	void parseFileData(std::string line) override;
};

