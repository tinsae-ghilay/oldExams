#ifndef FOOD_H
#define FOOD_H
#include <string>

using namespace std;
class Food{
protected:
    string typ = "food";
public:
    Food();
    virtual ~Food();
    virtual double getCalories();
    string getType()const;
};

Food::Food() =default;
Food::~Food() {};

string Food::getType() const {
    return  this->typ;
}

double Food::getCalories() {
    return 0;
}


#endif//FOOD_H