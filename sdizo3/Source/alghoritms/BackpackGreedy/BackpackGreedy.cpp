#include "stdafx.h"
#include "BackpackGreedy.h"

void BackpackGreedy::setParameters(int itemAmount)
{
	solution.reserve(itemAmount);
}

void BackpackGreedy::apply(const std::vector<int>& weights, const std::vector<int>& values, const int backpackSize)
{
	solution.clear();
	
	auto comp = [](Item a, Item b) {return ((float)a.value / (float)a.weight) < ((float)b.value / (float)b.weight); };
	std::priority_queue<Item, std::vector<Item>, decltype(comp)> queue(comp);
	
	for (unsigned int i = 0; i < weights.size(); i++)
	{
		Item item = { values[i], weights[i] };
		queue.push(item);
	}

	int currWeight = 0;
	while (!queue.empty())
	{
		auto item = queue.top();
		queue.pop();
		if (currWeight + item.weight <= backpackSize)
		{
			solution.push_back(item);
			currWeight += item.weight;
			if (currWeight == backpackSize)
				break;
		}
	}
}

std::vector<Item> BackpackGreedy::getSolution()
{
	return solution;
}
