#include <Arduino.h>
#include "Neuron.h"

// CONSTRUCTOR TO SET ANALOG AND DIGITAL PIN
Neuron::Neuron(int analog, int digital) {
  analogPin = analog;
  digitalPin = digital;
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

// RECIEVE A SIGNAL FROM ANOTHER NEURON
int Neuron::signalType() {
  
  // READ THE BLINK SPEED OF THREE POSSIBLE SIGNALS
  // 0 = no singnal, not blinking
  // 1 = excitory, blinking fast
  // 2 = inhibitory, blinking slow
  
  long frequency = getFrequency(analogPin);
  
  // EXCITORY FREQUENCY
  if (frequency > neuronSpeed) {
    Serial.println("Excitory " + frequency);
    return 1;
  } 
  
  // INHIBITORY FREQUENCY
  // THE 10 IS A BUFFER FOR ANY OUTSIDE INTERFERENCE
  if (frequency < (neuronSpeed * 2) && frequency > 10) {
    Serial.println("Inhibitory " + frequency);
    return 2;
  }
    // NO SIGNAL
    Serial.println("No signal " + frequency);
    return 0;

}

// GET THE FREQUENCY OF THE INCOMING SIGNAL
// http://tushev.org/articles/arduino/item/51-measuring-frequency-with-arduino
long Neuron::getFrequency(int pin) {
  int SAMPLES = 10;
  long freq = 0;
  for(unsigned int j=0; j<SAMPLES; j++) freq+= 50/pulseIn(pin, HIGH, 250);
  return freq / SAMPLES;
}

// SENDS AN EXCITORY SIGNAL
void Neuron::excitory() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(digitalPin, HIGH);
    delay(neuronSpeed);
    digitalWrite(digitalPin, LOW);
    delay(neuronSpeed);
  }
}

// SENDS AN INHIBITORY SIGNAL
void Neuron::inhibitory() {
  digitalWrite(digitalPin, HIGH);
  delay(neuronSpeed * 2);
  digitalWrite(digitalPin, LOW);
  delay(neuronSpeed);
}

// CONTROLS A NEURONS ACTION POTENTIAL
boolean Neuron::actionPotentialProbability(int excitory, int inhibitory) {

  // ESOTERIC FUNCTION TO RETURN A VALUE FOR A NEURON'S ACTION POTENTIAL

  /*if ((excitory - lastExcitory) > (inhibitory - lastInhibitory)) {
   return true;
   }*/

  // SIGNAL TRIGGERED BASED ON PROBABILITY
  /*if () {
   return true;
   }*/

  return false;

}

int Neuron::get_dendrite() {
  return analogPin;
}

int Neuron::get_terminal() {
  return digitalPin;
}
