#include "stdafx.h"
#include "BackpackBruteforce.h"

void BackpackBruteforce::setParameters(int itemAmount)
{
	solution.reserve(itemAmount);
}

void BackpackBruteforce::apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize)
{
	int bestValue = 0;
	solution.clear();
	auto subSets = findAllSubsets(weights.size()-1);

	for(auto set : subSets)
	{
		int currValue = 0, currWeight = 0;
		for (auto index : set)
		{
			currWeight += weights[index];
			currValue += values[index];
		}

		if (bestValue < currValue && currWeight <= backpackSize)
		{
			solution.clear();
			bestValue = currValue;
			for(auto index : set)
			{
				Item i = { values[index], weights[index] };
				solution.push_back(i);
			}
		}
	}
	
}

std::vector<Item> BackpackBruteforce::getSolution()
{
	return solution;
}

std::vector<std::vector<int>> BackpackBruteforce::findAllSubsets(int size)
{
	std::vector<std::vector<int>> output;

	for (int i = 0; i <= size; i++)
	{
		if (i == 0)
		{
			output.push_back(std::vector<int>());
			output.push_back(std::vector<int>(1, 0));
		}
		else
		{
			output.insert(output.end(), output.begin(), output.end());
			for (unsigned int j = 0; j < output.size() / 2; j++)
				output[j].push_back(i);
		}
	}

	return output;
}
