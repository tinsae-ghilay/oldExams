//
// Created by tgk on 5/14/24.
//

#ifndef FACTORY_H
#define FACTORY_H

# include <map>
# include <memory>
# include "machine.h"
# include "product.h"
# include <iterator>


class Product;
class Machine;

using namespace std;
/*
 * Die Klasse Factory repräsentiert die Fabrik und implementiert die Simulation. Sie verwaltet die Maschinen,
 * da immer wieder neue Maschinen hinzugefügt und alte entfernt werden,
 * soll die Maschinenverwaltung über einen dynamischen Datencontainer erfolgen. Wählen Sie selbstständig
 * einen passenden Datencontainer aus.
 * Des Weiteren verwaltet auch die Fabrik auch die Lager der Produkte, d.h. auch hier übernimmt sie für diese die
 * Object Ownership. Für jeden Produkttypen soll es ein eigenes Lager geben, die durch separate dynamische
 * Datencontainer repräsentiert werden. Wählen Sie selbstständig passende Datencontainer aus.
*/
class Factory {

private:

    unsigned int id_ = 0;
    unsigned int mId =0;
    map<unsigned int, unique_ptr<Product>> products;
    map<unsigned int, unique_ptr<Machine>> machines;
public:

    // Fügt eine neue Maschine hinzu. Der Rückgabewert ist
    // eine ID, die die jeweilige Maschine eindeutig identifiziert.
    unsigned int addMachine(Machine* m);
    // Gibt die Maschine mit der angegebenen ID zurück.
    Machine* getMachine(unsigned id);
    // Entfernt die Maschine mit der angegebenen ID und gibt
    // alle damit verbundenen Ressourcen wieder frei.
    void deleteMachine(unsigned id);
    // Übergibt ein neues Produkt der Fabrik. Die Fabrik muss
    // dann den Typ des Produkts bestimmen und in das entsprechende Lager einsortieren. Wenn ein
    // unbekanntes Produkt übergeben wird, dann soll eine MachineFailureException geworfen werden.
    void addProduct(Product* p);
    // Gibt die Anzahl der im Lager vorhandenen Produkte A zurück.
    unsigned int getProductACount();
    // Gibt die Anzahl der im Lager vorhandenen Produkte B zurück.
    unsigned int getProductBCount();

    // Diese Methode implementiert die Zeitschleife.
    // Der Eingabeparameter iterations gibt an, nach wie vielen Iterationen die Zeitschleife abgebrochen
    // werden soll (0 bedeutet, dass die Schleife nie abgebrochen wird).
    void run(unsigned iterations);

};





#endif //FACTORY_H
