//**********************************************************************/
// Universidad del Valle de Guatemala
// BE3029 - Electronica Digital 2
// Luis Rodriguez
// 21/07/2025
// LABORATORIO 1
// MCU: ESP32 dev kit 1.1
//**********************************************************************/


#include <Arduino.h>
#include <stdint.h>

// Definciones
#define LED_A 13
#define LED_M 14
#define LED_V 26
#define LED_B 33
#define BTN1 0
#define BTN2 5
#define BTN3 21

// Funciones
void encenderLEDS(bool t1, bool t2, bool t3, bool t4);

// Variables globales
uint8_t estadoBTN1 = 0;
uint8_t estadoBTN2 = 0;
uint8_t estadoBTN3 = 0;
int contador = 0;
int contadorC = 0;

const unsigned long debounceDelay = 50;  // ms

// Variables para debounce botón 1
unsigned long lastDebounceTime1 = 0;
bool lastButtonState1 = HIGH;
bool buttonState1 = HIGH;

// Variables para debounce botón 2
unsigned long lastDebounceTime2 = 0;
bool lastButtonState2 = LOW;
bool buttonState2 = LOW;

// Variables para debounce botón 3
unsigned long lastDebounceTime3 = 0;
bool lastButtonState3 = LOW;
bool buttonState3 = LOW;

void setup() {
  // put your setup code here, to run 
  
  unsigned long currentTime = millis();

  // Salidas
  pinMode(LED_A, OUTPUT);
  pinMode(LED_M, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  // Entradas
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLDOWN);
  pinMode(BTN3, INPUT);

  // Inicializar estado de LEDs
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_M, LOW);
  digitalWrite(LED_V, LOW);
  digitalWrite(LED_B, LOW);
}

void loop() {
  
  unsigned long currentTime = millis();
  // put your main code here, to run repeatedly:

  // lectura de estado de los 3 botones a utilizar
  bool reading1 = digitalRead(BTN1);
  bool reading2 = digitalRead(BTN2);
  bool reading3 = digitalRead(BTN3);
  
  // Cambio de contador utilizando un solo boton con debunce
  if (reading3 != lastButtonState3) {
    lastDebounceTime3 = currentTime;
  }
  if ((currentTime - lastDebounceTime3) > debounceDelay) {
    if (reading3 == HIGH && buttonState3 == LOW && contadorC == 0) {
      contadorC = 1;
      contador = 0;
    }else if(reading3 == HIGH && buttonState3 == LOW && contadorC == 1){
      contadorC = 0;
      contador = 0;
    }
    buttonState3 = reading3;
  }
  lastButtonState3 = reading3;

  // Cambio entre contadores gracias al contadorC
  switch(contadorC){
    case 0:

    // Botones de avanzar y retroceder con su respectivo debounce
    if (reading1 != lastButtonState1) {
      lastDebounceTime1 = currentTime;
    }
    if ((currentTime - lastDebounceTime1) > debounceDelay) {
      if (reading1 == LOW && buttonState1 == HIGH) {
        contador++;
        if (contador > 4) contador = 0;
      }
      buttonState1 = reading1;
    }
    lastButtonState1 = reading1;
  
    if (reading2 != lastButtonState2) {
      lastDebounceTime2 = currentTime;
    }
    if ((currentTime - lastDebounceTime2) > debounceDelay) {
      if (reading2 == HIGH && buttonState2 == LOW) {
        contador--;
        if (contador < 0) contador = 4;
      }
      buttonState2 = reading2;
    }
    lastButtonState2 = reading2;

    // Encendido de leds
    switch (contador){
      case 0:
        encenderLEDS(LOW, LOW, LOW, LOW);
        break;
      case 1: 
        encenderLEDS(HIGH, LOW, LOW, LOW);
        break;
      case 2:
        encenderLEDS(LOW, HIGH, LOW, LOW);
        break;
      case 3: 
        encenderLEDS(LOW, LOW, HIGH, LOW);
        break;
      case 4: 
        encenderLEDS(LOW, LOW, LOW, HIGH);
        break;
      }
    break;
    
    case 1:
    if (reading1 != lastButtonState1) {
      lastDebounceTime1 = currentTime;
    }
    if ((currentTime - lastDebounceTime1) > debounceDelay) {
      if (reading1 == LOW && buttonState1 == HIGH) {
        contador++;
        if (contador > 15) contador = 0;
      }
      buttonState1 = reading1;
    }
    lastButtonState1 = reading1;
  
    if (reading2 != lastButtonState2) {
      lastDebounceTime2 = currentTime;
    }
    if ((currentTime - lastDebounceTime2) > debounceDelay) {
      if (reading2 == HIGH && buttonState2 == LOW) {
        contador--;
        if (contador < 0) contador = 15;
      }
      buttonState2 = reading2;
    }
    lastButtonState2 = reading2;

    switch (contador){
      case 0:
        encenderLEDS(LOW, LOW, LOW, LOW);
        break;
      case 1: 
        encenderLEDS(LOW, LOW, LOW, HIGH);
        break;
      case 2:
        encenderLEDS(LOW, LOW, HIGH, LOW);
        break;
      case 3: 
        encenderLEDS(LOW, LOW, HIGH, HIGH);
        break;
      case 4: 
        encenderLEDS(LOW, HIGH, LOW, LOW);
        break;
      case 5: 
        encenderLEDS(LOW, HIGH, LOW, HIGH);
        break;
      case 6: 
        encenderLEDS(LOW, HIGH, HIGH, LOW);
        break;
      case 7: 
        encenderLEDS(LOW, HIGH, HIGH, HIGH);      
        break;
      case 8: 
        encenderLEDS(HIGH, LOW, LOW, LOW);
        break;
      case 9: 
        encenderLEDS(HIGH, LOW, LOW, HIGH);
        break;
      case 10: 
        encenderLEDS(HIGH, LOW, HIGH, LOW);
        break;
      case 11: 
        encenderLEDS(HIGH, LOW, HIGH, HIGH);
        break;
      case 12: 
        encenderLEDS(HIGH, HIGH, LOW, LOW);
        break;
      case 13: 
        encenderLEDS(HIGH, HIGH, LOW, HIGH);
        break;
      case 14: 
        encenderLEDS(HIGH, HIGH, HIGH, LOW);
        break;
      case 15: 
        encenderLEDS(HIGH, HIGH, HIGH, HIGH);
        break;            
    }
    break;
  }
}

void encenderLEDS(bool t1, bool t2, bool t3, bool t4){
  digitalWrite(LED_A,t1);
  digitalWrite(LED_M,t2);
  digitalWrite(LED_V,t3);
  digitalWrite(LED_B,t4);
}




