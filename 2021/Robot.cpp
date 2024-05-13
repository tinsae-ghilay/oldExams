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

// deletes sensor by id
void Robot::deleteSensor(int id){
    auto ssr = this->sensors.find(id);
    if(ssr!= this->sensors.end()){
        this->sensors.erase(ssr);
    }else{
        // throw some error
        throw RobotException("Provided Id doesn't belong to available sensors.");
    }
}


/*
 * Die 'Event-Loop' Comments are from the ex. sheet in Jupyter
 */
void Robot::eventLoop(){
    int i = 0;
    time_t start = time(nullptr);

    while(i < 30){

        int state = 0;
        sleep(1); // sleep for one sec on every iteration.
        for (const auto& [key,sensor]: this->sensors){ // will check all sensors
            try {

                // fragt ständig in einer (Pseudo)Endlosschleife den Status der Sensoren ab.
                // Die Rückgabewerte der Sensoren sind eine Zahl zwischen 0 und 100,
                int s_state = sensor->checkSensor();

                // Nachdem alle Sensoren abgefragt wurden, wird der höchste gemeldete Gefahrenlevel verwendet,
                // um die Geschwindigkeit des Motors zu setzen. (sehe unten)
                if (s_state > state) {
                    state = s_state;
                }

                // reset() wird für jeden fehlerhaften Sensor nur einmal pro Iteration ausgeführt
                if (sensor->getErrorState()) {
                    cout << "Resetting : ";
                    // reset motor
                    sensor->reset();
                    state = 0;
                }
            }
            /*
             * Wenn einer der Sensoren eine InternalErrorException wirft,
             * dann soll aus Sicherheitsgründen auf die niedrigste Geschwindigkeit geschaltet werden.
             * Die niedrigste Geschwindigkeit soll so lange aufrechterhalten werden,
             * bis der Sensor erfolgreich mit reset() zurückgesetzt werden konnte. → sehe oben.
             * bei Geschwindigkeitsreduktion aufgrund interner Sensorfehler
             * kann es aber immer noch zur Notabschaltung aufgrund kritischer Gefahr kommen!
             */
            catch(InternalErrorException& e){
                cout << e.what() <<endl;
                state = 100; // gefahr = 100 wird auf niedriger geschwindigkeit wirken.
            }
            /*
             * Wenn ein Sensor eine CriticalDangerException wirft, dann soll sofort
             * (d.h. das Abfragen der weiteren Sensoren wird an dieser Stelle unterbrochen)
             * ein Notstopp der Motoren eingeleitet werden. Nach 3 Iterationen der Event-Loop
             * soll dann wieder zum Normalzustand zurückgekehrt werden.
             */
            catch(CriticalDangerException& e){

                // stop motor- >speed to 0.
                cout<<"EMERGENCY STOP!!! ";
                this->motor->emergencyBreak();
                cout << e.what()<<endl;

                // 3 Iterationen der Event-Loop -> implemented here internally by updating i
                for(int ii = 0; ii < 3; ii++ && i++){
                    cout << "current speed = "<< this->motor->getSpeed() << " RPM"<< endl;
                    sleep(1);// because here, iteration will be incremented (by incrementing i too)
                }
                // Nach 3 Iterationen der Event-Loop, soll dann wieder zum Normalzustand zurückgekehrt werden.
                state = 0; // null gefahr wirkt an hoch geschwindigkeit.
                // Abfragen der weiteren Sensoren wird an dieser Stelle unterbrochen.
                break;
            }

        }
        // je nach Schwere der entdeckten Gefahr (0 bedeutet keine Gefahr und 100 bedeutet sehr große Gefahr).
        // der höchste gemeldete Gefahrenlevel wird verwendet, um die Geschwindigkeit des Motors zu setzen.
        float factor = 1 - (float) state / 100;
        int speed = (int)((factor * Motor::MAX_SPEED) + Motor::MIN_SPEED);
        this->motor->setSpeed(speed);
        cout << "current speed = "<< this->motor->getSpeed() << " RPM"<< endl;
        i++;
    }
    // ending test
    this->motor->setSpeed(0);
    time_t end = time(nullptr);

    cout << "Test done in "<<end-start<< " seconds" << endl;
}


// this is how we get Instance of Robot.( Only one Instance of robot object exists )
// @see  Motor::getInstance();
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
