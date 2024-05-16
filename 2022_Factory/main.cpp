//
// Created by tgk on 5/14/24.
//
# include <iostream>
# include "factory.h"






int main(){


    // creating Factory
    auto f = new Factory();
    for(int i = 0; i < 2; i++){
        f->addMachine(new MachineProductA());
        f->addMachine(new MachineProductB());
    }
    // runs for ten iterations
    f->run(10);

    // delete when done
    delete f;
}