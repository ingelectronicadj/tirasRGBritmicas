# Tiras de leds RGB ritmicas
Este proyecto tiene como proposito iluminar un ambiente de acuerdo al ritmo de la música.

# Materiales
* Tira de leds RGB de 5mts
* Microcontrolador Atmega328
* Transistores NPN de potencia
* Sensor de sonido
* Crsital de 16MHz, condensadores de 22pF, resistencias

# Esquema de conexión
![grafo1](https://github.com/ingelectronicadj/tirasRGBritmicas/blob/master/imagenes/rgb.jpg?raw=true "grafo1")

# Fases de trabajo
* Fase 1: Realizar secuencias de blink(parpadeo), brillo(intensidad) **(Done)**
* Fase 2: Ritmicas On/Off de colores RGB, CMY de acuerdo al sobrepaso de un nivel de volumen. **(Done)**
* Fase 3: Ritmicas por frecuencias del audio.

Hilo útil para la fase 3: https://www.arduino.cc/en/Tutorial/SimpleAudioFrequencyMeter
![grafo2](https://www.arduino.cc/en/uploads/Tutorial/ArduinoZeroAudioInput_bb.png "grafo2")

###Desarrollador
* Diego Javier Mena - @ingelectronicadj
