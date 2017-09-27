#include "stdafx.h"
#include "Item.h"


bool Item::operator==(const Item& r)
{
	return value == r.value && weight == r.weight;
}

bool operator==(const Item& l, const Item& r)
{
	return l.value == r.value && l.weight == r.weight;
}

bool operator!=(const Item & l, const Item & r)
{
	return !(l == r);
}

::std::ostream& operator<<(::std::ostream& os, const Item& i) {
	return os << "Weight: " << i.weight << " Value: " << i.value;
}
