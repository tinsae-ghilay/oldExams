//
// Created by tgk on 5/18/24.
//

#ifndef CARRENTALEXCEPTION_H
#define CARRENTALEXCEPTION_H
# include <stdexcept>
class CarRentalException: public std::runtime_error
{
public:
    inline  explicit CarRentalException(const std::string& msg)
            : std::runtime_error(msg){}
};

// thrown when car has motor problems
// inherits from carRentalException
class BrokenMotorException : public CarRentalException
{
public:
    inline explicit BrokenMotorException(const std::string& msg):
            CarRentalException(msg){}
};

// thrown when car has electrical problems
// inherits from CarRentalException
class ElectronicsFaultException : public CarRentalException
{
public:
    inline explicit ElectronicsFaultException(const std::string& msg):
            CarRentalException(msg){}
};

// thrown when car doesnt meet emission requirements
// inherits from CarRentalException
class EmissionsTooDirtyException : public CarRentalException
{
public:
    inline explicit EmissionsTooDirtyException(const std::string& msg):
            CarRentalException(msg){}
};

class InvalidCarException : public CarRentalException
{
public:
    inline explicit InvalidCarException(const std::string& msg):
            CarRentalException(msg){}
};

class UnavailableCarException : public CarRentalException
{
public:
    inline explicit UnavailableCarException(const std::string& msg):
            CarRentalException(msg){}
};
#endif //CARRENTALEXCEPTION_H
