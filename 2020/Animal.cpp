//
// Created by tgk on 4/27/24.

// definitions of Animal
// definition of all, subclasses of the superclass animal here.
//
# include "Animal.h"

// definitions of Animal
Animal::Animal(float weight){
    this->weight = weight;
}
// adds weight to animal depending on food's calorie count
void Animal::satisfy(double cal) {
    this->weight+=(float)(cal/this->weight);
}

// getter for weight
float Animal::getWeight() const {
    return this->weight;
}

// getter for animal species
string Animal::getSpecies() const {
    return this->species;
}

// getter for order of an animal
string Animal::getOrder() const {
    return this->order;
}

// determines if an animal can eat a given foor
bool Animal::canEat(Food &food) {
    return false;
}

// writing this here and adding a boolean to override dynamically
// so that I don't have to rewrite this code. should be the same for any animal.
// although all have different food efficiencies.
// instead I am overriding canEat() function to return boolean and control what object can consume.
int Animal::feed(Food &food) {
    if(food.isConsumed()){ /* food has been eaten by another animal */
        cout << "Nothing to eat. Food has been already consumed" << endl;
        return 0;
    }
    if(this->canEat(food)){ /* animal can eat provided food */

        float w = this->getWeight(); // not necessary. Just here for seeing weight difference.
        this->satisfy(food.getCalories());
        float w2 = this->getWeight();
        cout << this->getSpecies()<<" liked the "<<food.getType()<<", ate it and gained "<< w2-w<< " KGs" << endl;
        food.setStatus(true); // set food as eaten
        return 1; // return
    }else{ /* animal cannot eat food */

        cout << this->getSpecies()<<" doesn't like "<<food.getType() << endl;
        return 0;
    }
}

Animal::~Animal() = default;


// definition for Carnivore
Carnivorous::Carnivorous(float weight) : Animal(weight) {


    this->order = "Carnivorous";
}

// Herbivore
Herbivorous::Herbivorous(float weight) : Animal(weight) {
    this->order = "Herbivorous";
}

// Elephant


Elephant::Elephant(float weight) : Herbivorous(weight) {
    this->species = "Elephant";
}

bool Elephant::canEat(Food &food) { // can eat any plant
    return dynamic_cast<Plant*>(&food);;
}


Elephant::~Elephant() =default;

// Panda
Panda::Panda(float weight) : Herbivorous(weight) {
    this->species = "Panda";
}

bool Panda::canEat(Food &food) { // can eat only bamboo
    return dynamic_cast<Bamboo*>(&food);
}


Panda::~Panda() =default;

// Tiger
Tiger::Tiger(float weight) : Carnivorous(weight) {
    this->species = "Tiger";
}

bool Tiger::canEat(Food &food) { // can only meat
    return dynamic_cast<Meat*>(&food);
}

Tiger::~Tiger() = default;


// badger


Badger::Badger(float weight) : Carnivorous(weight) {
    this->species = "Badger";
}

bool Badger::canEat(Food &food) { // can eat meat or grass
    return dynamic_cast<Meat*>(&food) || dynamic_cast<Grass*>(&food);
}


Badger::~Badger() =default;