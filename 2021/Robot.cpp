//
// Created by tgk on 5/7/24.
//

# include "Robot.h"
# include <iostream>

Robot::Robot() {
    this->motor = Motor::getInstance();
    this->id_ = 0;
}
Robot::~Robot(){
    for(auto [key,val]:this->sensors){
        delete this->sensors[key];
    }
    delete motor;
}
int Robot::addSensor(Sensor* sensor){
    this->id_++;
    this->sensors.insert(std::make_pair(this->id_, sensor));
    return this->id_;
}
Sensor* Robot::getSensor(int id){
    if(this->sensors[id]){
        return this->sensors[id];
    }else{
        // throw some error
        throw RobotException("Provided Id doesn't belong to available sensors.");
    }
}
void Robot::deleteSensor(int id){
    auto ssr = this->sensors.find(id);
    if(ssr!= this->sensors.end()){
        this->sensors.erase(ssr);
    }else{
        // throw some error
        throw RobotException("Provided Id doesn't belong to available sensors.");
    }
}
void Robot::eventLoop(){
    int i = 0;
    this->motor->turnOn();
    while(i < 15){
        int stat= 0;
        for(const auto& [key, value] : this->sensors){
            try{
                int s_stat = value->checkSensor();
                cout <<*value<<" : Error state -  "<< value->getErrorState()<< endl;
                sleep(1);
                if(s_stat > stat){
                    stat = value->checkSensor();
                }
            }catch(CriticalDangerException &e){

                cout <<*value <<" : "<< e.what() << endl;
                sleep(1);
                try {
                    value->reset();
                }catch(InternalErrorException& e){
                    cout <<*value <<" : "<<  e.what() << endl;
                    sleep(1);
                    this->motor->emergencyBreak();
                    cout << "Restarting motor" << endl;
                    sleep(1);
                    this->motor->turnOn();
                }

            }catch (InternalErrorException &e){

                cout <<*value <<" : "<< e.what() << endl;
                sleep(1);
                // reduce speed.
                int speed = (this->motor->getSpeed()/2<5)? 5:this->motor->getSpeed()/2;
                cout <<"Reduced speed to "<< speed<<" RPM" << endl;
                this->motor->setSpeed(speed);
                sleep(1);
            }
        }
        if(this->motor->getSpeed()==0){
            this->motor->accelerate();
        }else{
            this->motor->setSpeed(this->motor->getSpeed()*2);
        }
        cout << "current speed = "<< this->motor->getSpeed() << " RPM : Sensor status = "<< stat<< endl;
        sleep(1);
        // motor speed can be the speed it has / stat. thus, the higher the stat-> the lower the speed.
        i++;
    }
}

Robot* Robot::getInstance() {
    static Robot* Instance_;
    if(Instance_){
        return Instance_;
    }else{
        Instance_ = new Robot;
        return Instance_;
    }
}
