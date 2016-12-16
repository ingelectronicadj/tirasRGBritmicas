/*
 ***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************
 */
int analog_sensor = A1; // pin para la salida analógica del sensor
int digit_sensor = 4; // pin para el potenciómetro del sensor
int ledPin = 13;  //En la PCB es el 5
int ledPinR = 9;
int ledPinG = 6;
int ledPinB = 10;
int analogValue ; // valor del pin de entrada analógico
int digitValue ; // valor del pin de entrada digital

int tiempo=100;

/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void setup () {
pinMode (ledPin, OUTPUT);
pinMode (ledPinR, OUTPUT);
pinMode (ledPinG, OUTPUT);
pinMode (ledPinB, OUTPUT);
pinMode (digit_sensor, INPUT);
Serial.begin (9600);
}

/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void loop () {
picoDeSonido();
//rojo();
//azul();
//verde();
}

void picoDeSonido(){
  analogValue = analogRead (analog_sensor);
  digitValue=digitalRead(digit_sensor);
  Serial.println(analogValue, DEC);
  if (analogValue > 37) // nivel de sonido en el que ejecuta accion
  {
  digitalWrite (ledPin, HIGH); // enciende el led
  delay(100); // al paso de 2 segundos
  digitalWrite (ledPin, LOW); // apaga el led
  }
}

void rojo() {
  digitalWrite(ledPinR, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(tiempo);              // wait for a second
  digitalWrite(ledPinR, LOW);    // turn the LED off by making the voltage LOW
  delay(tiempo);              // wait for a second
}

void verde() {
  digitalWrite(ledPinG, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(tiempo);              // wait for a second
  digitalWrite(ledPinG, LOW);    // turn the LED off by making the voltage LOW
  delay(tiempo);              // wait for a second
}

void azul() {
  digitalWrite(ledPinB, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(tiempo);              // wait for a second
  digitalWrite(ledPinB, LOW);    // turn the LED off by making the voltage LOW
  delay(tiempo);              // wait for a second
}
