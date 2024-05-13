//
// Created by tgk on 5/6/24.
//

# include "RSensors.h"
# include <iostream>
# include "RobotException.h"


using namespace std;


RSensor::RSensor() {
    this->setErrorState(false);
    this->is = "RSensor ";
}
RSensor::~RSensor()=default;


int RSensor::checkSensor(){
    return 0;
}


bool RSensor::getErrorState() const{
    return this->error_state;
}


void RSensor::reset(){
}


void RSensor::setErrorState(bool state){
    this->error_state = state;
}


// for testing purposes
void RSensor::activate() {
    int dur = 0;
    while (dur < 10){
        try{
            cout <<*this << this->checkSensor() << " with error-state ->"<<this->getErrorState()<<endl;
        }catch(CriticalDangerException &e){
            cout << e.what()<<endl;
            try {
                this->reset();
            }catch(InternalErrorException& e){
                cout << "Motor should stop here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
            }
        }catch (InternalErrorException& e){
            cout << e.what() << endl;
        }
        sleep(1);
        dur++;
    }
}


// child classes

// sonic
UltrasonicSensor::UltrasonicSensor(){
        this->max = 60;
        this->is ="Ultrasonic RSensor ";
}

int UltrasonicSensor::checkSensor() {
    int rnd = (int)random() % 10;
    if(rnd == 1){ // 1 = 1/10 = 10% probability for critical exception
        this->setErrorState(true);
        // throw CriticalDangerException
        throw CriticalDangerException("UltrasonicSensor-> Movement detected in close proximity.");

    }else if(rnd == 2 || rnd == 3) { // 2 & 3  (1/10) + (1/10)  = 20% probability for internal error
        this->setErrorState(true);
        // throw InternalErrorException
        throw InternalErrorException("UltrasonicSensor  not working within required parameters.");
    }else{
        return (int)random() % this->max;
    }
}

void UltrasonicSensor::reset() {
    int rnd = (int)random()%10;
    if(rnd < 6){ // 0,1,2,3,4,5 = 6(1/10) = 60 % chance
        this->setErrorState(false);
        cout << *this << "Reset Successfully"<<endl;

    }else{
        // throw InternalErrorException
        throw InternalErrorException("Unable to reset UltrasonicSensor.");
    }
}

// laser
LaserSensor::LaserSensor(){
    this->max = 80;
    this->is ="Laser RSensor ";
}
int LaserSensor::checkSensor() {
    int rnd = (int)random() % 10;
    if(rnd == 0 || rnd == 1){ // 0 and 1 = 2/10 = 20% probability for critical exception
        this->setErrorState(true);
        // throw CriticalDangerException
        throw CriticalDangerException("Laser RSensor-> Unable to determine distance.");

    }else if(rnd == 2) { // 2   1/10 = 10% probability for internal error
        this->setErrorState(true);
        // throw InternalErrorException
        throw InternalErrorException("Laser RSensor-> Beam out of focus.");

    }else{
        return (int)random() % this->max;
    }
}

void LaserSensor::reset() {
    int rnd = (int)random()%10;
    if(rnd <5 ){ // 0,1,2,3,4 = 5(1/10) = 50 % chance
        this->setErrorState(false);
        cout << *this << "Reset Successfully"<<endl;

    }else{
        // throw InternalErrorException
        throw InternalErrorException("Unable to reset Laser RSensor.");
    }
}

// camera
CameraSensor::CameraSensor(){
    this->max = 100;
    this->is ="Camera RSensor ";
}
int CameraSensor::checkSensor() {
    int rnd = (int)random() % 10;
    if(rnd == 0){ // 1 = 1/10 = 10% probability for critical exception
        this->setErrorState(true);
        // throw CriticalDangerException
        throw CriticalDangerException("Camera RSensor-> View blocked.");

    }else if(rnd == 1 || rnd ==2) { // 1/10 + 1/10   = 20% probability for internal error
        this->setErrorState(true);
        // throw InternalErrorException
        throw InternalErrorException("Camera RSensor-> unable to focus view.");

    }else{
        return (int)random() % this->max;
    }
}

void CameraSensor::reset() {
    int rnd = (int)random()%10;
    if(rnd > 4){ // 0,1,2,3 = 4(1/10) = 40 % chance
        this->setErrorState(false);
        cout << *this << "Reset Successfully"<<endl;

    }else{
        // throw InternalErrorException
        throw InternalErrorException("Unable to reset Camera RSensor.");
    }
}

std::ostream& operator<<(std::ostream& is, RSensor& s){
    return  is << s.is;
}
