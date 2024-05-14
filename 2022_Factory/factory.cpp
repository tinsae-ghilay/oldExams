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
        std::cout<<"Item doesnt exist";
        return nullptr;
    }
}

// Entfernt die Maschine mit der angegebenen ID und gibt
//alle damit verbundenen Ressourcen wieder frei.
void Factory::deleteMachine(unsigned int id){

    if(this->machines.at(id)){
        this->machines.erase(id);
        std::cout<<"Machine deleted Successfully" << std::endl;
    }else{
        // throw some exception or return nullptr
        std::cout<<"Machine doesnt exist"<< std::endl;
    }
}

// Übergibt ein neues Produkt der Fabrik. Die Fabrik muss
// dann den Typ des Produkts bestimmen und in das entsprechende Lager einsortieren. Wenn ein
// unbekanntes Produkt übergeben wird, dann soll eine MachineFailureException geworfen werden.
void Factory::addProduct(Product* p){
    auto v = unique_ptr<Product>(p);
    this->products[this->id_] = std::move(v);
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
//werden soll (0 bedeutet, dass die Schleife nie abgebrochen wird).
void Factory::run(unsigned int iterations){

    unsigned int i = 0;
    while(i < iterations){

        for(const auto&[key,val] : this->machines){
            try{
                sleep(1);
                val->tick();
                std::cout <<"Machine "<< key << " working fine "<<std::endl;
            }catch (MachineFailureException &e){
                std::cout << "Exception caught" << e.what()<<std::endl;
            }catch (MachineExplosionException &e){
            std::cout << "Exception caught" << e.what()<<std::endl;
            this->deleteMachine(key);
        }
        }
        i++;
    }
}
