#include "stdafx.h"
#include "BackpackController.h"

#include "views\backpackView\BackpackMenu.h"
#include "alghoritms\IBackpackAlghoritm.h"
#include "alghoritms\BackpackBruteforce\BackpackBruteforce.h"
#include "alghoritms\BackpackGreedy\BackpackGreedy.h"

using namespace std;

BackpackController::BackpackController()
{
	this->view = std::make_unique<BackpackMenu>();
}

void BackpackController::parseInput(const std::string & input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	std::unique_ptr<GenericController> controller = nullptr;
	std::unique_ptr<IBackpackAlghoritm> alghoritm = nullptr;
	system("cls");

	switch (parsedInput)
	{
	case 0:
		this->Stop();
		return;
		break;
	case 1:
		weights.clear();
		values.clear();
		generateRandomData();
		break;
	case 2:
		weights.clear();
		values.clear();
		loadFromFile();
		break;
	case 3:
		alghoritm = make_unique<BackpackBruteforce>();
		applyAlghoritm(alghoritm);
		break;
	case 4:
		alghoritm = make_unique<BackpackGreedy>();
		applyAlghoritm(alghoritm);
		break;
	case 5:
		
		break;
	default:
		throw new std::invalid_argument("Unknown controller input");
		break;
	}
	if (controller != nullptr)
		controller->Run();
}

void BackpackController::printDataState()
{
	if (!weights.empty())
	{
		cout << "Wagi:\t\t";
		for (auto i : weights)
			cout << i << "\t";
		cout << endl << "Wartoœci:\t";
		for (auto i : values)
			cout << i << "\t";
		cout << endl;
	}
}

void BackpackController::parseFileHeader(const std::string &header)
{
	istringstream iss(header);
	
	iss >> this->backpackSize;
	iss >> this->itemCount;
}

void BackpackController::parseFileData(const std::string &line)
{
	istringstream iss(line);
	
	int weight = 0, value = 0;
	iss >> weight;
	iss >> value;

	values.push_back(value);
	weights.push_back(weight);
}

void BackpackController::applyAlghoritm(std::unique_ptr<IBackpackAlghoritm> &alghoritm)
{
	system("cls");
	alghoritm->apply(weights, values, backpackSize);
	auto output = alghoritm->getSolution();

	int sumWeight = 0, sumValue = 0;

	cout << "Waga\t\tWartoœæ" << endl;
	for (auto pair : output)
	{
		cout << pair.weight << "\t\t" << pair.value << endl;
		sumWeight += pair.weight;
		sumValue += pair.value;
	}
	cout << "£¹czna waga: " << sumWeight << endl;
	cout << "£¹czna wartoœæ: " << sumValue << endl;
	system("pause");
}

void BackpackController::generateRandomData()
{
	system("cls");
	backpackSize = rand() % 100 + 1;

	cout << "Iloœæ przedmiotów: ";
	cin >> itemCount;

	cout << endl;

	cout << "Wielkoœæ plecaka: ";
	cin >> backpackSize;

	IBackpackAlghoritm::GenerateRandomData(weights, values, itemCount);
}
