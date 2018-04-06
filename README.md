# Arduino-Weather-CSV-Output
BME680 environmental sensor outputting data to the serial monitor as a CSV string

Barebones example of using [Adafruit's BME680 environmental sensor](https://www.adafruit.com/product/3660) breakout board to send sensor data to a Python program.

## Requirements
* Adafruit BME680 breakout board
* Adafruit_BME680 library (install in Arduino IDE through Sketch -> Include Library -> Manage Libraries, and search for BME680)
* Python with PySerial installed (install through pip: pip install pyserial)

## Stuff to know
* This example uses a very simple comma-separated value format created using the String object. The idea is ease of use and debugging for beginners, not speed.
* The order of sensor values must be agreed upon by both programs.
* For clarity, the Python program omits most error checking.
* Code assumes sensor is wired as I2C
