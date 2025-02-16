Charles Kahn

# Lab 5: Integration Exploration

This is the fourth assignment working with the ESP32.

In this lab, we used a sensor to affect the behavior of an actuator. I chose a joystick and a buzzer.

Code is flashed to the ESP32 via Arduino IDE. My MD editor is vim, my OS is Windows, and code is written in the AIDE.

This submission uses the two analog outputs from the joystick to select a frequency and a waveform. If the joystick is on the right side, the buzzer will receive a square wave. If the joystick is on the left side, it will receive a sine wave. This means I technically made a 2-tone 1-channel synthesizer. The y position of the joystick determines the frequency played, discretized to 25 notes across 2-ish octaves.

To accomplish this, I used the Arduino IDE's tone() function to control the square wave and the DacESP32 library to control the sine wave produced by the ESP32's cosine function generator. I then had to make the argument for the cosine frequency one whole step lower than the actual frequency, because the cosine generator seems to output a wave of a frequency a certain amount higher than requested.

The code for this main routine is in [main.ino](main/main.ino).

To make sure that all the code I was writing for that would work properly, I also created a joystick tester sketch. This confirmed, without annoying sounds, that the correct orientation of the joystick for this purpose is with the wires on the right, because I don't want to deal with pullup logic.

The code for this tester is in [joystick\_test.ino](joystick_test/joystick_test.ino).

For the extra credit, I decided to use the LED traffic light as a simple information readout. Because it was driving me insane, I decided to add a stop-playing function tied to the button on the joystick. Red means stopped, yellow means sine, and green means square. I didn't keep it separate from the normal-credit stuff because it's difficult to separate and easy to notice and comment out.
