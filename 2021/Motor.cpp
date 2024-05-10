
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

// increases motor speed * 3 every sec.
/*void Motor::accelerate(int to) {

    if(to > this->getSpeed()) {
        while (this->on && this->getSpeed() < to) {
            this->setSpeed(this->getSpeed() * 3);
            cout <<"\r"<< "Accelerating .... Current speed = " << this->getSpeed() << " RPM"<<flush;
            sleep(1);
        }
        cout<< endl;
    }
}*/

// turns motor on
/*void Motor::turnOn() {

    this->on=true;
    this->setSpeed(50);
    cout << "Motor turned On" << endl;
    this->accelerate(Motor::MAX_SPEED);
}

// turns motor off
void Motor::turnOff() {
    this->on= false;
    cout << "Motor turned off" << endl;
}*/

// toggles motor on <-> off
/*void Motor::toggleSwitch() {
    this->on = !this->on;
}*/

// stops motor with breaking effect
void Motor::emergencyBreak() {

    this->setSpeed(0);
    cout<<"EMERGENCY STOP!!! ";
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

// engages motor breaks to reduce speed
void Motor::engageBreaks(int fin) {
    sleep(1);
    cout <<"Motor Breaks engaged at "<<this->getSpeed()<<" RPM"<<endl;
    while(this->speed_>fin){
        this->speed_/=5;
        sleep(1);
        cout <<"\r"<< "Decelerating ....  " << this->getSpeed() << " RPM"<<flush;
    }
    cout << endl;
}

void Motor::runSlow(const string &why) {

    cout << why<<endl;
    if(this->getSpeed()> Motor::MIN_SPEED){ // motor running faster than minimum
        // set motor speed to minimum
        this->setSpeed(Motor::MIN_SPEED);
    }

}

