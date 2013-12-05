#include <Arduino.h>
#include "Neuron.h"

// CONSTRUCTOR TO SET ANALOG AND DIGITAL PIN
Neuron::Neuron(int analog, int digital) {
  analogPin = analog;
  digitalPin = digital;
}

/*
This starts and stops the neuron.
*/

void Neuron::start() {
  
  active = true;
  while (active=true) {
    
    if (actionPotentialProbability()) {
      excitory();
    }
    
    delay(Neuron::SPEED);
    
  }
}

void Neuron::terminate() {
   active = false; 
}

/*
This calibrates the neuron.
A measurement is saved for the highest and lowest
value that the dendrites can detect.
To make the calibrated values more accurate, multiple
measurements will be taken and averaged together.
To the accuracy of the calibration is praportional to
the number of samples taken.
*/

void Neuron::calibrate() {

  for (int i = 0; i <= 5; i++) {
    digitalWrite(digitalPin, HIGH);
    calibratedAmountHigh = (calibratedAmountHigh + analogRead(analogPin)) / 2;
    delay(SPEED);
    digitalWrite(digitalPin, LOW);
    calibratedAmountLow = (calibratedAmountLow + analogRead(analogPin)) / 2;
  }
  
  Serial.println("Neuron calibrated: " + String(calibratedAmountLow) + " - " + String(calibratedAmountHigh));
}

boolean Neuron::actionPotentialProbability() {

  Serial.println(String(analogRead(analogPin)) + " : " + String(calibratedAmountHigh) + " : " + String(calibratedAmountLow));
  Serial.println("ActionPotential: " + String(actionPotential));

  if (analogRead(analogPin) <= ((calibratedAmountLow - 50))) {
    
    actionPotential += 1;
        
    if (actionPotential >= 1) {
      Serial.println("Neuron fired action potential from stimulis!");
      return true;
    }
    
  } else if (random(40) == 5) {
      Serial.println("Random fire");        
      return true;
  }
  
  return false;
}

/*
The excitory and inhibitory methods send deffent types of signals.
Sending a signal decreases the action potential of a neuron.
* Only excitory signals are currently being used.
*/

void Neuron::excitory() {
  actionPotential -= 1;
  digitalWrite(digitalPin, HIGH);
  delay(SPEED);
  digitalWrite(digitalPin, LOW);
  delay(SPEED);
}

void Neuron::inhibitory() {
  actionPotential -= 1;
  digitalWrite(digitalPin, HIGH);
  delay(SPEED * 2);
  digitalWrite(digitalPin, LOW);
  delay(SPEED);
}

// RETURN NEURON PINS

int Neuron::dendrite() {
  return analogPin;
}

int Neuron::terminal() {
  return digitalPin;
}

