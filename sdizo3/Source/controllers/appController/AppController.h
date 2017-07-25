#pragma once
#include "controllers\genericController\GenericController.h"
#include "stdafx.h"

class AppController :
	public GenericController
{
	public:
		AppController();
		virtual ~AppController() = default;
		virtual void parseInput(const std::string &input);

	private:
		void runTests();
};

