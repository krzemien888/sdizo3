#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
#include "alghoritms\IBackpackAlghoritm.h"

class BackpackController final :
	public GenericProblemController
{
public:
	BackpackController();
	virtual ~BackpackController() = default;

	void parseInput(const std::string &input) override;
	void printDataState() override;

	void parseFileHeader(const std::string &header) override;
	void parseFileData(const std::string &line) override;

private:
	std::vector<int> weights;
	std::vector<int> values;
	int backpackSize = 0;
	int itemCount = 0;

	void applyAlghoritm(std::unique_ptr<IBackpackAlghoritm> &alghoritm);
	void generateRandomData();
};

