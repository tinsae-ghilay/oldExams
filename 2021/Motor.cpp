
#include "Motor.h"

Motor::Motor() = default;

int Motor::getSpeed() const {
    return this->speed_*10;
}

void Motor::setSpeed(int speed) {

    if(!this->on){
        this->on = true;
    }
    if(speed >= 0 && speed < 300) {
        this->speed_ = speed;
    }else if(speed > 300){
        this->speed_=300;
    }else{
        emergencyBreak();
        cout <<", because you tried to reverse motor abruptly: Speed = "<<this->getSpeed()<<" RPM"<<endl;
    }
}

void Motor::accelerate() {

    int i = 1;
    while(this->on && i <3){
        this->setSpeed(i*100);
        cout << "current speed = "<< this->getSpeed()<<" RPM"<<endl;
        sleep(1);
        i++;
    }
}

void Motor::turnOn() {

    this->on=true;
    this->accelerate();
}

void Motor::turnOff() {

    this->on= false;
}

void Motor::toggleSwitch() {
    this->on = !this->on;
}

void Motor::emergencyBreak() {

    while(this->speed_>0){
        this->speed_/=4;
        cout<<"current speed = : "<<this->getSpeed()<<" RPM"<<endl;
        sleep(1);
    }
    this->on= false;
    cout<<"Emergency stop! ";
}

void Motor::selfTest() {

    cout<<"motor will run self test"<<endl;
    sleep(1);
    cout<<"motor decoupled from robot"<<endl;
    sleep(1);
    if(!this->on){
        this->toggleSwitch(); // turn off or on
        this->setSpeed(10);
        cout<<"motor turned on"<<endl;
        sleep(1);
        cout <<"\r"<< "speed = "<<this->getSpeed()<<" RPM"<<flush;

    }
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
    //sleep(1);
    cout <<"\r"<< "speed = "<<this->getSpeed();
    sleep(1);
    cout <<" rpm: -- Full stop --"<<endl;
    sleep(1);
    toggleSwitch(); // off
    cout << "Off:";
    sleep(1);
    cout << " Motor was tested successfully"<<endl;
}

Motor *Motor::getInstance() {
    static Motor* Instance_;
    if(Instance_){
        return Instance_;
    }else{
        Instance_ = new Motor();
        return  Instance_;
    }
}

