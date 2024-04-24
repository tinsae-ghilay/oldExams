//
// Created by tgk on 4/23/24.
//

#ifndef ANIMAL_H
#define ANIMAL_H

# include <string>
# include "Plant.h" // will this work while we also use Food?
# include <memory>
# include <iostream>



using namespace  std;

// Parent class animal
class  Animal{
private:
    float weight;
protected:
    string order;
    string species;
    void satisfy(double cal);
public:
    explicit Animal(float weight);
    virtual ~Animal();
    int feed(Food& food);
    virtual bool canEat(Food& food) = 0;
    string getOrder() const;
    string getSpecies() const;
    float getWeight() const;
};
Animal::Animal(float weight){
    this->weight = weight;
};

void Animal::satisfy(double cal) {
    this->weight+=(float)(cal/this->weight);
}

float Animal::getWeight() const {
    return this->weight;
}

string Animal::getSpecies() const {
    return this->species;
}

string Animal::getOrder() const {
    return this->order;
}

// writing this here and adding a boolean to override dynamically
// so that I don't have to rewrite this code. should be the same for any animal.
// although all have different food efficiencies.
// instead I am overriding canEat() function to return boolean and control what object can consume.
int Animal::feed(Food &food) {
    if(this->canEat(food)){
        float w = this->getWeight();
        this->satisfy(food.getCalories());
        float w2 = this->getWeight();
        cout << this->getSpecies()<<" liked the "<<food.getType()<<", ate it and gained "<< w2-w<< " KGs" << endl;
        return 1;
    }else{

        cout << this->getSpecies()<<" doesn't like "<<food.getType() << endl;
        return 0;
    }
}

Animal::~Animal() = default;

// carnivores
class Carnivorous: public Animal{


public:
    explicit Carnivorous(float weight);

};

Carnivorous::Carnivorous(float weight) : Animal(weight) {


    this->order = "Carnivorous";
}

// herbivores
class Herbivorous: public Animal{

private:


public:
    explicit Herbivorous(float weight);

};

Herbivorous::Herbivorous(float weight) : Animal(weight) {
this->order = "Herbivorous";
}

// elephant
class Elephant: public Herbivorous{
private:
public:
    explicit  Elephant(float weight);
    ~Elephant() override;
    bool canEat(Food &food) override;
};


Elephant::Elephant(float weight) : Herbivorous(weight) {
    this->species = "Elephant";
}

bool Elephant::canEat(Food &food) { // can eat any plant
    return dynamic_cast<Plant*>(&food);;
}


Elephant::~Elephant() =default;

class Panda: public Herbivorous{
private:
public:
    explicit  Panda(float weight);
    ~Panda() override;
    bool canEat(Food &food) override;
};


// Panda
Panda::Panda(float weight) : Herbivorous(weight) {
    this->species = "Panda";
}

bool Panda::canEat(Food &food) { // can eat bamboo only
    return dynamic_cast<Bamboo*>(&food);
}


Panda::~Panda() =default;

class Tiger: public Carnivorous{
private:
public:
    explicit  Tiger(float weight);
    ~Tiger() override;
    bool canEat(Food &food) override;
};

// Tiger
Tiger::Tiger(float weight) : Carnivorous(weight) {
    this->species = "Tiger";
}

bool Tiger::canEat(Food &food) { // can eat bamboo only
    return dynamic_cast<Meat*>(&food);
}

Tiger::~Tiger() = default;


// Badger
class Badger: public Carnivorous{
private:
public:
    explicit  Badger(float weight);
    ~Badger() override;
    bool canEat(Food &food) override;
};


Badger::Badger(float weight) : Carnivorous(weight) {
    this->species = "Badger";
}

bool Badger::canEat(Food &food) { // can eat meat or grass
    return dynamic_cast<Meat*>(&food) || dynamic_cast<Grass*>(&food);
}


Badger::~Badger() =default;


#endif //ANIMAL_H
