//
// Created by tgk on 4/23/24.
//
# include <iostream>
# include "Zoo.h"


using namespace std;
int main(){
    Grass f = Grass(3);
    cout << f.getBundles() << " bundles of "<< f.getType() << " has "<<f.getCalories()<<" calories" <<endl;
    Bamboo b = Bamboo(1.00,10);
    cout << b.getAmount()<<" pieces of"<< b.getType() << " has "<<b.getCalories()<<" calories" <<endl;
    Meat m = Meat(1.0);
    cout << m.getWeight()<<" Kilos of "<< m.getType() << " has "<<m.getCalories()<<" calories" <<endl;

    // test elephant
    Elephant elephant = Elephant(400);
    elephant.feed(m); // cannot eat meat
    elephant.feed(f); // can eat grass
    //elephant.feed(b); // can eat bamboo

    // test Badger
    Badger bg = Badger(10);
    bg.feed(m); // can eat meat
    bg.feed(b); // cannot eat Bamboo
    bg.feed(f); // can eat grass

    // test Tiger
    Tiger t = Tiger(180);
    t.feed(m); // can eat meat
    t.feed(b); // cannot eat Bamboo
    t.feed(f); // cannot eat grass

    // test Badger
    Panda p = Panda(200);
    p.feed(m); // cannot eat meat
    p.feed(b); // can eat Bamboo
    p.feed(f); // cannot eat grass

    Zoo zoo = Zoo();
    zoo.addAnimal(&elephant);
    zoo.addAnimal(&bg);
    zoo.addAnimal(&t);
    zoo.addAnimal(&p);

    cout << "Zoo has "<< zoo.herdCount()<< " animals now and the second(1) is "<< zoo.getAnimal(1)->getSpecies()<< endl;
    zoo.deleteAnimal(1);
    cout << "Zoo has "<< zoo.herdCount()<< " animals now and the second(1) is "<< zoo.getAnimal(1)->getSpecies()<< endl;
    cout << "heaviest Carnivore  in zoo is "<< zoo.getHeaviestCarnivore()->getSpecies()<< endl;
    cout << "heaviest Herbivore  in zoo is "<< zoo.getHeaviestHerbivore()->getSpecies()<< endl;

    // TODO( have to make getType a virtual function)

    return 0;

}