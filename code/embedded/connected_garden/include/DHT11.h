#ifndef DHT11_H
#define DHT11_H

#include <stdint.h>

class DHT11{
    protected:
    static const unsigned long MIN_MEASURE_PERIOD = 1000; //ms

    uint8_t _pin;
    unsigned long _lastMeasureTime;

    public:
    DHT11(){};
    void setup(uint8_t pin);
    bool measure(uint16_t* humidity, uint16_t* temperature);



};

#endif /* DHT11_H */
