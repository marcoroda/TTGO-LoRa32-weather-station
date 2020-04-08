/*
    Header file for BME280 sensor data 
*/

#pragma once

#include "stdint.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "Wire.h"

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA    (1013.25)

static Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

class Bme280
{
private:
    /* data */
    float temperature;
    float humidity;
    float pressure;
public:
    Bme280();
    ~Bme280();

    uint8_t init(void);
    void printBmeValues();
    /* GETs and SETs */
    float getTemperature(void);
    float getHumidity(void);
    float getPressure(void);
};