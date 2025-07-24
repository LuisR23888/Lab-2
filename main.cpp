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

  bool reading1 = digitalRead(BTN1);
  bool reading2 = digitalRead(BTN2);
  bool reading3 = digitalRead(BTN3);
  
  
  if (reading3 != lastButtonState3) {
    lastDebounceTime3 = currentTime;
  }
  if ((currentTime - lastDebounceTime3) > debounceDelay) {
    if (reading3 == HIGH && buttonState3 == LOW) {
      contadorC++;
    }
    buttonState3 = reading3;
  }
  lastButtonState3 = reading3;

  switch(contadorC){
    case 0:
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

    switch (contador){
      case 0:
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, LOW);
        break;
      case 1: 
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, LOW);
        break;
      case 2:
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, HIGH);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, LOW);
        break;
      case 3: 
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, HIGH);
        digitalWrite(LED_B, LOW);
        break;
      case 4: 
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, HIGH);
        break;
      }
    case 1:
    //reading1 = digitalRead(BTN1);
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
  

    //reading2 = digitalRead(BTN2);
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

    switch (contador){
      case 0:
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, LOW);
        break;
      case 1: 
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, LOW);
        break;
      case 2:
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, HIGH);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, LOW);
        break;
      case 3: 
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, HIGH);
        digitalWrite(LED_B, LOW);
        break;
      case 4: 
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_M, LOW);
        digitalWrite(LED_V, LOW);
        digitalWrite(LED_B, HIGH);
        break;
    }


  }

  
}




