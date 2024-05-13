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
    static const int MAX_SPEED = 7200;
    static const int MIN_SPEED = 200;

    int getSpeed() const;

    void setSpeed(int speed);

    void emergencyBreak();

    void selfTest();

    static Motor *getInstance();

};
#endif //MOTOR_H
