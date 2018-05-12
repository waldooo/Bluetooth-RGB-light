# Bluetooth-RGB-light
The RGB led strip is connected to an Arduino and receives the color data from a cell phone.

# How to send colors
Send messages in the RGB format with values from 0 to 255. (both #255,255,255 or 255,255,255 are valid)
Make sure you use ('\n') at the end of line.

## Hardware used:

* Android phone connected to wifi network


* Raspberry Pi running as a MQTT Broker + Node-Red
* HC-05 Bluetooth module connected to the RX TX GPIO pins.

![Fritzing PNG: Raspberry Pi + Bluetooth](https://github.com/waldooo/Bluetooth-RGB-light/blob/master/images/luminaria_bluetooth_RGB_raspberryPi.png "Raspberry Pi (any) + HC-05") (HC-05 set as master)

* Arduino Uno R3
* HC-06 Bluetooth module
* 5v RGB Led strip

![Fritzing PNG: Arduino Bluetooth Led Strip](https://github.com/waldooo/Bluetooth-RGB-light/blob/master/images/luminaria_bluetooth_RGB_arduino.png "Arduino Bluetooth Led Strip") (showing HC-05 in picture but HC-06 was used)

