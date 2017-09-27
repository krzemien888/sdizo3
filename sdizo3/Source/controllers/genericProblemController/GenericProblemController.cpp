#include "stdafx.h"
#include "GenericProblemController.h"

using namespace std;

void GenericProblemController::loadFromFile()
{
	string userInput = "";
	string line = "";

	cout << "Podaj nazwê pliku: ";
	cin >> userInput;

	ifstream fileStream(userInput);

	if (!fileStream.is_open())
	{
		cout << "Nie mo¿na otworzyæ pliku. \nAktywny folder:" << endl;
		system("cd");
		system("pause");
		return;
	}

	getline(fileStream, line);
	parseFileHeader(line);

	while (getline(fileStream, line))
	{
		if (!line.empty())
			parseFileData(line);
	}
}
