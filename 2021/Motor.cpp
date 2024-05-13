
#include "Motor.h"


// default constructor -> Private
Motor::Motor() = default;

// getter
int Motor::getSpeed() const {
    return this->speed_;
}

// setter
void Motor::setSpeed(int speed) {

    if(speed < 0){
        this->speed_ = Motor::MIN_SPEED;
    }
    if(speed > Motor::MAX_SPEED){
        this->speed_ = Motor::MAX_SPEED;
    }else{
        this->speed_= speed;
    }
}



// to do test of this class
// this was done to see if motor object works as intended.
void Motor::selfTest() {

    cout<<"motor will run self test"<<endl;
    sleep(1);
    cout<<"motor decoupled from robot"<<endl;
    sleep(1);
    while(this->getSpeed()<300){
        sleep(1);
        this->setSpeed(this->getSpeed()*2);
        cout <<"\r"<< "speed = "<<this->getSpeed()<<" RPM"<<flush;
    }
    sleep(2); // stay 3 sec at max speed

    while(this->getSpeed()!=0){
        sleep(1);
        cout <<"\r" << "speed = "<<this->getSpeed()<<" RPM"<<flush;
        this->setSpeed(this->getSpeed()/2);
    }

    cout <<"\r"<< "speed = "<<this->getSpeed();
    sleep(1);
    cout <<" rpm: -- Full stop --"<<endl;
    sleep(1);
    //toggleSwitch(); // off
    cout << "Off:";
    sleep(1);
    cout << " Motor was tested successfully"<<endl;
} // end of motor Test


// this class is a singleton object. there exists (in our case) only one motor
// gets an instance of the object if already loaded. creates a new one if not
Motor *Motor::getInstance() {
    static Motor* Instance_;
    if(Instance_){ // Instance already running
        return Instance_;
    }else{ // Instance needs to be created
        Instance_ = new Motor();
        return  Instance_;
    }
}

// nothing fancy just setting speed to 0
void Motor::emergencyBreak() {
    this->speed_ = 0;
}

