/*
 ***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************
 */
int analog_sensor = A1; // pin para la salida analógica del sensor
int digit_sensor = 4; // pin para el potenciómetro del sensor
int ledPin = 13;
int analogValue ; // valor del pin de entrada analógico
int digitValue ; // valor del pin de entrada digital

/*
 ***********************************************************************
 *              SETUP CONFIGURACIÓN INICIAL
 ***********************************************************************
 */
void setup () {
pinMode (ledPin, OUTPUT);
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
//titileo();
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

void titileo() {
  int ulises=100;
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ulises);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(ulises);              // wait for a second
}
