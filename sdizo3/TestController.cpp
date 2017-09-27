#include "stdafx.h"
#include "TestController.h"

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
			file << testSize << ";" << time << endl;
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

void TestController::saveToFile(std::string message)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
		file << message << endl;
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}
