/*
 ***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************
 */
int analog_sensor = A5; // pin para la salida analógica del sensor
int digit_sensor = 4; // pin para el potenciómetro del sensor
//const byte ledPin;
const byte ledPinR = 13;
const byte ledPinG = 6;
const byte ledPinB = 10;
int analogValue ; // valor del pin de entrada analógico
//Girar el potenciometro hacia la izq aumenta el valor de ref 0-1023
int digitValue ; // valor del pin de entrada digital

int tiempo = 200;  //milisegundos


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
  pinMode (digit_sensor, INPUT);
}

/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void loop() {
    //titileo(ledPinR);
    //titileo(ledPinG);
    //titileo(ledPinB);
    picoDeSonido();

}

void titileo(const byte ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(tiempo);
  digitalWrite(ledPin, LOW);
  delay(tiempo);
}

void picoDeSonido(){
  analogValue = analogRead (analog_sensor);
  digitValue=digitalRead(digit_sensor);
  Serial.println(analogValue, DEC);
  if (analogValue > 37) // nivel de sonido en el que ejecuta accion
  {
  digitalWrite (ledPinR, HIGH); // enciende el led
  delay(100); // al paso de 2 segundos
  digitalWrite (ledPinR, LOW); // apaga el led
  }
}
