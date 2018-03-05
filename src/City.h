#pragma once
#include "Vehicle.h"
#include <string>
#include <vector>

class City
{
	std::string outputFilePath;

	int column, row;
	int tMax, bonus;
	Order::Lst orders;
	std::vector<Vehicle>  fleet;

public:
	City(char *in, char *string);
	~City();

	void basic_simulation();

	void fleetStat();
};

