#include "stdafx.h"
#include "BackpackMenu.h"

using namespace std;

void BackpackMenu::print()
{
	int index = 1;
	cout << "----- Problem plecakowy -----" << endl;
	cout << index++ << " : Generuj dane losowo" << endl;
	cout << index++ << " : Wczytaj dane z pliku" << endl;
	cout << index++ << " : Przegl¹d zupe³ny" << endl;
	cout << index++ << " : Algorytm zach³anny" << endl;
	cout << index++ << " : Algorytm oparty na programowaniu dynamicznym" << endl;
	cout << "0: Wyjscie" << endl;
}
