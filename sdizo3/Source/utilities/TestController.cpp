#include "stdafx.h"
#include "TestController.h"

#include "alghoritms\BackpackBruteforce\BackpackBruteforce.h"
#include "alghoritms\BackpackDynamic\BackpackDynamic.h"
#include "alghoritms\BackpackGreedy\BackpackGreedy.h"

using namespace std;

void TestController::runAllTests()
{
	runBackpackTests();
}

void TestController::runBackpackTests()
{
	cout << "Knapsnack problem alghoritm tests started" << endl;
	runBackpackGreedy();
	runBackpackDynamic();
	runBackpackBruteforce();
	cout << "Knapsnack problem alghoritm tests ended" << endl;
}

void TestController::runBackpackBruteforce()
{
	cout << "Backpack tests - Bruteforce: Preparing" << endl;

	BackpackBruteforce algh;
	auto currentItemCount = itemCount.begin();
	vector<int> values;
	vector<int> weights;
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;

	auto currentSizeMultiplier = backpackSizesMultipliers.begin();
	while (currentSizeMultiplier != backpackSizesMultipliers.end())
	{
		stringstream ss;
		ss << "BackpackBruteforce-multiplayer-" << *currentSizeMultiplier << ".csv";
		setFileName(ss.str());
		ss.str("");

		while (currentItemCount != itemCount.end())
		{
			int backpackSize = (int)(*currentSizeMultiplier) * (*currentItemCount);
			generateBackpackInputData(*currentItemCount, weights, values);
			cout << "Backpack tests - Bruteforce: Testing with " << *currentItemCount << " items and " << backpackSize << " places in backpack " << endl;
			for (int x = 0; x < 10; x++)
			{
				cout << "\rProgress: " << x + 1 << "%";

				startTime = chrono::high_resolution_clock::now();
				algh.apply(weights, values, backpackSize);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
			}
			cout << endl;
			ss << *currentItemCount;
			saveToFile(ss.str(), totalTime / 100);
			ss.str("");
			currentItemCount++;
		}
		currentSizeMultiplier++;
	}
}

void TestController::runBackpackDynamic()
{
}

void TestController::runBackpackGreedy()
{
}

void TestController::saveToFile(int testSize, int time)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
	{
		try {
			file << testSize << "," << time << endl;
		}
		catch (...)
		{
			cout << "Gotcha!" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}

void TestController::saveToFile(string testSize, int time)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
	{
		try {
			file << testSize << "," << time << endl;
		}
		catch (...)
		{
			cout << "Gotcha!" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}

void TestController::setFileName(const std::string& fileName)
{
	filename = fileName;
	file.open(filename, std::ios::out | std::ios::trunc);

	if (file.good())
		file << "size,time"<< endl;
	else
	{
		cout << "Error occured while opening the file!" << endl;
		system("pause");
	}
	file.close();
}

void TestController::generateBackpackInputData(const size_t itemCount, std::vector<int>& weights, std::vector<int>& values)
{
	weights.clear();
	values.clear();
	while (values.size() != itemCount)
	{
		weights.push_back(minItemWeight + (rand() % maxItemWeight));
		values.push_back(minItemValue + (rand() % maxItemValue));
	}
}
