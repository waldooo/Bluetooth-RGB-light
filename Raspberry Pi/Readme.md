# Node-RED


**1** Receive MQTT topic with color value

**2** Change #FFFFFF HEX color value to CSV 255,255,255 format:

```javascript
msg.payload = parseInt("0x" + msg.payload.slice(1,3)) + "," + parseInt("0x" + msg.payload.slice(3,5)) + "," + parseInt("0x" + msg.payload.slice(5)) + "\n";
return msg;
```

**3** Send msg.payload to Serial Port (Bluetooth)
