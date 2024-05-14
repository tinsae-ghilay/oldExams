//
// Created by tgk on 5/14/24.
//
# include <iostream>
# include "factory.h"






int main(){


    auto f = new Factory();
    for(int i = 0; i < 3; i++){
        f->addMachine(new MachineProductA());
        f->addMachine(new MachineProductB());
    }
    f->run(4);
}