#include "stdafx.h"
#include "BackpackController.h"

#include "views\backpackView\BackpackMenu.h"

BackpackController::BackpackController()
{
	this->view = std::make_unique<BackpackMenu>();
}

void BackpackController::parseFileHeader(std::string header)
{
}

void BackpackController::parseFileData(std::string line)
{
}
