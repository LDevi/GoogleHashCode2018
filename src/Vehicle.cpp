#include "Vehicle.h"
#include <complex>


Vehicle::Vehicle()
= default;


Vehicle::~Vehicle()
= default;

bool Vehicle::add(Order *n) {
        orders.push_back(n);
}

int Vehicle::getDistanceCost(const Order *n) const {
    int tv=0;

    Point cur(0, 0);
    for (auto &order : orders) {
        // T pour rejoindre
        Point &orderStartPoint = order->start;
        Point &orderEndPoint = order->end;
        tv += distanceBetween(cur, orderStartPoint);
        // attente
        tv = (order->earliest > tv) ? order->earliest : tv;
        // parcours
        tv += distanceBetween(orderEndPoint, orderStartPoint);
        cur.x = orderEndPoint.x;
        cur.y = orderEndPoint.y;
    }

    // T pour rejoindre
    Point processingOrderStartPoint = n->start;
    tv += distanceBetween(processingOrderStartPoint, cur);
    // attente
    tv = (n->earliest > tv) ? n->earliest : tv;
    // parcours
    Point processingOrderEndPoint = n->end;
    tv += distanceBetween(processingOrderEndPoint, processingOrderStartPoint);
    if(tv <= n->latest) {
        return tv;
    }
    return -1;
}

int Vehicle::distanceBetween(const Point &startPositionPoint, const Point &endPositionPoint) const {
    return abs(endPositionPoint.x - startPositionPoint.x) + abs(endPositionPoint.y - startPositionPoint.y);
}