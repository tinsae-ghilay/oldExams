//
// Created by tgk on 5/12/24.
//
# include <stdexcept>
# include <string>



#ifndef FIREALARMEXCEPTION_H
#define FIREALARMEXCEPTION_H
// Basisklasse aller Exceptions
// erbt von von std::runtime_error
class FireAlarmException: public std::runtime_error
{
public:
    inline  explicit FireAlarmException(const std::string& msg)
    : std::runtime_error(msg){}
};

// thrown when Fire is detected
// inherits from FireAlarmException
class FireDetectedException : public FireAlarmException
{
public:
    inline explicit FireDetectedException(const std::string& msg):
            FireAlarmException("FIRE DETECTED ON : "+msg){}
};

// thrown when Fire is detected
// inherits from FireAlarmException
class ErrorDetectedException : public FireAlarmException
{
public:
    inline explicit ErrorDetectedException(const std::string& msg):
            FireAlarmException("ERROR DETECTED : "+msg){}
};
#endif //FIREALARMEXCEPTION_H
