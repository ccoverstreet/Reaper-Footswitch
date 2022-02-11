# Reaper Footswitch

This project is a ATmega32u4 based footswitch for sending keyboard commands to a computer. The primary use case is for sending keys to a DAW (Reaper in this case) to change which track is armed. This allows for switching between guitar tones easily without needing to press any keys and makes using guitar amp sims feel closer to the real thing.

## Parts

- ATmega32u4 based microcontroller (pick based on IO needs)
- USB to USB Micro-B cable
- USB Micro-B panel mount [here](https://www.mouser.com/ProductDetail/474-CAB-15464)
- Momentary foot switches [here](https://www.mouser.com/ProductDetail/107-SF12011F-M)
- Protoboard (or breadboard)
- Frame/box material (whatever works)
- 22 AWG wire
- 2k Ohm resistors (same as number of foot switches)


## Circuit Diagram

![Circuit Diagram](/assets/reaper_footswitch_diagram.png)

## Arduino Code

The code for the leonardo type arduino is located within [reaper_leonardo](/reaper_leonardo). 

The number of switches and keystrokes sent by the controller can be customized depending on your needs. It is recommend to read the header file of the `Keyboard` arduino library to get an idea of what keystrokes are possible. 

The main loop of the microcontroller works by polling all the specified pins (for footswitches) and only sending a keyboard command when a different switch is pressed. The response time of the microcontroller is imperceptible and meets the requirements for a music application. 

An interrupt-based approach was trialed, but showed worse performance on the available arduino pro-micros. Initial latency with the interrupt approach was marginally lower but resulted in inconsistent state (unable to track current pin). This behavior led to unecessary keystrokes being send resulting in noticeable lag time in subsequent presses. The interrupt approach would also require a common interrupt line between all the switches, which would slightly increase the wiring complexity of the system.

### Uploading

The Arduino IDE or `arduino-cli` can be used to upload the sketch to the board.

For the Arduino CLI, make sure to attach the sketch to the correct board. The makefile in the sketch directory will compile and upload the sketch

