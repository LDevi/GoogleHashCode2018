#pragma once
#include "Order.h"

class Vehicle
{

public:
	Order::Lst orders;

	Vehicle();
	~Vehicle();

	bool add(Order *n);

    int timeBetween(const Point &startPositionPoint, const Point &endPositionPoint) const;

	int getPointForRide(const Order *n) const;

    void timeAndPosForScheduledOrders(int &totalTime, Point &cur) const;
};

