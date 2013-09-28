//#ifndef Neuron_h
//#define Neuron_h

#include <Arduino.h>

class Neuron {

public:
 Neuron(int analog, int digital);
 
 // SPEED OF NEURON OPERATION
 const static int neuronSpeed = 250;

 // DENDRITES AND SYNAPTIC TERMINALS
 int analogPin;
 int digitalPin;
 
 // DENDRITE READING WHEN TERMINALS SET TO LOW OR HIGH
 int calibratedAmountLow;
 int calibratedAmountHigh;
 
 // A current flaw is that the action potential does not regulate over time.
 // Neurotransmitters naturally ware off over time.
 int actionPotential;

 void calibrate();

 boolean actionPotentialProbability(int excitory, int inhibitory);
 
 int signalType();
 long getFrequency(int pin);
 long setFrequency(int pin);

 void excitory();
 void inhibitory();
 
 // RETURN NEURON PINS
 int get_dendrite();
 int get_terminal();

};
