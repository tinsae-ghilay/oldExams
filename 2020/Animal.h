//
// Created by tgk on 4/23/24.
// declares abstract class Animal and all its child classes.
// contains child classes Carnivores, Herbivores, Panda, Elephant and Tiger all are here
//

#ifndef ANIMAL_H
#define ANIMAL_H

# include "Food.h"
# include "Plant.h"
# include <iostream>



using namespace  std;

// Parent class animal
// declares Parent class Animal
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
    virtual bool canEat(Food& food);
    string getOrder() const;
    string getSpecies() const;
    float getWeight() const;
};

// declaration
// carnivores child class of Animal
class Carnivorous: public Animal{


public:
    explicit Carnivorous(float weight);

};

// declaration
// herbivores child class of Animal
class Herbivorous: public Animal{

private:


public:
    explicit Herbivorous(float weight);

};
// declaration
// elephant, inherits from Herbivores
class Elephant: public Herbivorous{
private:
public:
    explicit  Elephant(float weight);
    ~Elephant() override;
    bool canEat(Food &food) override;
};

// declaration
// Panda , inherits from Herbivores
class Panda: public Herbivorous{
private:
public:
    explicit  Panda(float weight);
    ~Panda() override;
    bool canEat(Food &food) override;
};

// declaration
// Tiger, inherits from Carnivores
class Tiger: public Carnivorous{
private:
public:
    explicit  Tiger(float weight);
    ~Tiger() override;
    bool canEat(Food &food) override;
};

// declaration
// Badger, inherits from Carnivores
class Badger: public Carnivorous{
private:
public:
    explicit  Badger(float weight);
    ~Badger() override;
    bool canEat(Food &food) override;
};


#endif //ANIMAL_H
