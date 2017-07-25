#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
class SalesmanController :
	public GenericProblemController
{
public:
	SalesmanController();
	virtual ~SalesmanController() = default;

	void parseFileHeader(std::string header) override;
	void parseFileData(std::string line) override;
};

