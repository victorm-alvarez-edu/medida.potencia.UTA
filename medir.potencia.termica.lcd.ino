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

int tempo = 7000;
  DHT sensor1(PIN_DHT1, DHT11);  //Declaramos obxecto dht
  DHT sensor2(PIN_DHT2, DHT11);  //Declaramos obxecto dht
float humidade1, temperatura1;
float humidade2, temperatura2;
String mensaxe = "";
  LiquidCrystal_I2C lcd(0x27, 16, 2); //Se o LCD non mostra datos, probar enderezo: 0x3F

void setup() {
  Serial.begin(9600);
  sensor1.begin();
  sensor2.begin();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  delay(tempo/4); //Espera aínda que se produza un erro de lectura
  
  humidade1 = sensor1.readHumidity();
  temperatura1 = sensor1.readTemperature();
  humidade2 = sensor2.readHumidity();
  temperatura2 = sensor2.readTemperature();

  //Detección de erros
  lcd.clear();
  if(isnan(humidade1) || isnan(temperatura1)) {
    Serial.println("Fallo na lectura do DHT11 #01");
    lcd.setCursor(0, 0);
    lcd.print("#1: Fallo sensor");
    return;
  }
  if(isnan(humidade2) || isnan(temperatura2)) {
    Serial.println("Fallo na lectura do DHT11 #02");
    lcd.setCursor(0, 1);
    lcd.print("#2: Fallo sensor");
    return;
  }
  mensaxe = "Sensor #01: Humidade:\t" + String(humidade1) + " %\t\tTemperatura:\t" + String(temperatura1) + " ºC\n";
  Serial.print(mensaxe);
  mensaxe = "Sensor #02: Humidade:\t" + String(humidade2) + " %\t\tTemperatura:\t" + String(temperatura2) + " ºC\n";
  Serial.print(mensaxe);
  Serial.println("");
  
  // Mostrar mensaxe no LCD
  mensaxe = "#1 " + String(humidade1, 1) + " % " + String(temperatura1, 1) + " C";
  lcd.setCursor(0, 0);
  lcd.print(mensaxe); // Linha #01
  mensaxe = "#2 " + String(humidade2, 1) + " % " + String(temperatura2, 1) + " C"; 
  lcd.setCursor(0, 1);
  lcd.print(mensaxe); // Linha #02
  delay(tempo);
  lcd.clear();
}
