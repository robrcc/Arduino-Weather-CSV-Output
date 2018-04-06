#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C

void setup() 
{
  Serial.begin(9600);
 
  if (!bme.begin()) 
  {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop() 
{
  // Output format: 27.88,30.66,959.85,454.22,26.50
  String strOutput = "";
  strOutput += String(bme.temperature) + ",";
  strOutput += String(bme.humidity) + ",";
  strOutput += String(bme.pressure/100.0) + ",";
  strOutput += String(bme.readAltitude(SEALEVELPRESSURE_HPA)) + ",";
  strOutput += String(bme.gas_resistance / 1000.0);
 
  Serial.println(strOutput);

  delay(2000);
}





