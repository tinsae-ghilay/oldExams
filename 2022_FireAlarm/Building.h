//
// Created by tgk on 5/12/24.
//

#ifndef BUILDING_H
#define BUILDING_H
# include <map>
# include "Sensor.h"
# include <memory>
# include <vector>
# include "Siren.h"
# include <unistd.h>



using namespace std;


class Building {

private:
    int floors;
    vector<unique_ptr<Siren>> sirens;
    unique_ptr<Siren>alarm;
    map<int, unique_ptr<Sensor*>> sensors;

    void installSirens();
    int encodeID(int floor, int id);
public:

    // Konstruktor, dem die Anzahl der Stockwerke übergeben wird.
    Building(int floors);
    // destructor;
    ~Building();
    /*
     * Fügt einen neuen Sensor zum angegebenen Stockwerk hinzu (Nummerierung startet bei 0).
     * Der Rückgabewert ist eine ID, die den jeweiligen Sensor eindeutig im jeweiligen Stockwerk identifiziert
     * ID muss, nur innerhalb eines Stockwerks eindeutig sein, geeignete ID selbstständig wählen.
     */
    int addSensor(int floor, Sensor* sensor);

    // Gibt den Sensor im angegebenen Stockwerk mit der angegebenen ID zurück.
    Sensor* getSensor(int floor, int id);

    // Zerstört den Sensor im angegebenen Stockwerk mit der angegebenen ID
    void deleteSensor(int floor, int id);

    /*
     * Überprüft alle Sensoren in allen Stockwerken.
     * Diese Funktion wird in regelmäßigen Zeitabständen aufgerufen (z.B. alle Sekunden).
     * Der Zweck dieser Funktion ist es, Brände zu erkennen und darauf zu reagieren.
     */
    void checkSensors();

    // Schaltet alle Sirenen wieder aus.
    void cancelAlarm();

};


#endif //BUILDING_H
