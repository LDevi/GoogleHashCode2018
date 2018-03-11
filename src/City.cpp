#include "City.h"
#include <fstream>

using namespace std;

City::City(char *in, char *out)
{

	outputFilePath = out;

	ifstream ifs (in);
	string line;
	int nbOrders, nbVehicles, noOrder = 0;

	int xi, yi, xf, yf, e, l;

	ifs >> this->row >> this->column >> nbVehicles >> nbOrders >> this->bonus >> this->tMax;

	while (!ifs.eof() && noOrder < nbOrders ) {
		ifs >> xi >> yi >> xf >> yf >> e >> l;
		orders.push_back( new Order(noOrder++, Point(xi, yi), Point(xf, yf), e, l));
	}
	ifs.close();
    std::vector<Vehicle>  arr(static_cast<unsigned long>(nbVehicles), Vehicle());
    fleet  = arr;

}

City::~City()
{
	for (auto &order : orders)
        delete order;
}


void City::basic_simulation() {

	for (auto &order : orders) {
        int bestVehicleIndex = BEST_VEHICLE_NOT_FOUND;
        int greatestNumberOfPoints = NO_POINT_EARNED;
        for(int i = 0; i<fleet.size();i++){
            int pointForRide = fleet[i].getPointForRide(order);
            if( pointForRide > greatestNumberOfPoints){
                greatestNumberOfPoints = pointForRide;
                bestVehicleIndex = i;
            }
        }
        if(bestVehicleIndex != BEST_VEHICLE_NOT_FOUND) {
            fleet[bestVehicleIndex].add(order);
        }
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
