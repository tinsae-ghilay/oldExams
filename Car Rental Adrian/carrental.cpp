#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include "carrental.h"
#include "car.h"
#include "exceptions.h"

/*Car Rental CPP
Objektfunktionen:
int addCar(Car* sensor): Fügt ein neues Auto hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
Car* getCar(int id): Gibt das Auto mit der angegebenen ID zurück.
void deleteCar(int id): Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
Car* rentCar(int licenceType, int passengerCount): Gibt ein passendes fahrtüchtiges Auto zurück, dass mit der angegeben Führerscheinklasse gefahren werden darf und mindestens die angegebene Anzahl an Passagieren befördern kann. Dabei sollen die frei bleibenden Passagierplätze minimal sein. Das Auto darf auch nicht schon an andere vermietet und muss fahrtüchtig sein. Die Fahrtüchtigkeit wird mit der checkCar()-Objektfunktion überprüft. Falls kein passendes Fahrzeug gefunden werden konnte, soll eine NoCarFoundException geworfen werden.
void simulate(int rentals): Simuliert die angegebene Anzahl an Mietvorgängen. Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.*/



int CarRental::addCar(Car* sensor) {
    cars[nextCarIndex] = sensor;
    nextCarIndex++;
    return nextCarIndex - 1;
}

Car* CarRental::getCar(int id) {
    return cars[id];
}

void CarRental::deleteCar(int id) {
    delete cars[id];
    cars.erase(id);
}
Car* CarRental::rentCar(int licenceType, int passengerCount) {
    std::vector<int> possibleCars;
    for (auto const& car : cars) {
        if (car.second->getRequiredDrivingLicence() <= licenceType && car.second->getPassengerCount() >= passengerCount) {
            try {
                car.second->checkCar();
                possibleCars.push_back(car.first);
            }
            catch (CarRentalException& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    if (possibleCars.size() == 0) {
        throw NoCarFoundException();
    }

    // Generate a random index
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, possibleCars.size() - 1);
    int randomIndex = dis(gen);

    // Return a random car from the possible cars
    return cars[possibleCars[randomIndex]];
}

void CarRental::simulate(int rentals) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> disLicence(1, 2);
    std::uniform_int_distribution<> disPassenger(1, 8);
    for (int i = 0; i < rentals; i++) {
        try {
            rentCar(disLicence(gen), disPassenger(gen));
        }
        catch (CarRentalException& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

CarRental::CarRental() {
    std::cout << "CarRental created" << std::endl;
}

CarRental::~CarRental() {
    std::cout << "CarRental destroyed" << std::endl;
}




