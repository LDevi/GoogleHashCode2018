#include "Vehicle.h"
#include "City.h"
#include <complex>


Vehicle::Vehicle()
= default;


Vehicle::~Vehicle()
= default;

bool Vehicle::add(Order *n) {
        orders.push_back(n);
}

int Vehicle::getPointForRide(const Order *n) const {
    int totalTime=0;
    Point cur(0, 0);
    timeAndPosForScheduledOrders(totalTime, cur);

    Point processingOrderStartPoint = n->start;
    Point processingOrderEndPoint = n->end;
    totalTime += timeBetween(processingOrderStartPoint, cur);
    totalTime = (n->earliest > totalTime) ? n->earliest : totalTime;
    int timeForRide = timeBetween(processingOrderEndPoint, processingOrderStartPoint);
    totalTime += timeForRide;
    if(totalTime <= n->latest) {
        return timeForRide;
    }
    return NO_POINT_EARNED;
}

void Vehicle::timeAndPosForScheduledOrders(int &totalTime, Point &cur) const {
    for (auto &order : orders) {
        Point &orderStartPoint = order->start;
        Point &orderEndPoint = order->end;
        totalTime += timeBetween(cur, orderStartPoint);
        totalTime = (order->earliest > totalTime) ? order->earliest : totalTime;
        totalTime += timeBetween(orderEndPoint, orderStartPoint);
        cur.x = orderEndPoint.x;
        cur.y = orderEndPoint.y;
    }
}

int Vehicle::timeBetween(const Point &startPositionPoint, const Point &endPositionPoint) const {
    return abs(endPositionPoint.x - startPositionPoint.x) + abs(endPositionPoint.y - startPositionPoint.y);
}