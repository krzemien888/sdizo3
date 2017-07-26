#pragma once
#include "alghoritms\IBackpackAlghoritm.h"


class BackpackBruteforce final :
	public IBackpackAlghoritm
{
public:
	BackpackBruteforce() = default;
	~BackpackBruteforce() = default;

	void setParameters(int itemAmount);
	void apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize) override;
	std::vector<Item> getSolution() override;

	std::vector<std::vector<int>> findAllSubsets(int size);
private:
	std::vector<Item> solution;
};

