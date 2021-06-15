/*
 * Script para medir temperatura
 * e humidade empregando dous sensores
 * analóxicos DHT11
 */
#include <DHT.h>

#define PIN_DHT1 A0
#define PIN_DHT2 A1

int tempo = 5000;
  DHT sensor1(PIN_DHT1, DHT11);  //Declaramos obxecto dht
  DHT sensor2(PIN_DHT2, DHT11);  //Declaramos obxecto dht
float humidade1, temperatura1;
float humidade2, temperatura2;
String mensaxe = "";

void setup() {
  Serial.begin(9600);
  sensor1.begin();
  sensor2.begin();
}

void loop() {
  humidade1 = sensor1.readHumidity();
  temperatura1 = sensor1.readTemperature();
  humidade2 = sensor2.readHumidity();
  temperatura2 = sensor2.readTemperature();

  //Detección de erros
  if(isnan(humidade1) || isnan(temperatura1)) {
    Serial.println("Fallo na lectura do DHT11 #01");
    return;
  }
  if(isnan(humidade2) || isnan(temperatura2)) {
    Serial.println("Fallo na lectura do DHT11 #02");
    return;
  }
  mensaxe = "Sensor #01: Humidade:\t" + String(humidade1) + "%\t\tTemperatura:\t" + String(temperatura1) + " ºC\n";
  Serial.print(mensaxe);
  mensaxe = "Sensor #02: Humidade:\t" + String(humidade2) + "%\t\tTemperatura:\t" + String(temperatura2) + " ºC\n";
  Serial.print(mensaxe);
  Serial.println("");
  delay(tempo);
}
