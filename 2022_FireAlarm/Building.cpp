//
// Created by tgk on 5/12/24.
//

#include "Building.h"


// Konstruktor, dem die Anzahl der Stockwerke übergeben wird.
Building::Building(int floors)
{
    this->floors = floors;
    this->installSirens();
}
Building::~Building()
{

    this->sirens.clear();
    this->sensors.clear();
}

// adds Sirens to building complex
void Building::installSirens()
{

    // adding external Siren
    this->alarm = make_unique<Siren>();

    // adding Sirens on every floor
    for(int i = 0; i < this->floors; i++){
        this->sirens.push_back(std::make_unique<Siren>());
    }
}

// generates a key as an ID for each sensor
// based on Floor number and sensor type
int Building::encodeID(int floor, int id)
{
    // we start from 1 for id because we want ID to have at least 2 digits (my preference)
    // assume floor is 0, from our formula, ID for sensor type 1 would be 11, and type 2 = 12
    // if we don't add 1 to floor, it will just be 0*10 + 1 = 1 (not a 2-digit number)
    // for floor 1, type 1 has ID 21 and type 2 has ID 22. we also use that as key for map

    return (id==1)?((floor+1)*100)+(id*10)+(smoke_detectors++):((floor+1)*100)+(id*10)+(infrared_detectors++);
}

/*
 * Fügt einen neuen Sensor zum angegebenen Stockwerk hinzu (Nummerierung startet bei 0).
 * Der Rückgabewert ist eine ID, die den jeweiligen Sensor eindeutig im jeweiligen Stockwerk identifiziert
 * ID muss, nur innerhalb eines Stockwerks eindeutig sein, geeignete ID selbstständig wählen.
 */
int Building::addSensor(int floor, Sensor* sensor)
{

    // id is an int with first digit as a floor number
    // and second digit as sensor type
    int key = this->encodeID(floor,sensor->getType());
    // unique pointer to store sensor in map;
    this->sensors[key] = unique_ptr<Sensor>(sensor);
    // store it in map, and return the key
    return key;
}

// Gibt den Sensor im angegebenen Stockwerk mit der angegebenen ID zurück.
Sensor* Building::getSensor(int floor, int id)
{

    int key = this->encodeID(floor,id);
    if(this->sensors[key].get()) {
        return this->sensors[key].get();
    }else{
        throw FireAlarmException("Sensor not found");
    }
}

// Zerstört den Sensor im angegebenen Stockwerk mit der angegebenen ID
void Building::deleteSensor(int floor, int id)
{
    int key = this->encodeID(floor,id);
    try{
        this->sensors.erase(key);
    }catch(...){
        throw FireAlarmException("Sensor not found");
    }
}

/*
 * Überprüft alle Sensoren in allen Stockwerken.
 * Diese Funktion wird in regelmäßigen Zeitabständen aufgerufen (z.B. alle Sekunden).
 * Der Zweck dieser Funktion ist es, Brände zu erkennen und darauf zu reagieren.
 */
void Building::checkSensors()
{

    for(const auto&[key,sensor]:this->sensors){
        try{
            // Check all sensors
            sensor->checkSensor();
        }catch(ErrorDetectedException& e){ // error detected
            // Error is ok, just pass it on.
            throw ErrorDetectedException(e);
        }catch(FireDetectedException& e){ // fire detected

            // Reporting error
            cout <<"Floor "<< key/100 <<" : "<<e.what() <<endl;
            // turning Siren of that floor on.
            cout <<"Floor "<< key/100 <<" : ";
            this->sirens[key/100]->switchOn();
            // turning external Siren on.
            cout <<"Gate : ";
            this->alarm->switchOn();
            throw FireDetectedException(e);
        }
    }
}


// Schaltet alle Sirenen wieder aus.
void Building::cancelAlarm()
{

    // switch floor alarm off
    for(int i = 0; i < this->floors; i++){

        if(this->sirens[i]->isOn()){
            cout << "-> Floor  "<<i<<" : ";
            this->sirens[i]->switchOff();
        }
    }
    // switch external alarm off
    if(this->alarm->isOn()){
        cout << "-> Gate : ";
        this->alarm->switchOff();
    }

}