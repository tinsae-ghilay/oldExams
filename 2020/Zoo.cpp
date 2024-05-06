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

    for(auto animal: *this){
        for(size_t i = 0; i < this->storage.size(); i++){
            try {
                int sat = animal->feed(*this->storage[i]);
                if(sat){
                    break;
                }
            }catch (ZooException& e){
                cout << e.what()<<endl;
            }
        }
        cout <<"All animals have been fed for now"<<endl;
    }
}

// to avoid repeating code below (see line 45+) for carnivore and herbivore
// I am using template here. to make this polymorphic
template<class T>
Animal* Zoo::getHeaviest(){
    int index = -1;
    cout << ", getting heaviest....";
    for(size_t i =0; i < this->size();i++){
        //cout << " looking at ... "<<this->at(i)->getSpecies();
        if(dynamic_cast<T*>(this->at(i))){ // animal is of the requested order
            cout << " looking at -> "<<this->at(i)->getSpecies()<< " weighing " <<this->at(i)->getWeight()<<" Kgs";
            if(index < 0){ // our first animal of the requested order.
                index = (int)i;
            }else if(this->at(i)->getWeight() > this->at(index)->getWeight()){
                index = (int)i;
            }
        }
    }
    if(index >= 0){ // we have carnivores and heaviest one at that
        cout <<" found heaviest "<< this->getAnimal(index)->getOrder()<<" = ";
        return this->at(index);
    }else{ // no animals of order T( can be carnivores or Herbivores
        cout << "Didn't find any animal in that criteria"<<endl;
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

void Zoo::addFood(unique_ptr<Food> food) {

    this->storage.push_back(std::move(food));

}
