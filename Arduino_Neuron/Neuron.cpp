#include <Arduino.h>
#include "Neuron.h"

// CONSTRUCTOR TO SET ANALOG AND DIGITAL PIN
Neuron::Neuron(int analog, int digital) {
  analogPin = analog;
  digitalPin = digital;
}

// CALIBRATE NEURON DENDRITES
void Neuron::calibrate() {

  // SET TERMINAL LOW
  digitalWrite(digitalPin, LOW);

  // RECORD LOW READING
  calibratedAmountLow = analogRead(analogPin);

  // SET TERMINAL HIGH
  digitalWrite(digitalPin, HIGH);

  // RECORD HIGH READING
  calibratedAmountHigh = analogRead(analogPin);

  Serial.println("Neuron calibrated");
}

// RECIEVE A SIGNAL FROM ANOTHER NEURON
int Neuron::signalType() {
  
  // READ THE BLINK SPEED OF THREE POSSIBLE SIGNALS
  // 0 = no singnal, not blinking
  // 1 = excitory, blinking fast
  // 2 = inhibitory, blinking slow
  
  long frequency = getFrequency(analogPin);
  
  // EXCITORY FREQUENCY
  if (frequency > 400) {
    return 1;
  } 
  
  // INHIBITORY FREQUENCY
  if (frequency < 400 && frequency > 200) {
    return 2;
  }
    // NO SIGNAL
    return 0;

}

// GET THE FREQUENCY OF THE INCOMING SIGNAL
// http://tushev.org/articles/arduino/item/51-measuring-frequency-with-arduino
long Neuron::getFrequency(int pin) {
  #define SAMPLES 4096
  long freq = 0;
  for(unsigned int j=0; j<SAMPLES; j++) freq+= 500000/pulseIn(pin, HIGH, 250000);
  return freq / SAMPLES;
}

// SENDS AN EXCITORY SIGNAL
void Neuron::excitory() {
  digitalWrite(digitalPin, HIGH);
  delay(250);
  digitalWrite(digitalPin, LOW);
  delay(250);
}

// SENDS AN INHIBITORY SIGNAL
void Neuron::inhibitory() {
  digitalWrite(digitalPin, HIGH);
  delay(250 * 2);
  digitalWrite(digitalPin, LOW);
  delay(250);
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
