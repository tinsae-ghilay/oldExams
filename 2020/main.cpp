//
// Created by tgk on 4/23/24.
//
# include <iostream>
# include "Zoo.h"
# include <memory>


using namespace std;
int main(){

    // creating animal instances
    Elephant elephant = Elephant(800);

    // test Badger
    Badger b = Badger(10);

    // test Tiger
    Tiger t = Tiger(180);

    // test Badger
    Panda p = Panda(200);
    Elephant e = Elephant(850);

    // zoo, three foods and three animals
    Zoo zoo = Zoo();
    // adding food to zoo storage

    // adding animals to zoo
    zoo.addAnimal(&elephant);
    zoo.addAnimal(&b);
    zoo.addAnimal(&t);
    zoo.addAnimal(&p);
    zoo.addAnimal(&e);
    // feed animals.
    zoo.feedingTime();

    cout << "Zoo has "<< zoo.herdCount()<<" animals"<< endl;
    cout << "heaviest Carnivore  in zoo is "<< zoo.getHeaviestCarnivore()->getSpecies()<< endl;
    cout << "heaviest Herbivore  in zoo is "<< zoo.getHeaviestHerbivore()->getSpecies()<< endl;

    // TODO( have to make getType a virtual function)

    return 0;
}