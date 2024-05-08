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
    int max_speed = 7200;
    bool on = false;

    Motor();

public:

    int getSpeed() const;

    void setSpeed(int speed);

    void accelerate(int to);
    void decelerate(int target_speed);

    void engageBreaks(int fin);

    void turnOn();

    void turnOff();

    void toggleSwitch();

    void emergencyBreak();

    void selfTest();

    static Motor *getInstance();

};
#endif //MOTOR_H
