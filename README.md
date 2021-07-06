# Photoelectric barrier

Sensor: [TCRT5000](https://www.amazon.de/dp/B07Q3X9J2V/ref=cm_sw_em_r_mt_dp_PBBP849SAZ3YE55GVBYM)

Microcontroller: Node MCU, Esp8266-12 WiFi module

Tutorial: https://diyi0t.com/tcrt5000-line-tracking-module-arduino-esp8266-esp32/

# Functionality:

The sensor is used to detect if a person enters or leaves the building. It sends a message every time the sensor detects a "color" change. (threshold is predefined through the potentiometer )

It uses the CleanAIRDevice library to connect to wifi and mqtt via external configuration. (See: https://github.com/CleanAIR-Building/CleanAIRDevice)

It sends json messages in the following shape:

```
{
    "sensor": <sensor-name>,
    "barrier": <0 or 1/-1>
}
```
