#include "Neuron.h"

/*
 ** ARDUINO NEURON
 ** BY GUNTHER COX
 ** 09/15/2013
 */

// SPEED OF NEURON OPERATION
int neuronSpeed = 50;
  
// CREATE NEW NEURONS
Neuron neuron1(A0, 6);
Neuron neuron2(A1, 5);
Neuron neuron3(A2, 4);
Neuron neuron4(A3, 3);

void setup() {
  
  // SET DENDRITES AS INPUTS AND SYNAPTIC TERMINALS AS OUTPUT
  pinMode(neuron1.get_dendrite(), INPUT);
  pinMode(neuron1.get_terminal(), OUTPUT);
  
  pinMode(neuron2.get_dendrite(), INPUT);
  pinMode(neuron2.get_terminal(), OUTPUT);

  pinMode(neuron3.get_dendrite(), INPUT);
  pinMode(neuron3.get_terminal(), OUTPUT);
  
  pinMode(neuron4.get_dendrite(), INPUT);
  pinMode(neuron4.get_terminal(), OUTPUT);

  Serial.begin(9600);
  Serial.println("Arduino Neuron Inilalized");
  delay(neuronSpeed);
  
  // CALIBRATE NEURONS
  neuron1.calibrate();
  neuron2.calibrate();
  neuron3.calibrate();
  neuron4.calibrate();
}

void loop() {

  // READ DENDRITE VALUES
  for (int w = 0; w <= 4; w++) {
    neuron1.actionPotential = analogRead(neuron1.get_dendrite());
    delay(neuronSpeed);
  }

  for (int x = 0; x <= 4; x++) {
    Serial.println(neuron1.actionPotential);
    delay(neuronSpeed);
  }
  
  neuron1.excitory();
  neuron2.inhibitory();
  neuron3.excitory();
  neuron4.inhibitory();

}
