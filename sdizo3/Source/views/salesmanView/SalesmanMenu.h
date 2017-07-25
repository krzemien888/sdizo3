#pragma once
#include "views\genericView\GenericView.h"
class SalesmanMenu final :
	public GenericView
{
public:
	SalesmanMenu() = default;
	virtual ~SalesmanMenu() = default;

	void print();
};

