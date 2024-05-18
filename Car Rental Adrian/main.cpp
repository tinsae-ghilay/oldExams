#include <iostream>
#include "carrental.h"
#include "car.h"
#include "exceptions.h"

int main() {
    CarRental carRental;
    VWBus vwBus;
    FordFocus fordFocus; 
    FerrariF40 ferrariF40;
    Kleinbus kleinbus;
    carRental.addCar(&ferrariF40);
    carRental.addCar(&kleinbus);
    carRental.addCar(&fordFocus);
    carRental.addCar(&vwBus);
    carRental.simulate(10);
    return 0;
};
