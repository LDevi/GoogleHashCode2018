#include "Vehicule.h"
#include <math.h>


Vehicule::Vehicule()
{
}


Vehicule::~Vehicule()
{
}

bool Vehicule::add(Order *n) {
	int tv=0, ts, tn=0;

	Point cur(0, 0);
	for (Order::Lst::iterator it = orders.begin(); it != orders.end(); it++) {
		// T pour rejoindre
		ts = abs((*it)->start.x - cur.x) + abs((*it)->start.y - cur.y);
		// attente
		tv += ((*it)->earliest > ts) ? (*it)->earliest : ts;
		// parcours
		tv += abs((*it)->end.x - (*it)->start.x) + abs((*it)->end.y - (*it)->start.y);

		cur.x = (*it)->end.x;
		cur.y = (*it)->end.y;
	}

	// T pour rejoindre
	ts = abs(n->start.x - cur.x) + abs(n->start.y - cur.y);
	// attente
	tv += (n->earliest > ts) ? n->earliest : ts;
	// parcours
	tv += abs(n->end.x - n->start.x) + abs(n->end.y - n->start.y);

	if(tv <= n->latest) {
		orders.push_back(n);
		return true;
	}

	return false;
}
