/*
 ***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************
 */
int analog_sensor = A5; // pin para la salida analógica del sensor
//int digit_sensor = 4; // pin para el potenciómetro del sensor

//const byte ledPin;
const byte ledPinR = 9;
const byte ledPinG = 6;
const byte ledPinB = 10;
const byte ledPinPCB = 5;

int analogValue;  // valor del pin de entrada analógico
//Girar el potenciometro hacia la izq aumenta el valor de ref 0-1023
int digitValue;  // valor del pin de entrada digital

int contador = 0;
int tiempo = 100;  //milisegundos
int transicion = 20;  //milisegundos
int brillo; //Variable auxiliar para condicionales


/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void setup() {
    Serial.begin(9600);
    pinMode(ledPinR, OUTPUT);
    pinMode(ledPinG, OUTPUT);
    pinMode(ledPinB, OUTPUT);
    //pinMode (digit_sensor, INPUT);
}

/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void loop() {
    //blink();
    //rutinaBrillos();
    picoDeSonido();

}

void blink(){
    titileoRGB(ledPinR); //Rojo
    titileoRGB(ledPinG); //Verde
    titileoRGB(ledPinB); //Azul
    titileoCMY(ledPinG,ledPinB); // Cian
    titileoCMY(ledPinR,ledPinB); // Magenta
    titileoCMY(ledPinR,ledPinG); // Amarillo
}

void titileoRGB(const byte ledPin) {
    digitalWrite(ledPin, HIGH);
    delay(tiempo);
    digitalWrite(ledPin, LOW);
    delay(transicion);
}

void titileoCMY(const byte ledPin,const byte ledPin2) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(tiempo);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    delay(transicion);
}

void rutinaBrillos(){
  intensidadBrilloRGB(ledPinR);
  intensidadBrilloRGB(ledPinG);
  intensidadBrilloRGB(ledPinB);
  intensidadBrilloCMY(ledPinG,ledPinB); // Cian
  intensidadBrilloCMY(ledPinR,ledPinB); // Magenta
  intensidadBrilloCMY(ledPinR,ledPinG); // Amarillo
}

void intensidadBrilloRGB(const byte ledPin){
  for(brillo=0; brillo<=255; brillo++){
      analogWrite(ledPin, brillo);
      delay(transicion); // tiempo de transicion
     }
     analogWrite(ledPin, 0);
     //delay(1000); // Sostiene el color 1s
}

void intensidadBrilloCMY(const byte ledPin,const byte ledPin2){
  for(brillo=0; brillo<=255; brillo++){
      analogWrite(ledPin, brillo);
      analogWrite(ledPin2, brillo);
      delay(transicion); // tiempo de transicion
     }
     analogWrite(ledPin, 0);
     analogWrite(ledPin2, 0);
     //delay(1000); // Sostiene el color 1s
}

void picoDeSonido(){
    analogValue = analogRead (analog_sensor);
    //digitValue=digitalRead(digit_sensor);
    Serial.print("ADC = ");
    Serial.println(analogValue, DEC);
    //Serial.print("Digital = ");
    //Serial.println(digitValue);
    Serial.print("Contador = ");
    Serial.println(contador);
    if (analogValue > 32) { // nivel de sonido en el que ejecuta accion

            contador++;
            if (contador <= 3) {
                    titileoRGB(ledPinR);
            }
            else if(contador > 3 && contador <= 6) {
                    titileoRGB(ledPinG);
            }
            else if(contador> 6 && contador <= 9) {
                    titileoRGB(ledPinB);
            }
            else if(contador> 9 && contador <= 12) {
                    titileoCMY(ledPinG,ledPinB); // Cian
            }
            else if(contador> 12 && contador <= 15) {
                    titileoCMY(ledPinR,ledPinB); // Magenta
            }
            else if(contador> 15 && contador <= 18) {
                    titileoCMY(ledPinR,ledPinG); // Amarillo
            }
            else{
                    contador=0;
            }
    }

}
