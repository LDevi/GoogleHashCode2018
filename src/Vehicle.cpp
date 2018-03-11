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

double Vehicle::getPointForRide(Order *&n) const {
    int totalTime=0;
    Point cur(0, 0);
    timeAndPosForScheduledOrders(totalTime, cur);

    Point processingOrderStartPoint = n->start;
    Point processingOrderEndPoint = n->end;
    totalTime += timeBetween(processingOrderStartPoint, cur);
    bool early = n->earliest > totalTime;
    totalTime = early ? n->earliest : totalTime;
    int timeForRide = timeBetween(processingOrderEndPoint, processingOrderStartPoint);
    totalTime += timeForRide;
    if(totalTime <= n->latest) {
        if(timeForRide == 0){
            return totalTime;
        }else {
            return totalTime/timeForRide;
        }

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