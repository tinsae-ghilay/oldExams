//
// Created by tgk on 5/18/24.
//

#include "carRental.h"


// Fügt ein neues Auto hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
int CarRental::addCar(Car* car){

    if(car){
        this->cars[this->id_] = unique_ptr<Car>(car);
        this->id_++;
        return this->id_;
    } else{
        // InvalideCar provided
    }
}

// Gibt das Auto mit der angegebenen ID zurück.
Car* CarRental::getCar(int id){

    if(this->cars[id]){
        return this->cars[id].get();
    }else{
        // throw car not found
    }
}

// Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
void CarRental::deleteCar(int id){}
/*
 * Gibt ein passendes fahrtüchtiges Auto zurück,
 * dass mit der angegebenen Führerscheinklasse gefahren werden darf und mindestens die angegebene Anzahl an Passagieren befördern kann.
 * Dabei sollen die frei bleibenden Passagierplätze minimal sein.
 * Das Auto darf auch nicht schon an andere vermietet und muss fahrtüchtig sein. Die Fahrtüchtigkeit wird mit der checkCar()-Objektfunktion überprüft.
 * Falls kein passendes Fahrzeug gefunden werden konnte, soll eine NoCarFoundException geworfen werden.
 * */
Car* CarRental::rentCar(int licenceType, int passengerCount){}

void CarRental::simulate(int rentals){}