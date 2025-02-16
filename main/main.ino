//Really Simple Digital Instrument
//There are two tones: sine and square. There is one channel.
//Frequency is controlled by moving the y-axis of a joystick. To keep things consistent, it can only choose between 25 in-tune notes.
//Select the tone by moving the joystick to the left for sine or right for square.

#include <DacESP32.h>

const int jsX = A4;
const int jsY = A5;
const int jclick = 15;
const int buzzer = DAC1; //This is also technically the same thing as DAC_CHANNEL_1, but DAC1 is an int
const int rled = 33; //LEDs are for extra credit.
const int yled = 27;
const int gled = 12;

DacESP32 dac1(DAC_CHANNEL_1); //Using DacESP32 to interface with the cosine generator

float freq = 440; //Gotta be something in case the joystick doesn't connect or whatever

void setup() {
  Serial.begin(9600); //Expected frequency for "tuning"
  pinMode(rled,OUTPUT);
  pinMode(yled,OUTPUT);
  pinMode(gled,OUTPUT);
  pinMode(jclick,INPUT_PULLUP);
  digitalWrite(rled,1);
  digitalWrite(yled,0);
  digitalWrite(gled,0);
}

void loop() {
  int xIn = analogRead(jsX); //Read the x-axis input for wave selection
  int readf = map(analogRead(jsY),0,4095,-12,12); //Map the y-axis input to a set of notes on 2 octaves
  freq = 440*pow(2,(float)readf/12); //Calculate frequency using an equal-weight 12-note scale
  if (xIn < 1023) { //right push = square wave
    dac1.disable(); //Disable the sine wave connection
    tone(buzzer,freq); //Set the square-wave generator to the input frequency
    Serial.print("Current frequency: ");
    Serial.println(freq);
    digitalWrite(rled,0); //When the square wave is active, the green LED will light up.
    digitalWrite(yled,0);
    digitalWrite(gled,1);
  }
  else if (xIn > 3071) { //left push = sine wave
    noTone(buzzer); //Disable the tone connection
    dac1.enable(); //Re-enable the sine wave connection
    dac1.outputCW(freq*pow(2.0,-1.0/6.0)); //Set the cosine generator to the input frequency, tuned down 2 notes
    Serial.print("Current frequency: ");
    Serial.println(freq);
    digitalWrite(rled,0); //When the sine wave is selected, the yellow LED will light up.
    digitalWrite(yled,1);
    digitalWrite(gled,0);
  }
  else if (!digitalRead(jclick)) { //If you click the joystick button (mine might be slightly broken, so clicking the stick doesn't work well, but the button itself works), it stops playing.
    noTone(buzzer);
    dac1.disable();
    Serial.println("Stopped");
    digitalWrite(rled,1); //When no note is playing, the red LED will light up.
    digitalWrite(yled,0);
    digitalWrite(gled,0);
  }
  delay(50); //Just to give things time to breathe
}
