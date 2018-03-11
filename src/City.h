#pragma once
#include "Vehicle.h"
#include <string>
#include <vector>

static const int BEST_VEHICLE_NOT_FOUND = -1;

static const int NO_POINT_EARNED = -1;

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

