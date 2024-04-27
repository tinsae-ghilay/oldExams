//
// Created by tgk on 4/27/24.
//

#ifndef OLDEXAMS_ZOO_H
#define OLDEXAMS_ZOO_H

# include <vector>
# include "Animal.h"


class Zoo : public vector<Animal*> {
private:
    template<class T>
    Animal* getHeaviest();
public:
    ~Zoo();
   int addAnimal(Animal *animal);

   Animal* getAnimal(int index);

   void deleteAnimal(int index);

   void feedingTime();

   Animal* getHeaviestCarnivore();

   Animal* getHeaviestHerbivore();

};


#endif //OLDEXAMS_ZOO_H
