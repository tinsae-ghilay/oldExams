//
// Created by tgk on 5/18/24.
//

#ifndef CAR_H
#define CAR_H

# include <random>
# include "carRentalException.h"
# include <string>

/*
 * Die Klasse Car ist die Oberklasse aller Autos und definiert deren öffentliches Interface.
 * Es gibt vier konkrete Autotypen:
 */
class Car {

private:
    int licence_level = 1;
protected:
    int capacity;
    std::string model;


public:
    // Überprüft die Fahrtüchtigkeit des Autos und gibt true zurück, wenn die Fahrtüchtigkeit gegeben ist.
    virtual inline bool checkCar() = 0;

    // Gibt die benötigte Führerscheinklasse zurück.
    inline int getRequiredDrivingLicence() const{
        return this->licence_level;
    };

    //Gibt die Anzahl der Passagierplätze zurück.
    int getPassengerCount() const{
        return this->capacity;
    }

    void setLicenceLevel(int level){
        this->licence_level = level;
    }

    std::string getModel()const{
        return this->model;
    }

};

/*
 *VW Bus: 8 Passagierplätze :Führerscheinklasse: 2
*/
class VWBus: public Car{

public:
    VWBus(){
        this->capacity = 4;
        this->model = "VW Bus";
    }
    /*
     * Hat eine 5 % Wahrscheinlichkeit eine BrokenMotorException zu werfen.
     * Hat eine 10 % Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
     * Eine EmissionsTooDirtyException kann bei diesem Fahrzeug nicht vorkommen.
     * */
    inline bool checkCar() override{

        int rnd = random()%100;
        if(rnd > 94){
            // throw BrokenMotorException
            throw BrokenMotorException("Car is out of order: Brocken Motor");
        } else if (rnd < 10){
            // throw ElectronicsFaultException
            throw ElectronicsFaultException(" Car has electronic problems: needs repair");
        }else{
            // dandy
            return true;
        }
    }
};

/*
 * Ford Focus : 4 Passagierplätze: Führerscheinklasse: 1
*/
class FordFocus: public Car{

public:
    FordFocus(){
        this->capacity = 4;
        this->model = "Ford Focus";
    }
    /*
     * Hat eine 8 % Wahrscheinlichkeit eine BrokenMotorException zu werfen.
     * Hat eine 6 % Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
     * Hat eine 15 % Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
     * */
    inline bool checkCar() override{

        int rnd = random()%100;
        if(rnd > 91) {

            // throw BrokenMotorException
            throw BrokenMotorException("Car is out of order: Brocken Motor");
        }else if(rnd > 14 && rnd < 21 ){
                // throw ElectronicsFaultException
            throw ElectronicsFaultException(" Car has electronic problems: needs repair");

        } else if (rnd < 15) {
            // throw EmissionsTooDirtyException
            throw EmissionsTooDirtyException(" Car emitting too much CO2: needs to pass requirements");
        }else{
            // dandy
            return true;
        }
    }
};

/*
 * Ferrari F40 : 1 Passagierplatz: Führerscheinklasse: 3
*/
class FerrariF40: public Car{
public:
    FerrariF40(){
        this->capacity = 1;
        this->setLicenceLevel(3);
    }

    // ein Ferrari kann nicht kaputtgehen, daher kommt es bei diesem Fahrzeug zu keiner Exception.
    inline bool checkCar() override{
        return true;
    }
};

/*
 * Kleinbus : 20 Passagierplätze: Führerscheinklasse: 4
*/
class Minibus: public Car{
public:
    Minibus(){
        this->capacity = 20;
        this->setLicenceLevel(4);
    }

    /*
     * Hat eine 15 % Wahrscheinlichkeit eine BrokenMotorException zu werfen.
     * Hat eine 10 % Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
     * Hat eine 5 % Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
     * */
    inline bool checkCar() override{

        int rnd = random()%100;
        if(rnd > 84) {

            // throw BrokenMotorException
            throw BrokenMotorException("Car is out of order: Brocken Motor");
        }else if(rnd > 4 && rnd < 14 ){
            // // throw ElectronicsFaultException
            throw ElectronicsFaultException("Car has electronic problems: needs repair");

        } else if (rnd < 5) {
            // throw EmissionsTooDirtyException
            throw EmissionsTooDirtyException("Car emitting too much CO2: needs to pass requirements");
        }else{
            // dandy
            return true;
        }
    }
};


#endif //CAR_H
