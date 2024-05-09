//
// Created by tgk on 5/7/24.
//

# include   "Robot.h"
# include <iostream>


// constructor, sets Motor instance and initial id.
Robot::Robot() {

    this->motor = Motor::getInstance();
    this->id_ = 0;
}

// destructor
Robot::~Robot(){
    for(auto [key,val]:this->sensors){ // all sensors
        delete this->sensors[key];
    }
    delete motor; // motor should also be deleted.
}

// adds sensors to Robot
int Robot::addSensor(Sensor* sensor){
    this->id_++;
    this->sensors.insert(std::make_pair(this->id_, sensor));
    return this->id_;
}

// getter for sensors
Sensor* Robot::getSensor(int id){
    if(this->sensors[id]){
        return this->sensors[id];
    }else{
        // throw some error
        throw RobotException("Provided Id doesn't belong to available sensors.");
    }
}

// deletes sensor
void Robot::deleteSensor(int id){
    auto ssr = this->sensors.find(id);
    if(ssr!= this->sensors.end()){
        this->sensors.erase(ssr);
    }else{
        // throw some error
        throw RobotException("Provided Id doesn't belong to available sensors.");
    }
}

// runs the robots sensors and motor
// reports sensor logs
void Robot::eventLoop(){
    int i = 0;
    time_t start = time(nullptr);
    this->motor->turnOn();
    while(i < 7){ // can be any number. the higher the number -> the longer the event snapshot
        int stat= 0; // sensor state initially 0, before we get first data.
        for(const auto& [key, value] : this->sensors){
            try{ // I am not sure if the catch clauses
                int s_stat = value->checkSensor(); // retrieve sensor state
                cout <<*value<<" : Error state -  "<< value->getErrorState()<< endl;
                sleep(1);
                if(s_stat > stat){ // sensor state is the highest of previous sensor states
                    stat = value->checkSensor();
                }
            }catch(const CriticalDangerException &e){ // critical error exception while checking sensor

                cout <<*value <<" : "<< e.what() << endl;
                sleep(1);
                try { // reset sensor
                    value->reset();
                }catch(const InternalErrorException& e){ // error while resetting sensor
                    cout <<*value <<" : "<<  e.what() << endl;
                    sleep(1);
                    // engage motor breaks and stop motor
                    this->motor->emergencyBreak();
                    cout << "Restarting motor" << endl;
                    sleep(1);
                    // restart motor and run again
                    this->motor->turnOn();
                }

            }catch (const InternalErrorException &e){ // internal error exception

                cout <<*value <<" : "<< e.what() << endl;
                sleep(1);
                // reduce motor speed.
                int speed = (this->motor->getSpeed()/2<5)? 5:this->motor->getSpeed()/2;
                if(speed >300){
                    cout <<"Reducing speed  to avoid accident!"<< endl;
                    this->motor->engageBreaks(speed);
                    sleep(1);
                }
            }
        }
        // motor might have reduced speed -> get it back to speed
        this->motor->accelerate(7200/*max speed of motor*/);
        cout << "current speed = "<< this->motor->getSpeed() << " RPM : Sensor status = "<< stat<< endl;
        sleep(1);
        i++;
    }
    cout << "Done testing parameters: ending process"<<endl;
    sleep(1);
    this->motor->engageBreaks(0);
    this->motor->turnOff();
    time_t end = time(nullptr);

    cout << "Test done in "<<end-start<< " seconds" << endl;
}

// this is how we get Instance of Robot.( Only one Instance of robot object exists )
Robot* Robot::getInstance() {
    static Robot* Instance_;
    if(Instance_){
        cout << "Robot was already on"<< endl;
        return Instance_;
    }else{
        Instance_ = new Robot;
        cout << "Robot ready"<< endl;
        return Instance_;
    }
}
