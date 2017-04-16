ArduinoNeuronLibrary
====================

Simulate neural activity with Arduino

The goal of this project is to create a neural network out of arduino boards.
The reason many boards are required is because of the need for neural networks
to be able to process information in parallel.

My reason for creating this is because I disagree with how many neural networks 
opperate. This network is designed to more accurately replicate the function of
biological neurons tham traditional neural networks. Traditional nodes such as the
ones used in common feedforward arcatecture only can weigh inputs that they are 
provided with.

Specifications:
- Each neuron can have an infinate number of potential connections.
- Each neuron cannot be aware of any of its connections.
- Neurons must fire randomly on occasion.
- Nurons must become inactive if unused for a period of time.
- Learning must be a emergant property of having many neurons together.


```

/*
I considered having the calibration run when the neuron begins,
or the neuron begin when the calibration has completed but It
turns out that it is important to have them seperate. The
neurons all need to calibrate in the setup loop. The ability
to begin and end activity in individual neurons is also
important.
*/


// GET THE FREQUENCY OF THE INCOMING SIGNAL
// http://tushev.org/articles/arduino/item/51-measuring-frequency-with-arduino

long Neuron::getFrequency(int pin) {
  int SAMPLES = 10;
  long freq = 0;
  for(unsigned int j=0; j<SAMPLES; j++) freq+= 50/pulseIn(pin, HIGH, 250);
  return freq / SAMPLES;
}

// CONTROLS A NEURONS ACTION POTENTIAL

boolean Neuron::actionPotentialProbability2(int excitory, int inhibitory) {
  
  // A current flaw is that the action potential does not regulate over time.
  // Neurotransmitters naturally ware off over time.

  // ESOTERIC FUNCTION TO RETURN A VALUE FOR A NEURONS ACTION POTENTIAL

  /*if ((excitory - lastExcitory) > (inhibitory - lastInhibitory)) {
   return true;
   }*/

  // SIGNAL TRIGGERED BASED ON PROBABILITY
  /*if () {
   return true;
   }*/

  return false;

}


/*
At first, I had thought that the key to allowing the neurons to
communicate was to set and read different frequencies. This
creates a problem because the Arduino platform does not have the
ability to continuously scan for an input signal. This was a
major obstical until I realized that it would be possible to
create a incremental varriable that corresponds to the cyclical
structure of the boards main method. By reading a cyclical
frequency I am able to read the different types of signals
correctly, but this also creates a new and very interesting
property. In order for the neurons to stay synchronized they
need to be listening when the correct cycle aproaches. This
desirable trait can be achieve by having each neuron wait for a
trigger signal beffore becoming active. This property of the 
artificial neurons may prove to mimic the way the human brain
will synchronize the firing of neurons to mimic sensory stimuli.
*/


// RECIEVE A SIGNAL FROM ANOTHER NEURON

int Neuron::signalType() {
  
  // READ THE BLINK SPEED OF THREE POSSIBLE SIGNALS
  // 0 = no singnal, not blinking
  // 1 = excitory, blinking fast
  // 2 = inhibitory, blinking slow
  
  // NO, not any more. NOW IT WILL BE PER CYCLE(S)
  
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

```
