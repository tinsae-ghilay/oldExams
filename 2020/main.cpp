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
    Elephant elephant = Elephant(400);
    elephant.feed(m);
    elephant.feed(f);
    elephant.feed(b);
}