#include "stdafx.h"
#include "BackpackMenu.h"

using namespace std;

void BackpackMenu::print()
{
	int index = 1;
	cout << "----- Problem plecakowy -----" << endl;
	cout << i++ << " : Przegl�d zupe�ny" << endl;
	cout << i++ << " : Algorytm zach�anny" << endl;
	cout << i++ << " : Algorytm oparty na programowaniu dynamicznym" << endl;
	cout << "0: Wyjscie" << endl;
}
