#pragma once
#include "alghoritms\IBackpackAlghoritm.h"

class BackpackDynamic final :
	public IBackpackAlghoritm
{
public:
	BackpackDynamic() = default;
	virtual ~BackpackDynamic() = default;

	void setParameters(int itemAmount) override;
	void apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize) override;
	void prepareSolutionMatrix(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize);
	std::vector<Item> getSolution() override;
	std::vector<std::vector<int>> getSolutionMatrix();

private:
	std::vector<Item> solution;
	std::vector<std::vector<int>> matrix;
};

