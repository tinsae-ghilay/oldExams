//
// Created by tgk on 5/14/24.
//

#include "factory.h"
# include <iostream>
# include "machine.h"
# include "FactoryException.h"
# include <unistd.h>

// Fügt eine neue Maschine hinzu. Der Rückgabewert ist
//eine ID, die die jeweilige Maschine eindeutig identifiziert.
unsigned int Factory::addMachine(Machine* m){

    m->setFactory(this);
    this->mId++;
    this->machines[this->mId] = unique_ptr<Machine>(m);
    return this->mId;
}
// Gibt die Maschine mit der angegebenen ID zurück.
Machine* Factory::getMachine(unsigned int id){

    if(this->machines.at(id)){
        return this->machines.at(id).get();
    }else{
        // throw some exception or return nullptr
        std::cout<<"Machine doesnt exist exist";
        return nullptr;
    }
}

// Entfernt die Maschine mit der angegebenen ID und gibt
//alle damit verbundenen Ressourcen wieder frei.
void Factory::deleteMachine(unsigned int id){

    if(this->machines.at(id)){
        this->machines.erase(id);
        std::cout<<"Machine "<<id<<" deleted Successfully" << std::endl;
    }else{
        // throw some exception or return nullptr
        std::cout<<"Machine doesnt exist"<< std::endl;
    }
}

// Übergibt ein neues Produkt der Fabrik. Die Fabrik muss
// dann den Typ des Produkts bestimmen und in das entsprechende Lager einsortieren. Wenn ein
// unbekanntes Produkt übergeben wird, dann soll eine MachineFailureException geworfen werden.
void Factory::addProduct(Product* p){
    if(p){
        auto v = unique_ptr<Product>(p);
        this->products[this->id_] = std::move(v);
        this->id_++;
    }else{
        // throw an error
        throw FactoryException("Invalide product provided");
    }
}

// ibt die Anzahl der im Lager vorhandenen Produkte A zurück.
unsigned int Factory::getProductACount(){
    int c = 0;
    for( const auto&[key,val]:this->products){
        if(val->getType()==1){
            c++;
        }
    }
    return c;
}

// Gibt die Anzahl der im Lager vorhandenen Produkte B zurück.
unsigned int Factory::getProductBCount(){
    int c = 0;
    for( const auto&[key,val]:this->products){
        if(val->getType()==2){
            c++;
        }
    }
    return c;
}

// Diese Methode implementiert die Zeitschleife.
// Der Eingabeparameter iterations gibt an, nach wie vielen Iterationen die Zeitschleife abgebrochen
// werden soll (0 bedeutet, dass die Schleife nie abgebrochen wird).
void Factory::run(unsigned int iterations){

    // 0 bedeutet, dass die Schleife nie abgebrochen wird
    // I will assume that by this, it means it will continue the loop for the highest possible unsigned int value
    // decrementing iteration by 1 pre execution
    // will make iteration have the highest unsigned int value(4294967295) if it is 0 at the beginning

    while(--iterations){

        // we iterate over all available machines
        for(auto & machine : this->machines){
            try{
                sleep(1);
                machine.second->tick();
                std::cout <<"Machine "<< machine.first << " working and factory has now "<<this->getProductACount()<<" product A and "<< this->getProductBCount()<<" product B's "<<std::endl;
            }catch (MachineFailureException &e){
                std::cout << "Exception caught " << e.what()<<std::endl;
            }catch (MachineExplosionException &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
                this->deleteMachine(machine.first);

                // IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!
                // break here very important: without it, we have a segmentation fault!! on long loops
                break;
            }
        }
        if(this->machines.empty()){
            std::cout <<"Factory run out of Machines: Closing shop."<<std::endl;
            break;
        }
    }
    std::cout<<std::endl <<"*** Factory simulation ended Bye. ***"<<std::endl<<std::endl;;
}



