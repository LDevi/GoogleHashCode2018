#pragma once
#include "Order.h"

class Vehicle
{

public:
	Order::Lst orders;
	typedef std::list<Vehicle *> Lst;

	Vehicle();
	~Vehicle();

	bool add(Order *);

    int distanceBetween(const Point &startPositionPoint, const Point &endPositionPoint) const;

	int getDistanceCost(const Order *n) const;
};

