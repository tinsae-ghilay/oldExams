//
// Created by tgk on 5/18/24.
//

#ifndef CAR_H
#define CAR_H

# include <random>

/*
 * Die Klasse Car ist die Oberklasse aller Autos und definiert deren öffentliches Interface.
 * Es gibt vier konkrete Autotypen:
 */
class Car {

private:
    int licence_level = 1;

protected:
    bool is_drivable = true;
    int capacity;

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

};

/*
 *VW Bus: 8 Passagierplätze :Führerscheinklasse: 2
*/
class VWBus: public Car{

    VWBus(){
        this->capacity = 4;
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
        } else if (rnd < 10){
            // throw ElectronicsFaultException
        }else{
            // dandy
        }
    }
};

/*
 * Ford Focus : 4 Passagierplätze: Führerscheinklasse: 1
*/
class FordFocus: public Car{

    FordFocus(){
        this->capacity = 4;
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
        }else if(rnd > 14 && rnd < 21 ){
                // // throw ElectronicsFaultException

        } else if (rnd < 15) {
            // throw EmissionsTooDirtyException
        }else{
            // dandy
        }
    }
};

/*
 * Ferrari F40 : 1 Passagierplatz: Führerscheinklasse: 3
*/
class FerrariF40: public Car{
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
 * Kleinbus : 20 Passagierplätze : Führerscheinklasse: 4
*/
class Minibus: public Car{
    Minibus(){
        this->capacity = 20;
        this->setLicenceLevel(4);
    }

    /*
     * Hat eine 15% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
     * Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
     * Hat eine 5% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
     * */
    inline bool checkCar() override{

        int rnd = random()%100;
        if(rnd > 84) {

            // throw BrokenMotorException
        }else if(rnd > 4 && rnd < 14 ){
            // // throw ElectronicsFaultException

        } else if (rnd < 5) {
            // throw EmissionsTooDirtyException
        }else{
            // dandy
        }
    }
};


#endif //CAR_H
