//
// Created by tgk on 5/18/24.
//

#include "carRental.h"
# include "carRentalException.h"
# include <string>
# include <memory>
# include <iostream>
# include <unistd.h>


// Fügt ein neues Auto hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
int CarRental::addCar(Car* car){

    if(car){
        this->cars[this->id_] = unique_ptr<Car>(car);
        this->id_++;
        return this->id_;
    } else{
        // InvalideCar provided
        throw InvalidCarException("Provided car not valid");
    }
}

// Gibt das Auto mit der angegebenen ID zurück.
Car* CarRental::getCar(int id){

    if(this->cars[id]){
        return this->cars[id].get();
    }else{
        // throw car not found
        throw UnavailableCarException("Car not available with ID:"+ to_string(id));
    }
}

// Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
void CarRental::deleteCar(int id){
    if(this->cars[id]){
        this->cars.erase(id);
    }else{
        // throw car not found
        throw UnavailableCarException(" Car not available for deletion");
    }
}
/*
 * Gibt ein passendes fahrtüchtiges Auto zurück,
 * dass mit der angegebenen Führerscheinklasse gefahren werden darf und mindestens die angegebene Anzahl an Passagieren befördern kann.
 * Dabei sollen die frei bleibenden Passagierplätze minimal sein.
 * Das Auto darf auch nicht schon an andere vermietet und muss fahrtüchtig sein. Die Fahrtüchtigkeit wird mit der checkCar()-Objektfunktion überprüft.
 * Falls kein passendes Fahrzeug gefunden werden konnte, soll eine NoCarFoundException geworfen werden.
 * */
Car* CarRental::rentCar(int licenceType, int passengerCount){
    try {
        for(const auto& car: this->cars ){
            if(car.second->getPassengerCount() <= passengerCount && car.second->getRequiredDrivingLicence() <= licenceType){
                return car.second.get();
            }
        }
    }catch(CarRentalException & e){
        throw e;
    }
    // throw no car available
    throw UnavailableCarException("Car not available for rent");
}

//  Simuliert die angegebene Anzahl an Mietvorgängen.
//  Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.
void CarRental::simulate(int rentals){

    while(rentals){
        sleep(1);
        try {
            int license = (random()% 4) + 1;
            int capacity = (random() % 10)+1;
            auto car = this->rentCar(license,capacity);

            if(car->checkCar()) {
                cout << "car with capacity for " << car->getPassengerCount()
                     << " was rented to be driven with license :" << car->getRequiredDrivingLicence() << endl;
            }
        }catch(CarRentalException& e){
            cout << e.what()<<endl;
        }
        rentals--;
    }
}