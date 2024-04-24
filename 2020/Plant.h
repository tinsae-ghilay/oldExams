//
// Created by tgk on 4/23/24.
//

#ifndef PLANT_H
#define PLANT_H
# include "Food.h"
# include <string>

using namespace std;

// Plant object, itself an abstract class.
// inherited from food
// doesn't override anything, so it stays **abstract**
class Plant :public Food{

protected:
    string plant_typ;
public:
    Plant();
    string getPlantTyp() const;

};


Plant::Plant() :Food(){
    this->typ = "Plant";
}

string Plant::getPlantTyp() const {
    return  this->plant_typ;
}



// Bamboo Plant
// inherited from Plant
// overrides all virtual functions from Food
class Bamboo: public Plant{
private:
    double length;
    int amount;

public:
    Bamboo(double length, int amount);
    ~Bamboo() override;
    double getLength() const;
    int getAmount() const;

    double getCalories() override;
};

Bamboo::Bamboo(double length, int amount){
    this->amount = amount;
    this->length = length;
    this->plant_typ = "Bamboo";
}
int Bamboo::getAmount() const {
    return this->amount;
}

double Bamboo::getLength() const {
    return this->length;
}

// I will assume bamboo shoots are 2 cm in diameter.
double Bamboo::getCalories() {
    return this->length*3.1415*amount*27;
}

Bamboo::~Bamboo() = default;

// Grass object
// inherited from Plant
// overrides all virtual functions from Food
class  Grass: public Plant{
private:
    int bundles;
public:
    explicit Grass(int bundle);
    ~Grass() override;
    int getBundles() const;
    double getCalories() override;
};


Grass::Grass(int bundle) {
    this->plant_typ = "Grass";
    this->bundles = bundle;
}

int Grass::getBundles() const {
    return this->bundles;
}

double Grass::getCalories() {
    return this->bundles * 33.0;
}

Grass::~Grass() =default;

#endif //PLANT_H
