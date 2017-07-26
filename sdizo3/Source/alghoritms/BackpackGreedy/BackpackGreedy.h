#pragma once
#include "alghoritms\IBackpackAlghoritm.h"
#include "stdafx.h"

class BackpackGreedy :
	public IBackpackAlghoritm
{
public:
	BackpackGreedy() = default;
	virtual ~BackpackGreedy() = default;

	virtual void setParameters(int itemAmount);
	virtual void apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize);
	virtual std::vector<Item> getSolution();

private:
	std::vector<Item> solution;
};

