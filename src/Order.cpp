#include "Order.h"

using namespace std;

Order::Order(int _no, const Point& _s, const Point& _e, int _earliest, int _latest)
	:no(_no), start(_s), end(_e), earliest(_earliest), latest(_latest)
{
}

Order::~Order()
= default;
