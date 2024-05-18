#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
/*Exceptions
Die Basisklasse aller Exceptions soll CarRentalException heißen, 
die wiederum von std::exception erbt. Überschreiben Sie die Funktion 
const char* what() der Klasse std::exception, sodass eine aussagekräftige 
Fehlermeldung zurückgegeben wird 
(alternativ können Sie auch von std::runtime_error erben und die Fehlermeldung dessen Konstruktor übergeben).

Wenn Sie es für notwendig erachten, können Sie auch weitere benutzerdefinierte 
Exception-Klassen neben den schon oben genannten hinzufügen.*/

class CarRentalException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "CarRentalException";
    }
};

class BrokenMotorException : public CarRentalException {
public:
    virtual const char* what() const noexcept override {
        return "BrokenMotorException";
    }
};

class ElectronicsFaultException : public CarRentalException {
public:
    virtual const char* what() const noexcept override {
        return "ElectronicsFaultException";
    }
};

class EmissionsTooDirtyException : public CarRentalException {
public:
    virtual const char* what() const noexcept override {
        return "EmissionsTooDirtyException";
    }
};

class NoCarFoundException : public CarRentalException {
public:
    virtual const char* what() const noexcept override {
        return "NoCarFoundException";
    }
};

#endif


