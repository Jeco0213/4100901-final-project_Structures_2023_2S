# 4100901-final-project
This repository contains the example for the final project of the course computation structures. Please go to the [C4Model](Doc/C4Model.md) diagrams for more details on the functionality of the system.

## Hardware prerequisites
* The example is a digital lock system featuring an STM32L4 for controling the system, an ESP8266 for interfacing with the internet, a keypad for getting the sequences, and an OLED display for GUI. See more details in the [C4Model](Doc/C4Model.md)
* The following is the pinout of the STM32:
![pinout](Doc/pinout.png)

## Theoretical basis
### ESP8266
* ¿Qué es el ESP8266?: Se trata de un chip integrado con conexión WiFi y compatible con el protocolo TCP/IP. El objetivo principal es dar acceso a cualquier microcontrolador a una red.
* La gran ventaja del ESP8266 es su bajo consumo. Es el producto ideal para wereables y dispositivos del IoT.
* Especificaciones del chip ESP8266
  * Hardware:
    * Utiliza una CPU Tensilica L106 32-bit
    * Voltaje de operación entre 3V y 3,6V
    * Corriente de operación 80 mA
    * Temperatura de operación -40ºC y 125ºC
  * Conectividad:
    * Soporta IPv4 y los protocolos TCP/UDP/HTTP/FTP
  * Puertos GPIO (de propósito general): 



## Firmware prerequisites
* The ESP8266 runs the esp-link [v2.2.3](https://github.com/jeelabs/esp-link/releases/tag/v2.2.3) firmware. Please follow the [serial flashing guide](https://github.com/jeelabs/esp-link/blob/master/FLASHING.md#initial-serial-flashing).
* The STM32 runs the firmware compiled from this repository using STM32CubeIDE.



## Building and Flashing
* Open the project in STM32CubeIDE.
* Compile using the current project settings.
* Use an ST-LINK to flash the firmware into the STM32.

## Functionality
* ***TODO:*** Add more explanation here.
* The keypad...
* The Debug console...
* The internet interface...
* The system sends metrics to the internet every 24h by using an alarm of the embedded RTC.

## Contact info
* Sam C - saacifuentesmu@unal.edu.co
