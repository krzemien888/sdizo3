#pragma once

#include "stdafx.h"

struct Item {
	int value;
	int weight;
};

class IBackpackAlghoritm
{
public:
	virtual void setParameters(int itemAmount) = 0;
	virtual void apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize) = 0;
	virtual std::vector<Item> getSolution() = 0;

	static void GenerateRandomData(std::vector<int> &weights, std::vector<int> &values, const int &itemCount)
	{
		for (int i = 0; i < itemCount; i++)
		{
			weights.push_back(rand() % 100 + 1);
			values.push_back(rand() % 100 + 1);
		}
	}
};

