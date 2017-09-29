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

	std::vector<Item> bestSolution;
	if (weights.size() > 63)
		throw std::invalid_argument("Amount of subsets exceeds variable range (over 63)");

	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;
	int currentTime = 0;

	startTime = std::chrono::high_resolution_clock::now();
	for (unsigned long long currSubset = 1; currSubset < pow(2, weights.size()); currSubset++)
	{

		int currValue = 0, currWeight = 0;
		unsigned long long currItem = 1;
		std::vector<Item> currSolution;

		while (currItem <= currSubset && currWeight <= backpackSize)
		{
			if (((currItem & currSubset) != 0))
			{
				int currIndex = (int)log2(currItem);
				if(((weights[currIndex] + currWeight) <= backpackSize))
				{
					Item i = { values[currIndex], weights[currIndex] };
					currValue += values[currIndex];
					currWeight += weights[currIndex];
					currSolution.push_back(i);
				}
				else
				{
					break;
				}
			}
			currItem *= 2;
		}

		if (currValue > bestValue)
		{
			bestValue = currValue;
			bestSolution = currSolution;
		}

		endTime = std::chrono::high_resolution_clock::now();
		currentTime = (int)std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime).count();
		if (currentTime > 60)
			throw std::length_error("Execution time exceeds 1 hour");
	}

	solution = bestSolution;
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
