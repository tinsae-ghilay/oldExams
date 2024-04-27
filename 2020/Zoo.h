//
// Created by tgk on 4/27/24.

// declaration of the class Zoo:
// Zoo class extends Vector container and makes use of its built-in functions
// in fact many of the functions here just implement the default algorithm of Vector.
// they are here just because they are specified.
// so to prevent using vector functions for the Zoo class we will extend it as private
// and use specified functions for accessing values.
#ifndef ZOO_H
#define ZOO_H

# include <vector>
# include "Animal.h"

// Zoo is a custom vector<Animal> container.
class Zoo : vector<Animal*> {
private:
    // returns pointer to the heaviest animal of class type <T>
    template<class T>
    Animal* getHeaviest();
public:
    ~Zoo();

    // adds an animal
   int addAnimal(Animal *animal);

   // reference to animal at index
   Animal* getAnimal(int index);

   // delet an animal from Zoo
   void deleteAnimal(int index);

   // feeding time -- don't know what I am supposed to do here
   void feedingTime();

   // returns pointer to heaviest carnivore
   Animal* getHeaviestCarnivore();

    // returns pointer to heaviest Herbivore
   Animal* getHeaviestHerbivore();

   // returns the number of animal the zoo has
   size_t herdCount();

};


#endif //ZOO_H
