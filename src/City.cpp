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

	ifs >> this->row >> this->column >> nbVehicules >> nbOrders >> this->bonus >> this->tmax;

	while (!ifs.eof() && noOrder < nbOrders ) {
		ifs >> xi >> yi >> xf >> yf >> e >> l;
		orders.push_back( new Order(noOrder++, Point(xi, yi), Point(xf, yf), e, l));
	}
	ifs.close();
    std::vector<Vehicle>  arr(static_cast<unsigned long>(nbVehicules), Vehicle());
    fleet  = arr;

}

City::~City()
{
	for (auto &order : orders)
        delete order;
}


void City::basic_simulation() {

	for (auto &order : orders) {
        int cheaper_vehicle = -1;
        int cheaper_cost = -1;
        for(int i = 0; i<fleet.size();i++){
            int currentCostForVehicle =  fleet[i].getDistanceCost( order);
            if( cheaper_cost == -1 || currentCostForVehicle < cheaper_cost){
                cheaper_cost =currentCostForVehicle;
                cheaper_vehicle = i;
            }
        }
        fleet[cheaper_vehicle].add(order);
	}
}


void City::fleetStat() {
	std::ofstream ofs(outputFilePath);
for(auto &vehicle : fleet){
    ofs << vehicle.orders.size() << " ";
    for (auto &order : vehicle.orders)
        ofs << order->no << " ";
    ofs << "\n";
}

}
