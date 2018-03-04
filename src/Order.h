#pragma once

#include "Point.h"
#include <list>

class Order
{

public:
	int no;
	Point start, end;
	int earliest, latest;

	typedef std::list<Order *> Lst;

	Order(int,const Point&, const Point&, int, int);
	~Order();
};

