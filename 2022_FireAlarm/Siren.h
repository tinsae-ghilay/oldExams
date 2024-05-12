//
// Created by tgk on 5/12/24.
//

#ifndef SIREN_H
#define SIREN_H

#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
# include <unistd.h>

using namespace std;

// Class repräsentiert eine Sirene
class Siren{
private:
    bool state = false;

public:

    // switches siren on
    // schaltet die Sirene ein (in unserem Fall Ausgabe auf der Konsole).
    inline void switchOn()
    {
        if(!this->state){
            this->state=true;
            cout << "Siren switched On"<<endl;
        }else{
            cout << "Siren already switched On"<<endl;
        }
    }

    // switches siren off
    // schaltet die Sirene aus
    inline void switchOff()
    {
        if(this->state){
            this->state=false;
            cout << "Siren switched Off"<<endl;
        }else{
            cout << "Siren already switched Off"<<endl;
        }
    }
    inline bool isOn(){
        return this->state;
    }
};
#endif //SIREN_H
