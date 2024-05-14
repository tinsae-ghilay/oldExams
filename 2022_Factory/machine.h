//
// Created by tgk on 5/14/24.
//

#ifndef MACHINE_H
#define MACHINE_H
# include "factory.h"

/*
 * Die Klasse Machine ist die Oberklasse aller Maschinen und definiert deren öffentliches Interface.
*/
class Factory;

class Machine {

protected:
    Factory* factory;

public:
    Machine();
    virtual ~Machine();
    virtual void tick();
    /*
     * Damit eine Maschine ein neu erstelltes Produkt der Fabrik
     * mithilfe der Methode addProdukt() übergeben kann, benötigt die Maschine eine Referenz auf
     * die Fabrik. Mithilfe dieser Methode kann die entsprechende Referenz der Maschine in
     * der addMachine()-Methode übergeben werden.
     */
    void setFactory(Factory* f);

};


 /*
Es gibt zwei konkrete Maschinen:
•MachineProductA:
▪ Produziert pro Zeitschritt 2 Einheiten von Produkt A.
▪ Hat eine 15 % Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 2 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.
  */

 class MachineProductA: public Machine{

 public:
     using Machine::Machine;

     virtual void tick() override;
 };

 /*
•MachineProductB
▪ Produziert pro Zeitschritt 3 Einheiten von Produkt B.
▪ Hat eine 20 % Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 5 % Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */

 class MachineProductB: public Machine{

 public:
     using Machine::Machine;

     virtual void tick() override;
 };



#endif //MACHINE_H
