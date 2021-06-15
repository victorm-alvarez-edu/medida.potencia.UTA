/*
 * Script para medir temperatura
 * e humidade empregando dous sensores
 * analóxicos DHT11
 */
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN_DHT1 A0
#define PIN_DHT2 A1
#define PIN_DHT3 A2

int tempo = 5000;
  DHT sensor1(PIN_DHT1, DHT11);  //Declaramos obxecto dht
  DHT sensor2(PIN_DHT2, DHT11);  //Declaramos obxecto dht
  DHT sensor3(PIN_DHT3, DHT11);  //Declaramos obxecto dht
float humidade1, temperatura1;
float humidade2, temperatura2;
float humidade3, temperatura3;
String mensaxe = "";
  LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  sensor1.begin();
  sensor2.begin();
  sensor3.begin();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  humidade1 = sensor1.readHumidity();
  temperatura1 = sensor1.readTemperature();
  humidade2 = sensor2.readHumidity();
  temperatura2 = sensor2.readTemperature();
  humidade3 = sensor3.readHumidity();
  temperatura3 = sensor3.readTemperature();

  //Detección de erros
  if(isnan(humidade1) || isnan(temperatura1)) {
    Serial.println("Fallo na lectura do DHT11 #01");
    return;
  }
  if(isnan(humidade2) || isnan(temperatura2)) {
    Serial.println("Fallo na lectura do DHT11 #02");
    return;
  }
    if(isnan(humidade3) || isnan(temperatura3)) {
    Serial.println("Fallo na lectura do DHT11 #03");
    return;
  }
  mensaxe = "Sensor #01: Humidade:\t" + String(humidade1) + "%\t\tTemperatura:\t" + String(temperatura1) + " ºC\n";
  Serial.print(mensaxe);
  mensaxe = "Sensor #02: Humidade:\t" + String(humidade2) + "%\t\tTemperatura:\t" + String(temperatura2) + " ºC\n";
  Serial.print(mensaxe);
  mensaxe = "Sensor #03: Humidade:\t" + String(humidade3) + "%\t\tTemperatura:\t" + String(temperatura3) + " ºC\n";
  Serial.print(mensaxe);
  Serial.println("");
  
  // Mostrar mensaxe no LCD
  mensaxe = "#01: Hr1:\t" + String(humidade1) + "%\t\tT1:\t" + String(temperatura1) + " ºC\n";
  lcd.print(mensaxe); // Linha #01
  mensaxe = "#02: Hr2:\t" + String(humidade2) + "%\t\tT2:\t" + String(temperatura2) + " ºC\n"; 
  lcd.print(mensaxe); // Linha #02
  delay(tempo);
  lcd.clear();
  lcd.print(mensaxe); // Linha #01
  mensaxe = "#03: Hr3:\t" + String(humidade3) + "%\t\tT3:\t" + String(temperatura3) + " ºC\n"; 
  lcd.print(mensaxe); // Linha #02
  delay(tempo);
  lcd.clear();
  delay(tempo/3);
}
