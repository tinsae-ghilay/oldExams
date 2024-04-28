//
// Created by tgk on 4/27/24.
//

#include "Zoo.h"
// add animal at a position

int Zoo::addAnimal(Animal* animal){
    this->push_back(animal);
    return this->size()-1;
};
// get animal at a position
Animal* Zoo::getAnimal(int index){
    return this->at(index);
}
void Zoo::deleteAnimal(int index){ // delete animal from a position
    this->erase(this->begin()+index);
}
void Zoo::feedingTime(){
    cout << "Please feed the animals now. they eat whenever you feed them."<< endl;
}

// to avoid repeating code below (see line 45+) for carnivore and herbivore
// I am using template here. to make this polymorphic
template<class T>
Animal* Zoo::getHeaviest(){
    int index = -1;
    for(size_t i =0; i < this->size();i++){
        if(dynamic_cast<T*>(this->at(i))){ // animal is of the requested order
            if(index == -1){ // our first animal of the requested order.
                index = (int)i;
            }else if(this->at(i)->getWeight() > this->at(index)->getWeight()){
                index = (int)i;
            }
        }
    }
    if(index !=-1){ // we have carnivores and heaviest one at that
        return this->at(index);
    }else{ // no animals of order T( can be carnivores or Herbivores
        return nullptr;
    }
}

// get heaviest carnivore
Animal* Zoo::getHeaviestCarnivore(){
    return this->getHeaviest<Carnivorous>();
}

// get heaviest Herbivore
Animal* Zoo::getHeaviestHerbivore(){
    return this->getHeaviest<Herbivorous>();
}

// destructor, here we can clean up heap
Zoo::~Zoo() {

    cout << "Zoo has been closed."<<endl;
    // if objects have been created on Heap, they have to be deleted here.

}

size_t Zoo::herdCount() {
    return this->size();
}
