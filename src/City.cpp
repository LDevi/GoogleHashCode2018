#include "City.h"
#include <fstream>

using namespace std;

City::City(char *in, char *out)
{
	outputFilePath = out;

	ifstream ifs (in);
	string line;
	int nbOrders, nbVehicules, noOrder = 0;

	int xi, yi, xf, yf, e, l;

//	getline(ifs, line);
	ifs >> this->row >> this->column >> nbVehicules >> nbOrders >> this->bonus >> this->tmax;

	while (!ifs.eof() && noOrder < nbOrders ) {
		ifs >> xi >> yi >> xf >> yf >> e >> l;
		orders.push_back( new Order(noOrder++, Point(xi, yi), Point(xf, yf), e, l));
	}
	ifs.close();

	for (int i = 0; i < nbVehicules; i++)
		fleet.push_back(new Vehicule());
}

City::~City()
{
	for (Order::Lst::iterator it = orders.begin(); it != orders.end(); it++)
		delete *it;
}


void City::basic_simulation() {

	for (Order::Lst::iterator it = orders.begin(); it != orders.end(); it++) {
		for (Vehicule::Lst::iterator itf = fleet.begin(); itf != fleet.end(); itf++) {
			if ((*itf)->add(*it))
				break;
		}
	}
}


void City::fleetStat() {
	std::ofstream ofs(outputFilePath);

	for (Vehicule::Lst::iterator it = fleet.begin(); it != fleet.end(); it++) {
		ofs << (*it)->orders.size() << " ";

		for (Order::Lst::iterator ito = (*it)->orders.begin(); ito != (*it)->orders.end(); ito++)
			ofs << (*ito)->no << " ";

		ofs << "\n";
	}

}
