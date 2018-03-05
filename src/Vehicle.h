#pragma once
#include "Order.h"

class Vehicle
{

public:
	Order::Lst orders;

	Vehicle();
	~Vehicle();

	bool add(Order *n);

    int distanceBetween(const Point &startPositionPoint, const Point &endPositionPoint) const;

	int getDistanceCost(const Order *n) const;

};

