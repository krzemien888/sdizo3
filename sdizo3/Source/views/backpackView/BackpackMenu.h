#pragma once
#include "views\genericView\GenericView.h"
class BackpackMenu final :
	public GenericView
{
public:
	BackpackMenu() = default;
	virtual ~BackpackMenu() = default;

	void print();
};

