#include "stdafx.h"
#include "BackpackDynamic.h"

void BackpackDynamic::setParameters(int itemAmount)
{
	solution.reserve(itemAmount);
}

std::vector<Item> BackpackDynamic::getSolution()
{
	return solution;
}

void BackpackDynamic::prepareSolutionMatrix(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize)
{
	while (matrix.size() != weights.size() + 1)
		matrix.push_back(std::vector<int>(backpackSize + 1, 0));
	
	const size_t itemAmount = weights.size();
	
	for (int x = 0; x <= (int)itemAmount; x++)
	{
		for (int y = 0; y <= backpackSize; y++)
		{
			if (y == 0 || x == 0)
			{
				matrix[x][y] = 0;
				continue;
			}
			if (y - weights[x - 1] >= 0)
			{
				matrix[x][y] = max(matrix[x - 1][y], matrix[x - 1][y - weights[x - 1]] + values[x - 1]);
			}
			else
			{
				matrix[x][y] = matrix[x - 1][y];
			}
		}
	}
}

void BackpackDynamic::apply(const std::vector<int> &weights, const std::vector<int> &values, const int backpackSize)
{
	solution.clear();
	matrix.clear();

	prepareSolutionMatrix(weights, values, backpackSize);


	int x = (int)matrix.size() - 1;
	int y = backpackSize;
	while (x != 0 && y != 0)
	{
		if (matrix[x][y] != matrix[x - 1][y])
		{
			Item i;
			i.value = values[x-1];
			i.weight = weights[x-1];
			solution.push_back(i);
			y -= weights[x-1];
			x--;
			continue;
		}
		else
		{
			x--;
			continue;
		}
	}
}

std::vector<std::vector<int>> BackpackDynamic::getSolutionMatrix()
{
	return matrix;
}