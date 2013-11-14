//#ifndef Neuron_h
//#define Neuron_h

#include <Arduino.h>

class Neuron {

public:
 Neuron(int analog, int digital);
 
 // SPEED OF NEURON OPERATION
 // SHULD BE CAPS
 const static int neuronSpeed = 250;
 
 // CYCLICAL FREQUENCY STATE
 int frequency;
 
 // BOOLEAN VALUE THAT ALLOWS NEURON TO BE TURNED OFF
 boolean active = false;

 // DENDRITES AND SYNAPTIC TERMINALS
 int analogPin;
 int digitalPin;
 
 // DENDRITE READING WHEN TERMINALS SET TO LOW OR HIGH
 int calibratedAmountLow;
 int calibratedAmountHigh;
 
 int actionPotential;

 void calibrate();
 void start();


 boolean actionPotentialProbability2();
 boolean actionPotentialProbability(int excitory, int inhibitory);
 
 int signalType();
 long getFrequency(int pin);
 long setFrequency(int pin);

 void excitory();
 void inhibitory();
 
 int dendrite();
 int terminal();

};

