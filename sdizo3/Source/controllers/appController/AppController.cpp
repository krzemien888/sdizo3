#include "stdafx.h"
#include "AppController.h"
#include "controllers\genericController\GenericController.h"
#include "views\app\appMenu.h"

#include "controllers\backpackController\BackpackController.h"
#include "controllers\salesmanController\SalesmanController.h"

using namespace std;

AppController::AppController() : GenericController()
{
	setlocale(LC_ALL, "Polish");
	view = std::make_unique<appMenu>();
	srand((unsigned int)time(NULL));
}

void AppController::parseInput(const std::string &input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	std::unique_ptr<GenericController> controller = nullptr;

	switch (parsedInput) 
	{
		case 0:
			this->Stop();
			return;
			break;
		case 1:
			controller = std::make_unique<BackpackController>();
			break;
		case 2:
			controller = std::make_unique<SalesmanController>();
			break;
		case 3:
			controller.reset();
			runTests();
			break;
		default:
			throw new std::invalid_argument("Unknown controller input");
			break;
	}
	if(controller != nullptr)
		controller->Run();
}


void AppController::runTests()
{
	
}
