#include "Bme280.h"

/* Constructor and Destructor */
Bme280::Bme280() : temperature(32.12), humidity(70.3), pressure(101.325) { }
Bme280::~Bme280() {}

/* Init BME280 Sensor */
uint8_t Bme280::init(void)
{
    uint8_t ret = 1;

    Serial.println(F("BME280 init"));

    /* Default test Settings */
    uint8_t status;
    status = bme.begin();  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("   ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
        ret = 1;
    }
    else
    {
        ret = 0;
        Serial.println(F("BME280 init done ... "));
    }
    
    Serial.println("-- BME280 Default Test --");
    Serial.println();
    
    return ret;
}

/* To test reading from BME280 */
void Bme280::printBmeValues()
{
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}

/* GETS and SETs */
float Bme280::getTemperature(void) { return this->temperature; }
float Bme280::getHumidity   (void) { return this->humidity;    } 
float Bme280::getPressure   (void) { return this->pressure;    } 
