//
// Created by tgk on 5/12/24.
//

#ifndef SENSOR_H
#define SENSOR_H
# include <random>
# include <iostream>
# include "FireAlarmException.h"
# include <string>

/* Diese Klasse ist die Basisklasse für alle Sensoren
 * sie definiert deren öffentliches Interface.
 * Konkrete Sensoren werden von Subklassen dieser Klasse repräsentiert.
 */
class Sensor {
public:

    Sensor() = default;
    inline virtual ~Sensor()=default;

    // Überprüft den Sensoren. Wirft 'FireAlarmException'
    inline virtual void checkSensor(){};

    // Gibt den Typ des konkreten Sensors zurück
    virtual int getType() const = 0;
};

// gets a pseudo random number between two integers.
// taken from SO.
static int getRandom()
{
    std::random_device device;
    std::mt19937 range(device());
    std::uniform_int_distribution <std::mt19937::result_type> dist(0, 100);
    return (int)dist(range);
}

class SmokeDetector : public Sensor
{
public:

    using ::Sensor::Sensor;

    inline ~SmokeDetector() override = default;

    inline void checkSensor() override
    {
        int rnd = getRandom();
        if(rnd > 96){ // 97, 98, 99 = 3%

            //FireDetectedException
            throw FireDetectedException("Sensor type "+std::to_string(this->getType()));
        }
        else if(rnd < 2){// 0, 1 = 2%

            // ErrorDetectedException
            throw ErrorDetectedException("Sensor type "+std::to_string(this->getType()));
        }

    }
    inline int getType() const override
    {
        return 1;
    }
};


class InfraredSensor : public Sensor
{
public:

    using ::Sensor::Sensor;
    inline ~InfraredSensor() override = default;
    inline void checkSensor() override
    {
        int rnd = getRandom();
        if(rnd > 94){ //95, 96 97, 98, 99 = 5%

            //FireDetectedException
            throw FireDetectedException("Sensor type "+std::to_string(this->getType()));
        }
        else if(rnd < 4){// 0, 1, 2, 3 = 4%

            // ErrorDetectedException
            throw ErrorDetectedException("Sensor type "+std::to_string(this->getType()));

        }

    }
    inline int getType() const override
    {
        return 2;
    }
};


#endif //SENSOR_H
