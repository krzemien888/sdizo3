#pragma once
#include "stdafx.h"

class Item {
public:
	Item() = default;
	~Item() = default;
	int value;
	int weight;
	bool operator==(const Item& r);
	friend bool operator==(const Item& l, const Item& r);
	friend bool operator!=(const Item& l, const Item& r);
	friend ::std::ostream& operator<<(::std::ostream& os, const Item& i);
};


