#include "stdafx.h"
#include "controllers\appController\AppController.h"


int main()
{
	AppController app;

	try
	{
		app.Run();
	}
	catch (std::bad_alloc)
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
