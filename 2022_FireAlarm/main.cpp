//
// Created by tgk on 5/12/24.
//
#include "Building.h"


int main(){

    int floor = 10;
    auto building = new Building(floor);
    cout << "installing sensors";
    for(int i = 0; i < floor;i++){
        // adding sensors to building. building will handle their lifecycle
        try{ // in case creating pointers on heap gives us exception
            building->addSensor(i,new SmokeDetector());
            building->addSensor(i,new InfraredSensor());
            building->addSensor(i,new InfraredSensor());
            building->addSensor(i,new SmokeDetector());
        }catch(...){
            cout << "error while installing sensors to building"<<endl;
        }
    }

    int i = 0;
    while(i < 20){
        sleep(1);
        try{
            building->checkSensors();
            cout << "Sensors report : OK."<<endl;
        }catch(FireDetectedException& e){
            // sirens have been turned on automatically by building.
            // the program should do that by itself
            // thus, Sirens are encapsulated as Private
            for(int l = 3; l > 0; i++ && --l){
                cout <<"\r"<< "Sirens on for "<< l << " seconds "<< flush;
                sleep(1);
            }
            cout << endl;
            building->cancelAlarm();
        }catch(ErrorDetectedException& e){

            cout << e.what()<< endl;
        }



        i++;
    }
    try {
        cout << "getting sensor :"<< building->getSensor(200,10)->getType() << endl;
    }catch(FireAlarmException& e){
        cout <<e.what() <<endl;
    }
    delete building;
    return 0;

}