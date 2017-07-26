#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
class SalesmanController :
	public GenericProblemController
{
public:
	SalesmanController();
	virtual ~SalesmanController() = default;

	void parseFileHeader(const std::string &header) override;
	void parseFileData(const std::string &line) override;
};

