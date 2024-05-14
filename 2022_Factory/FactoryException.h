//
// Created by tgk on 5/14/24.
//
#ifndef FACTORYEXCEPTION_H
#define FACTORYEXCEPTION_H

# include <stdexcept>
# include <string>

class FactoryException : public std::runtime_error{

public:
    FactoryException(const std::string& msg): std::runtime_error(msg) {};
};

class MachineFailureException: public FactoryException{

public:
    using FactoryException::FactoryException;
};

class MachineExplosionException: public FactoryException{

public:
    using FactoryException::FactoryException;
};
#endif //FACTORYEXCEPTION_H
