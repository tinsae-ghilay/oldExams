//
// Created by tgk on 5/6/24.
//

#ifndef MOTOR_H
#define MOTOR_H

# include<iostream>
# include <unistd.h>
using namespace std;

class Motor {
private:
    int speed_;
    bool on = false;
    Motor()=default;
public:

    inline int getSpeed() const{
        return this->speed_;
    }
    inline void setSpeed(int speed){
        if(!this->on){
            this->on = true;
        }
        if(speed >= 0 && speed < 300) {
            this->speed_ = speed;
        }else if(speed > 300){
            this->speed_=300;
        }else{
            emergencyBreak();
            cout <<", because you tried to reverse motor abruptly: Speed = "<<this->speed_<<endl;
        }
    }
    inline void accelerate(){
        int i = 1;
        while(this->on && i <3){
            this->setSpeed(i*100);
            cout << "current speed = "<< this->getSpeed()<<"0"<<endl;
            sleep(1);
            i++;
        }
    }
    inline void turnOn(){
        this->on=true;
        this->accelerate();

    }
    inline void turnOff(){
        this->on= false;
    }

    inline void toggleSwitch(){
        this->on = !this->on;
    }

    inline static Motor* getInstance(){
        static Motor* Instance_;
        if(Instance_){
            return Instance_;
        }else{
            Instance_ = new Motor();
            return  Instance_;
        }
    }
    inline void emergencyBreak(){
        while(this->speed_!=0){
            this->speed_= this->speed_/2;
        }
        this->on= false;
        cout<<"Emergency stop! ";
    }



    void selfTest(){
        cout<<"motor will run self test"<<endl;
        sleep(1);
        cout<<"motor decoupled from robot"<<endl;
        sleep(1);
        if(!this->on){
            this->toggleSwitch(); // turn off or on
            this->setSpeed(10);
            cout<<"motor turned on"<<endl;
            sleep(1);
            cout <<"\r"<< "speed = "<<this->getSpeed()<<"000rpm"<<flush;

        }
        while(this->getSpeed()<300){
            sleep(1);
            this->setSpeed(this->getSpeed()*2);
            cout <<"\r"<< "speed = "<<this->getSpeed()<<"000rpm"<<flush;
        }
        sleep(2); // stay 3 sec at max speed
        while(this->getSpeed()!=0){
            sleep(1);
            cout <<"\r" << "speed = "<<this->getSpeed()<<"000rpm"<<flush;
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
};


#endif //MOTOR_H
