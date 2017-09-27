#pragma once
#include "alghoritms\IBackpackAlghoritm.h"
#include "stdafx.h"

class BackpackGreedy final :
	public IBackpackAlghoritm
{
public:
	BackpackGreedy() = default;
	virtual ~BackpackGreedy() = default;

	virtual void setParameters(int itemAmount) override;
	virtual void apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize) override;
	virtual std::vector<Item> getSolution() override;

private:
	std::vector<Item> solution;
};

