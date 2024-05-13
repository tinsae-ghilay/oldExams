//
// Created by tgk on 5/6/24.
//

#ifndef SENSORS_H
#define SENSORS_H
# include <random>
#include <unistd.h>
# include <string>


class RSensor {
friend std::ostream& operator<<(std::ostream& is, RSensor& s);
protected:
    int max;
    std::string is;

private:
    bool error_state;

public:

    RSensor();
    virtual ~RSensor();
    bool getErrorState() const;
    virtual int checkSensor();
    virtual void reset();

    void setErrorState(bool state);

    // for testing sensors
    void activate();
};

class UltrasonicSensor: public RSensor{
public:
    UltrasonicSensor();
    int checkSensor() override;
    void reset() override;

};

class LaserSensor: public RSensor{
public:
    LaserSensor();
    int checkSensor() override;
    void reset() override;

};
class CameraSensor: public RSensor {
public:
    CameraSensor();
    int checkSensor() override;
    void reset() override;
};
#endif //SENSORS_H
