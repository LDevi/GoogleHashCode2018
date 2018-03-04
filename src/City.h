#pragma once
#include "Vehicule.h"
#include <string>
class City
{
	std::string outputFilePath;

	int column, row;
	int tmax, bonus;
	Order::Lst orders;
	Vehicule::Lst fleet;

public:
	City(char *in, char *string);
	~City();

	void basic_simulation();

	void fleetStat();
};

