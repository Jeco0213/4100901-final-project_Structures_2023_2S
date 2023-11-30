# C4Model
Use the [structurizr-dsl](https://www.structurizr.com/dsl) online tool to render the diagrams with the code in [C4Model.dsl](C4Model.dsl)

## Context Diagram
The user can prompt the digital lock system either by using:
1. The debug terminal from a host PC through the ST-Link COM port.
2. The hex keypad for password related transactions.
3. The internet over WIFI.
![context](context.png)

## Container Diagram
The lock system features an STM32L4 as the main processor and an [ESP8266](https://www.espressif.com/en/products/socs/esp8266) as an auxiliar for conenction with the internet (see [ESP-Link](https://github.com/jeelabs/esp-link)). The STM32 controls a hex keypad, a VCOM port for debug, an OLED display for GUI, and an LED for mocking the actuator of the lock system.
![context](container.png)

## Component Diagram
The STM32 runs a [controller-model-view](https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller) pattern in which the controller captures the events from the keypad as well as the commands from the internet, then the model processes the events and updates the view accordingly.
![context](component.png)

## Code Diagram
El diagrama de código en la imagen representa la interacción entre tres sistemas de software en un sistema de bloqueo:

* KEYPAD: Este es el sistema que permite la entrada de datos del usuario. Este sistema recibe la entrada del usuario a través de un teclado de membrana y luego pasa esa entrada al sistema de bloqueo.

* LOCK: Este es el sistema que gestiona el mecanismo de bloqueo. Recibe la entrada del usuario del sistema KEYPAD, verifica si la entrada es correcta y luego cambia el estado del bloqueo (bloqueado/desbloqueado) en consecuencia.

* SCREEN OLED: Este es el sistema que muestra información al usuario. Puede mostrar el estado del bloqueo, mensajes de error si la entrada del usuario es incorrecta.
![context](Code_diagram.png)