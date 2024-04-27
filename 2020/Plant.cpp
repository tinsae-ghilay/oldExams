//
// Created by tgk on 4/27/24.
//
# include "Plant.h"


Plant::Plant() :Food(){
    this->typ = "Plant";
}

// Bamboo

Bamboo::Bamboo(double length, int amount){
    this->amount = amount;
    this->length = length;
    this->typ = "Bamboo";
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


// Grass

Grass::Grass(int bundle) {
    this->typ = "Grass";
    this->bundles = bundle;
}

int Grass::getBundles() const {
    return this->bundles;
}

double Grass::getCalories() {
    return this->bundles * 33.0;
}

string Grass::getType() const {
    return this->typ;
}

Grass::~Grass() =default;