// sdizo3.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "controllers\appController\AppController.h"

int main()
{
	AppController app;

	try 
	{
		app.Run();
	}
	catch (...)
	{
		std::cout << "Unexpected error. Application shutdown." << std::endl;
	}

    return 0;
}
