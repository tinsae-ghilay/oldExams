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

    int speed_ = 0;
    bool on = false;

    Motor();

public:

    int getSpeed() const;

    void setSpeed(int speed);

    void accelerate();

    void turnOn();

    void turnOff();

    void toggleSwitch();

    void emergencyBreak();

    void selfTest();

    static Motor *getInstance();

};
#endif //MOTOR_H
