//
// Created by tgk on 5/18/24.
//

#ifndef CARRENTAL_H
#define CARRENTAL_H

# include "car.h"
# include <map>
# include <memory>


using namespace std;

/*
 * Die Klasse CarRental repräsentiert die Autovermietung selber und implementiert die zentralen Verwaltungsfunktionen.
 * Da ständig neue Autos aufgenommen und alte ausgeschieden werden,
 * wird für deren Verwaltung ein dynamischer Datencontainer benötigt.
*/

class CarRental {
private:
    int id_ = 0;
    map<int, unique_ptr<Car>> cars;
public:
    int addCar(Car* car);
    Car* getCar(int id);
    void deleteCar(int id);
    Car* rentCar(int licenceType, int passengerCount);
    void simulate(int rentals);
};


#endif //CARRENTAL_H
