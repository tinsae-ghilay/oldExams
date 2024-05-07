//
// Created by tgk on 5/6/24.
//
# include "Motor.h"
# include "Sensors.h"
# include "Robot.h"
using namespace std;
int main(){
    // singleton motor
    //Motor* m = Motor::getInstance();
    // do self test.
    //m->selfTest();
    Robot* robot = Robot::getInstance();


    // testing sensors
    auto s1 = new UltrasonicSensor();
    auto s2 = new LaserSensor();
    auto s3 = new CameraSensor();
    if(robot->addSensor(s1) &&  robot->addSensor(s2) && robot->addSensor(s3)){
        cout << "Sensors added "<<endl;
        robot->eventLoop();
    }else{

        cout << "couldn't add sensors"<<endl;
    }
    // activate sensor

    delete robot;
    return 0;
}