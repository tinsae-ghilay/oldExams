//
// Created by tgk on 5/14/24.
//

#ifndef PRODUCT_H
#define PRODUCT_H

/*
 * Die Klasse Product ist die Oberklasse aller Produkte und definiert deren öffentliches Interface.
 * */
class Product{
public:
    inline Product() = default;
    virtual ~Product()= default;
    inline virtual int getType() const = 0;
};



class ProductA:public Product{
public:

    using Product::Product;

    // Identifiziert den Produkttypen (Damit die automatischen Tests korrekt
    //funktionieren
    inline int getType() const override{
        return 1;
    }
};



class ProductB: public Product{
public:

    using Product::Product;

    // Identifiziert den Produkttypen (Damit die automatischen Tests korrekt
    //funktionieren
    inline int getType() const override{
        return 2;
    }
};


#endif //PRODUCT_H
