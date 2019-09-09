# IDD-Fa18-Lab1: Blink!

**A lab report by Meera Nanda**

## Part A. Set Up a Breadboard

View from the top:\
![Breadboard Top](/images/PartA_BreadboardTop.png){:height="200px"}

View from an angle:\
![Breadboard Side](/images/PartA_BreadboardAngle.png){:height="100px"}


## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**\
100 Ohm = Brown, Black, Brown.
 
**b. What do you have to do to light your LED?**\
The circuit needs to be complete in order to light the LED, so in this case the switch needs to be pushed down. Below are photos of the implemented circuit, and a video of the switch in action:

![Circuit Top](/images/PartB_BreadboardTop.png)
![Circuit Angle](/images/PartB_BreadboardAngle.png)


## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**\
In the Arduino built-in Blink example, no changes need to be made to the code in order to make the LED blink. However, the line of code that causes the blink is:

digitalWrite(LED_BUILTIN, HIGH); 

By setting the built-in LED's voltage to high, it causes LED to light up.


**b. What line(s) of code do you need to change to change the rate of blinking?**\
The line of code that needs to change to change the rate of blinking is the delay() function: 

delay(1000); 

Currently it is set to 1000ms, or 1 second. We can change this to 100ms to increase the blink rate.


**c. What circuit element would you want to add to protect the board and external LED?**\
A resistor would protect the board and the LED from potentially experiencing a short circuit.
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**\
At a delay of approximately 10ms, I can no longer perceive the LED blinking. We can prove that it still is however, using a logger within the system. Using the code below, I logged each time the voltage on the LED was set to high and to low in order to ensure there was a blink still occuring. 

[Code snippet](/code/MyBlink.ino):

Output screenshot:


**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

[Code snippet](/code/MyBlink.ino):
```c
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for 100ms
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for 2 seconds
}

```

Below is a video of the built-in LED blinking:


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

[link to your video here; feel free to upload to youtube and just paste in a link here]


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**\
Yes, the LED glows through the whole turning range of the potentiometer. At it's highest resistance it still emits a very faint glow. This is because there is still a small amount of current in the circuit despite there being the resistance from the potentiometer and the 220 Ohm resistor.

Below is a video of the implemented circuit:


## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**\
I had to modify the output pin from 9 to 11, which is where the external LED is connected. See the updated code [here](/code/NewFade.ino), or a snippet below:

Original line:
```c
int led = 9; 
```

New line:
```c
int led = 11; 
```

**b. What is analogWrite()? How is that different than digitalWrite()?**\
analogWrite() writes an analog value to a pin, and therefore allows a range of values as inputs. In the case of an LED, it can be used to lit it at varying brightness levels ranging from 0-255. Using digitalWrite() only allows you to set the state of a pin to either HIGH or LOW.

Funky Fade:
```c
/*
  New Fade

  This example shows how to fade an LED on pin 11 using the analogWrite()
  function.

*/

int led = 11;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 12;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 11 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 11:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(100);
}
```

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 
For this section, I used an old radio remote controller:
![Radio Remote](/images/PartF_1_RemoteOutside.png)
![Radio Remote Circuit](/images/PartF_1_RemoteInside.png)

Below are the schematics:
![Radio Remote Schematics](/images/PartF_1_RemoteSchematics.png)


**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**\
There is no computation device within the remote. 

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**\
There are no sensors, only buttons within the remote. As they are pressed, information is encoded to an infrared transmitter that conveys that information to the radio unit, which then decodes the infrared transmission.

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**\
The device is powered by a 3V lithium battery. There is a capacitor that is regulating the power.

**d. Is information stored in your device? Where? How?**\
Information is not stored in this device during usage. 

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**\
I tracked where the power was flowing through in the remote and tested the LED at various points in the circuit. Initially I thought it would be easiest to test the LED where the infrared diode is positioned at the top of the remote. However, at this point in the circuit the infrared diode only emits light when a button is pressed, and I wanted to see a continuous flow of current through my external LED. So I instead positioned the LED in series with the capacitor in the circuit. See below for the video and schematics.

### 3. Build your light!
![FrankenRemote](/images/PartF_3_Frankenlight.png)

**Make a video showing off your Frankenlight.**


**Include any schematics or photos in your lab write-up.**
