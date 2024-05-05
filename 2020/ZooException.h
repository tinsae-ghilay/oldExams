//
// Created by tgk on 5/5/24.
//

#ifndef ZOOEXCEPTION_H
#define ZOOEXCEPTION_H
# include <stdexcept>

class ZooException: public std::runtime_error {

private:
    std::string msg;
public:
    ZooException(const std::string& msg) : std::runtime_error(msg) {};
};
#endif //ZOOEXCEPTION_H
