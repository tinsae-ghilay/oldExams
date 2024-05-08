//
// Created by tgk on 5/6/24.
//
# include "Motor.h"
# include "Sensors.h"
# include "Robot.h"
# include <memory>
# include <ctime>
using namespace std;
int main(){

    // Robot -> smart pointer
    auto robot = make_unique<Robot>(*Robot::getInstance());

    // adding robots... cannot make them smart pointers because that would change footprint(For the prof.)
    if(robot->addSensor(new UltrasonicSensor())
        &&  robot->addSensor(new LaserSensor())
        && robot->addSensor(new CameraSensor()))
    { // all sensors added successfully

        cout << "Systems ready "<<endl;
        // run event loop of robot
        robot->eventLoop();
    }else{

        cout << "Error while activating robot sensors! refer to service manual"<<endl;
    }
    return 0;
}