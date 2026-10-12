Charles Kahn

# Really Simple Digital Instrument

This is an Arduino sketch, originally from an academic assignment, for a simple musical instrument composed of an ESP32, a joystick, and a passive buzzer.

The instrument uses the two analog outputs from the joystick to select a frequency and a waveform. If the joystick is on the right side, the buzzer will receive a square wave. If the joystick is on the left side, it will receive a sine wave. The vertical position determines the frequency of the buzzer, discretized to 25 notes.

Square wave generation uses Arduino's tone() function and sine wave generation uses the DACESP32 library to take advantage of the ESP32's built in cosine generator. The sine wave is then pitched down one whole step to match the frequency of the square wave.

The code for this main routine is in [main.ino](main/main.ino).

This repository also includes a joystick tester sketch in order to determine the correct orientation of the joystick. The code for this tester is in [joystick\_test.ino](joystick_test/joystick_test.ino).

## Setup

Currently, this requires:

- Adafruit ESP32 Feather V2 microcontroller
- Dual-axis thumbstick supporting 3.3V Vcc
- Single channel passive buzzer (also 3.3V)

Pins are connected as follows:

- Joystick x: Pin A4
- Joystick y: Pin A5
- Passive Buzzer: DAC1 (Pin A1)

All pin references are for the Adafruit ESP32 Feather V2 microcontroller. These values may be substituted for equivalent analog inputs and DAC outputs on other platforms, but the sketch must be modified to do so.

## Optional Features

If the joystick used has a clicking function, or an additional button is added, clicking it will cause the instrument to stop playing. The button input is assigned to the Feather V2's pin 15.

The device can also support an LED readout with three lights, only one of which is on at any one time. The first means stopped, the second means sine, and the third means square. The first LED is assigned to Pin 33, the second to Pin 27, and the third to Pin 12.

## TODO

- Add circuit diagrams to README
- Allow other ESP32 boards (possible support for non-ESP32 as well)
- Output over USB
- Transition away from Arduino IDE
