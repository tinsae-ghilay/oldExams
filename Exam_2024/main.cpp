//
// Created by tgk on 5/18/24.
//

# include "carRental.h"
# include "car.h"

int main(){


    auto shop = new CarRental();

    shop->addCar(new VWBus());
    shop->addCar(new FordFocus());
    shop->addCar(new FerrariF40());
    shop->addCar(new Minibus());
    shop->simulate(20);

    return 0;
}