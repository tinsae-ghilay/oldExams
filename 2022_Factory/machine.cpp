//
// Created by tgk on 5/14/24.
//

# include "machine.h"
# include "product.h"
# include <random>
# include <memory>
# include "FactoryException.h"

Machine::Machine() = default;
Machine::~Machine() = default;
void Machine::tick(){};
/*
 * Damit eine Maschine ein neu erstelltes Produkt der Fabrik
 * mithilfe der Methode addProdukt() übergeben kann, benötigt die Maschine eine Referenz auf
 * die Fabrik. Mithilfe dieser Methode kann die entsprechende Referenz der Maschine in
 * der addMachine()-Methode übergeben werden.
 */
void Machine::setFactory(Factory* f){
    this->factory = f;
};

/*
Es gibt zwei konkrete Maschinen:
•MachineProductA:
▪ Produziert pro Zeitschritt 2 Einheiten von Produkt A.
▪ Hat eine 15 % Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 2 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */
void MachineProductA::tick(){
    int rnd = random()%100;
    if(rnd < 15){

        // throw MachineFailureException
        throw MachineFailureException("Machine Product A: Failure!");

    }else if(rnd > 97){

        // throw MachineExplosionException
        throw MachineExplosionException("Machine Product A: Exploded!");
    }else{

        for(int i = 0; i< 3; i++){
            this->factory->addProduct(new ProductA());
        }

    }

}

/*
•MachineProductB
▪ Produziert pro Zeitschritt 3 Einheiten von Produkt B.
▪ Hat eine 20 % Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 5 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.
*/
void MachineProductB::tick(){
    int rnd = random()%100;
    if(rnd < 20){

        // throw MachineFailureException
        throw MachineFailureException("Machine Product B: Failure!");

    }else if(rnd > 94){

        // throw MachineExplosionException
        throw MachineExplosionException("Machine Product A: Exploded!");
    }else{

        for(int i = 0; i< 3; i++){
            this->factory->addProduct(new ProductB());
        }

    }

}