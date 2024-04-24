//
// Created by tgk on 4/23/24.
//

#ifndef ANIMAL_H
#define ANIMAL_H

# include <string>
# include "Plant.h" // will this work while we also use Food?
# include <stdexcept> // may be override it later
# include <memory>
# include <iostream>



using namespace  std;

class  Animal{
    friend int feed(Food& food);
private:
    float weight;
    string food;
protected:
    string order;
    string species;
public:
    explicit Animal(float weight);
    virtual ~Animal();
    virtual int feed(Food& food) = 0;

    string getOrder() const;
    string getSpecies() const;
    float getWeight() const;
    string eats() const;

    void satisfy(double cal);
};
Animal::Animal(float weight){
    this->weight = weight;
};

string Animal::eats() const {
    return this->food;
}

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

int feed(Food &food) {
    return 0;
}

Animal::~Animal() = default;


class Carnivorous: public Animal{

private:

    string food  = "Meat";

public:
    explicit Carnivorous(float weight);

};

Carnivorous::Carnivorous(float weight) : Animal(weight) {


    this->order = "Carnivorous";
}


class Herbivorous: public Animal{

private:

    string food  = "Plant";

public:
    explicit Herbivorous(float weight);

};

Herbivorous::Herbivorous(float weight) : Animal(weight) {
this->order = "Herbivorous";
}


class Elephant: public Herbivorous{
private:
    string foods ="Grass, Bamboo";
public:
    explicit  Elephant(float weight);
    ~Elephant() override;
    int feed(Food &food) override;
};

int Elephant::feed(Food &food) {

    try {
        Plant *p = dynamic_cast<Plant*>(&food);
        if(p){
            float w = this->getWeight();
            this->satisfy(p->getCalories());
            float w2 = this->getWeight();
            cout << this->getSpecies()<<" liked the food and gained "<< w2-w<< " KGs" << endl;
            return 1;
        }else{

            cout << this->getSpecies()<<" doesnt like "<<food.getType() << endl;
            return 0;
        }
    }catch(exception &e){
        cout << this->getSpecies()<<" doesnt like "<<food.getType() << endl;
        return 0;
    }
}

Elephant::Elephant(float weight) : Herbivorous(weight) {
    this->species = "Elephant";
}


Elephant::~Elephant() =default;



#endif //ANIMAL_H
