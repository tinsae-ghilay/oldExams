//
// Created by tgk on 4/23/24.
//

#ifndef PLANT_H
#define PLANT_H


# include "Food.h"

using namespace std;

// Plant object, itself an abstract class.
// inherited from food
// doesn't override anything, so it stays **abstract**
class Plant :public Food{

protected:
public:
    Plant();

};


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
    string getType() const;
};


#endif //PLANT_H
