//
// Created by tgk on 5/14/24.
//
#ifndef FACTORYEXCEPTION_H
#define FACTORYEXCEPTION_H

# include <stdexcept>
# include <string>

// FactoryException
// Basisklasse aller Exceptions
class FactoryException : public std::runtime_error{

public:
    explicit FactoryException(const std::string& msg): std::runtime_error(msg) {};
};


// MachineFailureException
class MachineFailureException: public FactoryException{

public:
    using FactoryException::FactoryException;
};


// MachineExplosionException
class MachineExplosionException: public FactoryException{

public:
    using FactoryException::FactoryException;
};
#endif //FACTORYEXCEPTION_H
