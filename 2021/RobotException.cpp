//
// Created by tgk on 5/7/24.
//

# include "RobotException.h"

// base
RobotException::RobotException(const std::string &msg): std::runtime_error(msg) {}


// critical


CriticalDangerException::CriticalDangerException(const std::string &msg): RobotException("CRITICAL ERROR : "+msg){}

// Internal

InternalErrorException::InternalErrorException(const std::string &msg): RobotException("INTERNAL ERROR : "+msg){}