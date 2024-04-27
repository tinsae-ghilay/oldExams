#ifndef FOOD_H
#define FOOD_H
#include <string>

using namespace std;
class Food{
protected:
    string typ = "food";
    bool isConsumed_ = false;
public:
    Food();
    virtual ~Food();
    virtual double getCalories();
    string getType()const;
    bool isConsumed() const;
    void setStatus(bool status);
};


// meat class

class Meat: public Food{

private:
    double  weight;
public:
    Meat(double weight);
    ~Meat() override;
    double getWeight() const;

    double getCalories() override;
};


#endif//FOOD_H