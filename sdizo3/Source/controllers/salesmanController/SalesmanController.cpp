#include "stdafx.h"
#include "SalesmanController.h"

#include "views\salesmanView\SalesmanMenu.h"

SalesmanController::SalesmanController()
{
	this->view = std::make_unique<SalesmanMenu>();
}

void SalesmanController::parseFileHeader(std::string header)
{

}

void SalesmanController::parseFileData(std::string line)
{

}