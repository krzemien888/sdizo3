// sdizo3.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "controllers\appController\AppController.h"


#include "alghoritms\BackpackBruteforce\BackpackBruteforce.h"

int main()
{
	AppController app;

	try 
	{
		app.Run();
	}
	catch (std::bad_alloc &e)
	{
		std::cout << "Out of memory. Application shutdown." << std::endl;
		system("pause");
	}
	catch (...)
	{
		std::cout << "Unexpected error. Application shutdown." << std::endl;
		system("pause");
	}


    return 0;
}
