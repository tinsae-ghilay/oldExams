#ifndef CAR_H
#define CAR_H

/*Klasse Car
Die Klasse Car ist die Oberklasse aller Autos und definiert deren öffentliches Interface.

Objektfunktionen:
bool checkCar(): Überprüft die Fahrtüchtigkeit des Autos und gibt true zurück, wenn die Fahrtüchtigkeit gegeben ist. Bei gefundenen Problemen wird eine Exception geworfen (BrokenMotorException, ElectronicsFaultException oder EmissionsTooDirtyException).
int getRequiredDrivingLicence(): Gibt die benötigte Führerscheinklasse zurück.
int getPassengerCount(): Gibt die Anzahl der Passagierplätze zurück.*/

class Car {
public:
    virtual bool checkCar() = 0;
    virtual int getRequiredDrivingLicence() = 0;
    virtual int getPassengerCount() = 0;




};

/*VW Bus
8 Passagierplätze
Führerscheinklasse: 2
Hat eine 5% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
Eine EmissionsTooDirtyException kann bei diesem Fahrzeug nicht vorkommen.*/

class VWBus : public Car {
public:
    bool checkCar();
    VWBus(); // Constructor
    ~VWBus(); // Destructor
 
private:
    int getRequiredDrivingLicence() override;
    int getPassengerCount() override;
    int passengerCount = 8;
    int licenceType = 2;

};

/*Ford Focus
4 Passagierplätze
Führerscheinklasse: 1
Hat eine 8% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
Hat eine 6% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
Hat eine 15% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.*/

class FordFocus : public Car {
public:
    bool checkCar();
    FordFocus(); // Constructor
    ~FordFocus(); // Destructor

private:
    int getRequiredDrivingLicence() override;
    int getPassengerCount() override;
    int passengerCount = 4;
    int licenceType = 1;
};

/*Ferrari F40
1 Passagierplatz
Führerscheinklasse: 3
Ein Ferrari kann nicht kaputt gehen, daher kommt es bei diesem Fahrzeug zu keiner Exception.
*/

class FerrariF40 : public Car {
public:
    bool checkCar();
    FerrariF40(); // Constructor
    ~FerrariF40(); // Destructor
    int getRequiredDrivingLicence() override;
    int getPassengerCount() override;

private:
    
    int passengerCount = 1;
    int licenceType = 3;
};

/*Kleinbus
20 Passagierplätze
Führerscheinklasse: 4
Hat eine 15% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
Hat eine 5% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.*/

class Kleinbus : public Car {
public:
    bool checkCar();
    Kleinbus(); // Constructor
    ~Kleinbus(); // Destructor

private:
    int getRequiredDrivingLicence() override;
    int getPassengerCount() override;
    int passengerCount = 20;
    int licenceType = 4;
};







#endif // CAR_H
