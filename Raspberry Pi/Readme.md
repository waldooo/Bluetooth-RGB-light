# Raspberry Pi

## MQTT and Node-RED

With the [mqtt dash](https://play.google.com/store/apps/details?id=net.routix.mqttdash) Android App you can create a dashboard with a color picker and send color values direct from it. The color values would be published to a topic (e.g. home/sala/cor) in the #FFFFFF format.

The _function Node_ is needed so you can choose any color from the color picker. If you have a limited number of colors (or if you are using text input) you can publish directly in the 255,255,255 format to the topic and send this value to the serial port. 


![Send color value](https://github.com/waldooo/Bluetooth-RGB-light/blob/master/images/screen_NodeRED.png "Node-RED")

**mqtt Node** Receive MQTT topic with color value

**function Node:** Change #FFFFFF HEX color value to CSV 255,255,255 format:

```javascript
msg.payload = parseInt("0x" + msg.payload.slice(1,3)) + "," + parseInt("0x" + msg.payload.slice(3,5)) + "," + parseInt("0x" + msg.payload.slice(5)) + "\n";
return msg;
```

**seriall Node:** Send msg.payload to Serial Port (Bluetooth)

## Wiring

First look for the HC-06 bluetooth address, then the **HC-05**(wired to the Raspberry Pi RX TX GPio pins) must be set to master and autoconnect to that found address. 

![Raspberry Pi wiring](https://github.com/waldooo/Bluetooth-RGB-light/blob/master/images/luminaria_bluetooth_RGB_raspberryPi.png)

![Raspberry Pi with wifi and bluetooth photo](https://github.com/waldooo/Bluetooth-RGB-light/blob/master/images/2017-11-20%2001.37.36.jpg)
