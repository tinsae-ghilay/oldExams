//
// Created by tgk on 5/14/24.
//

# include "machine.h"
# include "product.h"
# include <random>
# include "FactoryException.h"

Machine::~Machine() = default;
void Machine::tick(){};
/*
 * Damit eine Maschine ein neu erstelltes Produkt der Fabrik
 * mithilfe der Methode addProdukt() übergeben kann, benötigt die Maschine eine Referenz auf
 * die Fabrik. Mithilfe dieser Methode kann die entsprechende Referenz der Maschine in
 * der addMachine()-Methode übergeben werden.
 */
void Machine::setFactory(Factory* f)
{
    this->factory = f;
}

/*
 * MachineProductA:
 * Produziert pro Zeitschritt 2 Einheiten von Produkt A.
 * Hat eine 15 % Wahrscheinlichkeit eine MachineFailureException zu werfen.
 * Hat eine 2 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */
void MachineProductA::tick()
{
    int rnd = getRandom();//int rnd = (int)random()%100;
    if(rnd < 15){ // 15 % Wahrscheinlichkeit eine MachineFailureException zu werfen.

        // throw MachineFailureException
        throw MachineFailureException("Machine Product A: Failure!");

    }else if(rnd > 97){ // 2 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.

        // throw MachineExplosionException
        throw MachineExplosionException("Machine Product A: Exploded!");

    }else{

        // Produziert pro Zeitschritt 2 Einheiten von Produkt A.
        for(int i = 0; i< 2; i++){

            // dann produkte zu der Fabrik mithilfe der addProduct()-Methode übergeben
            this->factory->addProduct(new ProductA());
        }
    }
}

/*
 * MachineProductB
 * produziert pro Zeitschritt 3 Einheiten von Produkt B.
 * Hat eine 20 % Wahrscheinlichkeit eine MachineFailureException zu werfen.
 * Hat eine 5 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */
void MachineProductB::tick()
{
    int rnd = getRandom();//(int)random()%100;
    if(rnd < 20){ // 20 % Wahrscheinlichkeit eine MachineFailureException zu werfen.

        // throw MachineFailureException
        throw MachineFailureException("Machine Product B: Failure!");

    }else if(rnd > 94){ // 5 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.

        // throw MachineExplosionException
        throw MachineExplosionException("Machine Product A: Exploded!");
    }else{

        // Produziert pro Zeitschritt 3 Einheiten von Produkt B.
        for(int i = 0; i< 3; i++){

            // dann produkte zu der Fabrik mithilfe der addProduct()-Methode übergeben
            this->factory->addProduct(new ProductB());
        }
    }
}

// generates a random number from a uniform distribution
// more about this at https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

int Machine::getRandom()
{
    random_device device;
    mt19937 range(device());
    uniform_int_distribution <mt19937::result_type> dist(0, 100);
    return (int)dist(range);
}