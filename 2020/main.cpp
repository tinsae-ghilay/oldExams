//
// Created by tgk on 4/23/24.
//
# include <iostream>
# include "Zoo.h"


using namespace std;
int main(){

    // creating animal instances
    auto elephant = new Elephant(800);

    // test Badger
    auto b = new Badger(10);

    // test Tiger
    auto t = new Tiger(180);

    // test Badger
    auto p = new Panda(200);
    auto  e = new Elephant(850);


    // zoo, three foods and three animals
    Zoo zoo = Zoo();
    // adding food to zoo storage
    zoo.addFood(make_unique<Meat>(0.50));
    zoo.addFood(make_unique<Grass>(3));
    zoo.addFood(make_unique<Grass>(6));
    zoo.addFood(make_unique<Bamboo>(100.0,10));
    zoo.addFood(make_unique<Meat>(5.0));

    // adding animals to zoo
    zoo.addAnimal(elephant);
    zoo.addAnimal(b);
    zoo.addAnimal(t);
    zoo.addAnimal(p);
    zoo.addAnimal(e);
    // feed animals.
    zoo.feedingTime();

    cout << "Zoo has "<< zoo.herdCount()<<" animals"<< endl;
    cout << "heaviest Carnivore  in zoo is "<< zoo.getHeaviestCarnivore()->getSpecies()<< endl;
    cout << "heaviest Herbivore  in zoo is "<< zoo.getHeaviestHerbivore()->getSpecies()<< endl;

    // TODO( have to make getType a virtual function)

    return 0;
}