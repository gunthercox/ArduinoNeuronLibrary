#include <Arduino.h>

class Neuron {

public:
 Neuron(int analog, int digital);
 
 // SPEED OF NEURON OPERATION
 const static int SPEED = 150;
 
 // BOOLEAN VALUE THAT ALLOWS NEURON TO BE TURNED OFF
 boolean active = false;

 // DENDRITES AND SYNAPTIC TERMINALS
 int analogPin;
 int digitalPin;
 
 int calibratedAmountLow;
 int calibratedAmountHigh;
 
 void calibrate();
 void start();
 void terminate();

 int actionPotential = 0;
 boolean actionPotentialProbability();
 
 void excitory();
 void inhibitory();
 
 int dendrite();
 int terminal();

};

