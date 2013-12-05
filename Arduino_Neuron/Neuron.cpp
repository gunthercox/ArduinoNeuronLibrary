#include <Arduino.h>
#include "Neuron.h"

// CONSTRUCTOR TO SET ANALOG AND DIGITAL PIN
Neuron::Neuron(int analog, int digital) {
  analogPin = analog;
  digitalPin = digital;
}

// CALL THIS TO START THE NEURON
void Neuron::start() {
  active = true;
  
  while (active=true) {
    
    // WAIT FOR A SIGNAL TO START (READ FIRST), OR RANDOMLY FIRE

    if (actionPotentialProbability()) {
      excitory();
    }
    
  }
  
}

// CALIBRATE NEURON DENDRITES
void Neuron::calibrate() {
  
  // SET TERMINAL HIGH
  digitalWrite(digitalPin, HIGH);

  // RECORD HIGH READING
  calibratedAmountHigh = analogRead(analogPin);
  
  delay(neuronSpeed);

  // SET TERMINAL LOW
  digitalWrite(digitalPin, LOW);

  // RECORD LOW READING
  calibratedAmountLow = analogRead(analogPin);
  
  Serial.println("Neuron calibrated: " + String(calibratedAmountLow) + " - " + String(calibratedAmountHigh));
}

// SENDS AN EXCITORY SIGNAL
void Neuron::excitory() {
    digitalWrite(digitalPin, HIGH);
    delay(neuronSpeed);
    digitalWrite(digitalPin, LOW);
    delay(neuronSpeed);
}

// SENDS AN INHIBITORY SIGNAL
void Neuron::inhibitory() {
  digitalWrite(digitalPin, HIGH);
  delay(neuronSpeed * 2);
  digitalWrite(digitalPin, LOW);
  delay(neuronSpeed);
}

// TEMPORARY HACK TO SKIP USING MULTIPLE SIGNAL TYPES
boolean Neuron::actionPotentialProbability() {
  
      Serial.println(String(analogRead(analogPin)) + " : " + String(calibratedAmountHigh) + " : " + String(calibratedAmountLow));
  
      if (analogRead(analogPin) <= ((calibratedAmountLow - 50))) {
            
          // TRIGGER ACTION POTENTIAL
          Serial.println("Neuron fired action potential from stimulis!");
          delay(Neuron::neuronSpeed);
          
          return true;
      
    // RANDOMLY FIRE
    } else if (random(20) == 5) {
        
        Serial.println("Random fire");
        delay(Neuron::neuronSpeed);
        
        return true;
        
    // DO NOT FIRE
    } else {
      delay(Neuron::neuronSpeed);
    }
  
  return false;
}

// RETURN NEURON PINS

int Neuron::dendrite() {
  return analogPin;
}

int Neuron::terminal() {
  return digitalPin;
}

