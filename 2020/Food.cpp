//
// Created by tgk on 4/27/24.
//

# include "Food.h"


Food::Food() =default;
Food::~Food() = default;

string Food::getType() const {
    return  this->typ;
}

double Food::getCalories() {
    return 0;
}

// meat

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

bool Food::isConsumed() const {
    return this->isConsumed_;
}

void Food::setStatus(bool status) {
    this->isConsumed_ = status;
}
