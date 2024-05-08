//
// Created by tgk on 5/7/24.
//



#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

# include <stdexcept>
# include <string>


class RobotException: public std::runtime_error{
public:
    explicit RobotException(const std::string& msg);
};


// Critical
class CriticalDangerException: public RobotException{
public:
    explicit CriticalDangerException(const std::string& msg);
};

// Internal

class InternalErrorException: public RobotException{
public:
    explicit InternalErrorException(const std::string& msg);
};


#endif //MYEXCEPTIONS_H
