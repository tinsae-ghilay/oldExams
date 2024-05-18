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

// thrown when Fire is detected
// inherits from FireAlarmException
class BrokenMotorException : public CarRentalException
{
public:
    inline explicit BrokenMotorException(const std::string& msg):
            CarRentalException("FIRE DETECTED ON : "+msg){}
};

// thrown when Fire is detected
// inherits from FireAlarmException
class ElectronicsFaultException : public CarRentalException
{
public:
    inline explicit ElectronicsFaultException(const std::string& msg):
            CarRentalException("ERROR DETECTED : "+msg){}
};

// thrown when Fire is detected
// inherits from FireAlarmException
class EmissionsTooDirtyException : public CarRentalException
{
public:
    inline explicit EmissionsTooDirtyException(const std::string& msg):
            CarRentalException("ERROR DETECTED : "+msg){}
};
#endif //CARRENTALEXCEPTION_H
