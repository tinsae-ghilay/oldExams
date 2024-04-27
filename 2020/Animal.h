//
// Created by tgk on 4/23/24.
//

#ifndef ANIMAL_H
#define ANIMAL_H

# include "Food.h"
# include "Plant.h"
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
    virtual bool canEat(Food& food);
    string getOrder() const;
    string getSpecies() const;
    float getWeight() const;
};

// carnivores
class Carnivorous: public Animal{


public:
    explicit Carnivorous(float weight);

};


// herbivores
class Herbivorous: public Animal{

private:


public:
    explicit Herbivorous(float weight);

};

// elephant
class Elephant: public Herbivorous{
private:
public:
    explicit  Elephant(float weight);
    ~Elephant() override;
    bool canEat(Food &food) override;
};


class Panda: public Herbivorous{
private:
public:
    explicit  Panda(float weight);
    ~Panda() override;
    bool canEat(Food &food) override;
};


class Tiger: public Carnivorous{
private:
public:
    explicit  Tiger(float weight);
    ~Tiger() override;
    bool canEat(Food &food) override;
};

// Badger
class Badger: public Carnivorous{
private:
public:
    explicit  Badger(float weight);
    ~Badger() override;
    bool canEat(Food &food) override;
};


#endif //ANIMAL_H
