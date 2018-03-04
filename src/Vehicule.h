#pragma once
#include "Order.h"

class Vehicule
{

public:
	Order::Lst orders;
	typedef std::list<Vehicule *> Lst;

	Vehicule();
	~Vehicule();

	bool add(Order *);

};

