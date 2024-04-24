//
// Created by tgk on 4/23/24.
//
#include "Plant.h"
# include "Meat.h"
# include <iostream>
# include "Animal.h"


using namespace std;
int main(){
    Grass f = Grass(3);
    cout << f.getBundles() << " bundles of "<< f.getPlantTyp() << " has "<<f.getCalories()<<" calories" <<endl;
    Bamboo b = Bamboo(1.00,10);
    cout << b.getAmount()<<" pieces of"<< b.getPlantTyp() << " has "<<b.getCalories()<<" calories" <<endl;
    Meat m = Meat(1.0);
    cout << m.getWeight()<<" Kilos of "<< m.getType() << " has "<<m.getCalories()<<" calories" <<endl;

    // test elephant
    Elephant elephant = Elephant(400);
    elephant.feed(m); // cannot eat meat
    elephant.feed(f); // can eat grass
    elephant.feed(b); // can eat bamboo

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


}