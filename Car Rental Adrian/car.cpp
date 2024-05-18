/*Beginnen Sie mit der Implementierung der Klasse Car 
und deren Subklassen. Testen Sie diese ausführlich.*/
#include <iostream>
#include <random>
#include <chrono>
#include "car.h"
#include "exceptions.h"

/*Car
Die Klasse Car ist die Oberklasse aller Autos und definiert deren öffentliches Interface.

Objektfunktionen:
bool checkCar(): Überprüft die Fahrtüchtigkeit des Autos und gibt true zurück, wenn die Fahrtüchtigkeit gegeben ist. Bei gefundenen Problemen wird eine Exception geworfen (BrokenMotorException, ElectronicsFaultException oder EmissionsTooDirtyException).
int getRequiredDrivingLicence(): Gibt die benötigte Führerscheinklasse zurück.
int getPassengerCount(): Gibt die Anzahl der Passagierplätze zurück.*/


// VW Bus
bool VWBus::checkCar() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(1, 100);
    int random = dis(gen);
    if (random <= 5) {
        std::cout << "VW Bus encountered: " << std::endl;
        throw BrokenMotorException();
    }
    if (random <= 10) {
        std::cout << "VW Bus encountered: " << std::endl;
        throw ElectronicsFaultException();
    }
    return true;
}

int VWBus::getRequiredDrivingLicence() {
    return licenceType;
}

int VWBus::getPassengerCount() {
    return passengerCount;
}

VWBus::VWBus() {
    std::cout << "VWBus created" << std::endl;
}

VWBus::~VWBus() {
    std::cout << "VWBus destroyed" << std::endl;
}



// Ford Focus
bool FordFocus::checkCar() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(1, 100);
    int random = dis(gen);
    if (random <= 8) {
        std::cout << "Ford Focus encountered: " << std::endl;
        throw BrokenMotorException();
    }
    if (random <= 6) {
        std::cout << "Ford Focus encountered: " << std::endl;
        throw ElectronicsFaultException();
    }
    if (random <= 15) {
        std::cout << "Ford Focus encountered: " << std::endl;
        throw EmissionsTooDirtyException();
    }
    return true;
}

int FordFocus::getRequiredDrivingLicence() {
    return licenceType;
}

int FordFocus::getPassengerCount() {
    return passengerCount;
}

FordFocus::FordFocus() {
    std::cout << "FordFocus created" << std::endl;
}

FordFocus::~FordFocus() {
    std::cout << "FordFocus destroyed" << std::endl;
}



// Ferrari F40
bool FerrariF40::checkCar() {
    return true;
}

int FerrariF40::getRequiredDrivingLicence() {
    return licenceType;
}

int FerrariF40::getPassengerCount() {
    return passengerCount;
}

FerrariF40::FerrariF40() {
    std::cout << "FerrariF40 created" << std::endl;
}

FerrariF40::~FerrariF40() {
    std::cout << "FerrariF40 destroyed" << std::endl;
}



// Kleinbus
bool Kleinbus::checkCar() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(1, 100);
    int random = dis(gen);
    if (random <= 15) {
        std::cout << "Kleinbus encountered: " << std::endl;
        throw BrokenMotorException();
    }
    if (random <= 10) {
        std::cout << "Kleinbus encountered: " << std::endl;
        throw ElectronicsFaultException();
    }
    if (random <= 5) {
        std::cout << "Kleinbus encountered: " << std::endl;
        throw EmissionsTooDirtyException();
    }
    return true;
}

int Kleinbus::getRequiredDrivingLicence() {
    return licenceType;
}

int Kleinbus::getPassengerCount() {
    return passengerCount;
}

Kleinbus::Kleinbus() {
    std::cout << "Kleinbus created" << std::endl;
}

Kleinbus::~Kleinbus() {
    std::cout << "Kleinbus destroyed" << std::endl;
}

