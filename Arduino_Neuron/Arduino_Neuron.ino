#include "Neuron.h"

/*
 ** ARDUINO NEURON
 ** BY GUNTHER COX
 ** 09/15/2013
 */
  
// CREATE NEW NEURONS
Neuron neuron1(A0, 6);
Neuron neuron2(A1, 5);
Neuron neuron3(A2, 4);
Neuron neuron4(A3, 3);

void setup() {
  
  // SET DENDRITES AS INPUTS AND SYNAPTIC TERMINALS AS OUTPUT
  pinMode(neuron1.dendrite(), INPUT);
  pinMode(neuron1.terminal(), OUTPUT);
  
  pinMode(neuron2.dendrite(), INPUT);
  pinMode(neuron2.terminal(), OUTPUT);

  pinMode(neuron3.dendrite(), INPUT);
  pinMode(neuron3.terminal(), OUTPUT);
  
  pinMode(neuron4.dendrite(), INPUT);
  pinMode(neuron4.terminal(), OUTPUT);

  Serial.begin(9600);
  Serial.println("Arduino Neuron Inilalized");
  delay(Neuron::neuronSpeed);
  
  // CALIBRATE NEURONS
  neuron1.calibrate();
  neuron2.calibrate();
  neuron3.calibrate();
  neuron4.calibrate();
}

void loop() {
  
  // dont forget to neuron.begin!!!!

  // READ DENDRITE VALUES
  /*for (int w = 0; w <= 4; w++) {
    neuron1.actionPotential = analogRead(neuron1.get_dendrite());
    delay(Neuron::neuronSpeed);
  }

  for (int x = 0; x <= 4; x++) {
    Serial.println(neuron1.actionPotential);
    delay(Neuron::neuronSpeed);
  }*/
  
 // neuron1.getFrequency(A0);
  
  //Serial.println("Cycle completed");
  
  // DETERMINE THE TYPE OF SIGNAL TYPE BEING RECIEVED
  
  // EXCITORY SIGNAL RECIEVED
  // SEND A SIGNAL BASED ON THE INPUT
  // SURRENTLY DOES NOT RESPECT "POTENTIAL"
  
  /*if (neuron1.signalType() == 1) {
    neuron1.excitory();
  }
  
  if (neuron1.signalType() == 2) {
    neuron1.inhibitory();
  }
  
  if (neuron1.signalType() == 0) {
    Serial.println("no signal");
  }
    
  if (neuron2.signalType() == 1) {
    neuron2.excitory();
  }
  
  if (neuron2.signalType() == 2) {
    neuron2.inhibitory();
  }
  
  if (neuron2.signalType() == 0) {
    Serial.println("no signal");
  }
  
  if (neuron3.signalType() == 1) {
    neuron3.excitory();
  }
  
  if (neuron3.signalType() == 2) {
    neuron3.inhibitory();
  }
  
  if (neuron3.signalType() == 0) {
    Serial.println("no signal");
  }
  
  if (neuron4.signalType() == 1) {
    neuron4.excitory();
  }
  
  if (neuron4.signalType() == 2) {
    neuron4.inhibitory();
  }
  
  if (neuron4.signalType() == 0) {
    Serial.println("no signal");
  }*/

}

