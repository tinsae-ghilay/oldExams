//
// Created by tgk on 5/7/24.
//

#ifndef ROBOT_H
#define ROBOT_H
# include "RSensors.h"
# include <map>
# include "RobotException.h"
# include <unistd.h>
# include "Motor.h"
# include <memory>

class Robot {

private:
    Motor* motor;
    int id_;
    std::map<int,RSensor*> sensors;
    Robot();
public:
    ~Robot();
    int addSensor(RSensor* sensor);
    RSensor* getSensor(int id);
    void deleteSensor(int id);
    void eventLoop();

    static Robot* getInstance();

};


#endif //ROBOT_H
