//
// Created by tgk on 5/18/24.
//

# include "carRental.h"
# include "car.h";

int main(){


    auto shop = new CarRental();
    shop->addCar(new VWBus());
    shop->simulate(10);

    return 0;
}