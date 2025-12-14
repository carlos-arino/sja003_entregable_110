/* Ejercicio entregable 110
 Deben de utilizar este archivo los alumnos con c<5, d<5, u>=5
 siendo c,d,u las tres últimas cifras del DNI 22000cdu -W
 Sensor de temperatura y motor continua con encoder
 Para cambiar la temperatura haz click sobre el sensor NTC durante la simulacion
 rellenar vuestro nombre y DNI
 NOMBRE ALUMNO: XXXXX
 DNI: XXXXX
 ENLACE WOKWI: XXXXXXX
*/

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int tempPin = 4;  // Pin de datos del DS18B20 (OneWire)
const int encAPin = 23; // Pin para el canal A del encoder
const int encBPin = 22; // Pin para el canal B del encoder
const int encCPin = 16; // Pin para el canal C del encoder
const int encDPin = 15; // Pin para el canal D del encoder
OneWire oneWire(tempPin);
DallasTemperature sensors(&oneWire);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  ledcAttachPin(26, 0);
  ledcSetup(0, 1000, 10); // frecuencia 1KHz y resolucion 2^10
  pinMode(encAPin, INPUT);
  pinMode(encBPin, INPUT);
  pinMode(encCPin, INPUT);
  pinMode(encDPin, INPUT);
  sensors.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(100);
  if (millis() < 5000)
    ledcWrite(0, 200);
  if (millis() > 5000)
    ledcWrite(0, 500);
  if (millis() > 10000)
    ledcWrite(0, 1000);
  Serial.print(digitalRead(encAPin));
  Serial.print(", ");
  Serial.print(digitalRead(encBPin));
  Serial.print(", ");
  Serial.print(digitalRead(encCPin));
  Serial.print(", ");
  Serial.print(digitalRead(encDPin));
  Serial.print(", ");
  sensors.requestTemperatures();
  const float tempC = sensors.getTempCByIndex(0);
  Serial.println(tempC);
}
