//
// Created by tgk on 4/23/24.
//

#ifndef MEAT_H
#define MEAT_H

# include <string>
# include "Food.h"



using namespace std;

class Meat: public Food{

private:
    double  weight;
public:
    Meat(double weight);
    ~Meat() override;
    double getWeight() const;

    double getCalories() override;
};

Meat::Meat(double weight) {
    this->typ = "Meat";
    this->weight = weight;
}


Meat::~Meat() = default;

double Meat::getWeight() const {
    return this->weight;
}

double Meat::getCalories() {
    return this->weight*10 * 143.5;
}


#endif //MEAT_H
