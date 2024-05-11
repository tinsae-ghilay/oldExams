//
// Created by tgk on 5/6/24.
//

#ifndef SENSORS_H
#define SENSORS_H
# include <random>
#include <unistd.h>
# include <string>


class Sensor {
friend std::ostream& operator<<(std::ostream& is, Sensor& s);
protected:
    int max;
    std::string is;

private:
    bool error_state;

public:

    Sensor();
    virtual ~Sensor();
    bool getErrorState() const;
    virtual int checkSensor();
    virtual void reset();

    void setErrorState(bool state);

    // for testing sensors
    void activate();
};

class UltrasonicSensor: public Sensor{
public:
    UltrasonicSensor();
    int checkSensor() override;
    void reset() override;

};

class LaserSensor: public Sensor{
public:
    LaserSensor();
    int checkSensor() override;
    void reset() override;

};
class CameraSensor: public Sensor {
public:
    CameraSensor();
    int checkSensor() override;
    void reset() override;
};
#endif //SENSORS_H
