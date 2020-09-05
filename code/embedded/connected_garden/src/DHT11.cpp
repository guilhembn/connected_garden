#include <DHT11.h>
#include <Arduino.h>

void DHT11::setup(uint8_t pin){
    _pin = pin;
}

bool DHT11::measure(uint16_t* humidity, uint16_t* temperature){
    if (millis() - _lastMeasureTime < MIN_MEASURE_PERIOD){
        return false;
    }
    uint16_t data = 0, rawHumidity = 0, rawTemperature = 0;
    // Request sample
	digitalWrite(_pin, LOW); // Send start signal
	pinMode(_pin, OUTPUT);
	delay(18);
	pinMode(_pin, INPUT_PULLUP);
	//digitalWrite(_pin, HIGH); // Switch bus to receive data

	// We're going to read 83 edges:
	// - First a FALLING, RISING, and FALLING edge for the start bit
	// - Then 40 bits: RISING and then a FALLING edge per bit
	// To keep our code simple, we accept any HIGH or LOW reading if it's max 85 usecs long
	noInterrupts();
    unsigned long startTime;
	for (int8_t i = -3; i < 2 * 40; i++)
	{
	    byte age;
		startTime = micros();
		do
		{
			age = (unsigned long)(micros() - startTime);
			if (age > 90)
			{
				//error = ERROR_TIMEOUT;
				interrupts();
				return false;
			}
		} while (digitalRead(_pin) == (i & 1) ? HIGH : LOW);
		if (i >= 0 && (i & 1))
		{
			// Now we are being fed our 40 bits
			data <<= 1;
			// A zero max 30 usecs, a one at least 68 usecs.
			if (age > 30)
			{
				data |= 1; // we got a one
			}
		}
		switch (i)
		{
		case 31:
			rawHumidity = data;
			break;
		case 63:
			rawTemperature = data;
			data = 0;
			break;
		}
	}
	interrupts();

	// Verify checksum
	if ((byte)(((byte)rawHumidity) + (rawHumidity >> 8) + ((byte)rawTemperature) + (rawTemperature >> 8)) != data)
	{
		//error = ERROR_CHECKSUM;
		return false;
	}

	// Convert readings
	*humidity = (rawHumidity >> 8) + ((rawHumidity & 0x00FF) * 0.1);
	*temperature = (rawTemperature >> 8) + ((rawTemperature & 0x00FF) * 0.1);

    _lastMeasureTime = millis();

	//error = ERROR_NONE;
    return true;
}