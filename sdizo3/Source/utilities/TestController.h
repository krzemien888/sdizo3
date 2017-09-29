#pragma once
#include "stdafx.h"
#include "alghoritms\Item.h"

class TestController final
{
public:
	TestController() = default;
	~TestController() = default;

	void runAllTests();

	void runBackpackTests();
	void runBackpackBruteforce();
	void runBackpackDynamic();
	void runBackpackGreedy();
private:
	void saveToFile(int testSize, int time);
	void saveToFile(std::string testSize, int time);
	void setFileName(const std::string& fileName);

	const int maxItemWeight = 20;
	const int minItemWeight = 1;
	const int maxItemValue = 100;
	const int minItemValue = 1;
	std::vector<int> itemCount = {15, 30, 60, 75, 90};
	std::vector<float> backpackSizesMultipliers = { 7.5, 10, 12.5 };

	void generateBackpackInputData(const size_t itemCount, std::vector<int>& weights, std::vector<int>& values);

	std::string filename;
	std::ofstream file;
};

