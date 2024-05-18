#ifndef CARRENTAL_H
#define CARRENTAL_H
#include "car.h"
#include "exceptions.h"
#include <map>


/*Klasse CarRental
Die Klasse CarRental repräsentiert die Autovermietung selber und implementiert die zentrale Verwaltungsfunktionen. Da ständig neue Autos aufgenommen und alte ausgeschieden werden, wird für deren Verwaltung ein dynamischer Datencontainer benötigt. Bestimmen Sie selbstständig einen passenden Datencontainer. Autos werden durch eindeutige nummerische IDs identifiziert.

Objektfunktionen:
int addCar(Car* sensor): Fügt ein neues Auto hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
Car* getCar(int id): Gibt das Auto mit der angegebenen ID zurück.
void deleteCar(int id): Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
Car* rentCar(int licenceType, int passengerCount): Gibt ein passendes fahrtüchtiges Auto zurück, dass mit der angegeben Führerscheinklasse gefahren werden darf und mindestens die angegebene Anzahl an Passagieren befördern kann. Dabei sollen die frei bleibenden Passagierplätze minimal sein. Das Auto darf auch nicht schon an andere vermietet und muss fahrtüchtig sein. Die Fahrtüchtigkeit wird mit der checkCar()-Objektfunktion überprüft. Falls kein passendes Fahrzeug gefunden werden konnte, soll eine NoCarFoundException geworfen werden.
void simulate(int rentals): Simuliert die angegebene Anzahl an Mietvorgängen. Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.*/

class CarRental {
public:
    int addCar(Car* sensor);
    Car* getCar(int id);
    void deleteCar(int id);
    Car* rentCar(int licenceType, int passengerCount);
    void simulate(int rentals);
    std::map<int, Car*> cars;
    int nextCarIndex = 0;
    CarRental();
    ~CarRental();
    
};

#endif
