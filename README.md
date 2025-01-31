# IDD-Fa18-Lab1: Blink!

**A lab report by Meera Nanda**

## Part A. Set Up a Breadboard

![Breadboard Top](/images/PartA_BreadboardTop.png)


## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**\
100 Ohm = Brown, Black, Brown.

1. The first Brown is for the first digit, 1
1. Black is for the second digit, 0
1. The second Brown is for the multiplier, 10

Therefore we end up with 10x10=100 Ohms. Depending on the color of the 4th band, the resistor will have certain tolerance number as well, e.g. if the fourth band is gold then the resistor will have a tolerance of 5%.
 
**b. What do you have to do to light your LED?**\
The circuit needs to be complete in order to light the LED, so in this case the switch needs to be pushed down. Below are photos of the implemented circuit, and a video of the switch in action:

![Circuit Angle](/images/PartB_BreadboardAngle.png)

[Switch Video](https://youtu.be/ZZL-1xwhWc4)


## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**\
In the Arduino built-in Blink example, no changes need to be made to the code in order to make the LED blink. However, the line of code that causes the blink is:

```c
digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
```

By setting the built-in LED's voltage to high, it causes LED to light up.


**b. What line(s) of code do you need to change to change the rate of blinking?**\
The line of code that needs to change to change the rate of blinking is the delay() function: 

```c
delay(1000); 
```

Currently it is set to 1000ms, or 1 second. We can change this to 100ms to increase the blink rate.


**c. What circuit element would you want to add to protect the board and external LED?**\
A resistor would protect the board and the LED.
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**\
At a delay of approximately 10ms, I can no longer perceive the LED blinking. We can prove that it still is blinking however, by using a logger within the system. Using the code below, I logged each time the voltage on the LED was set to high and to low in order to ensure there was a blink still occuring. 

[Code snippet](/code/MyBlink.ino):
```c
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial monitor to log messages
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.write("On"); // print when LED is lit
  delay(10);                       // wait for 10ms
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  Serial.write("Off"); // print when LED is not lit
  delay(10);                       // wait for 10ms
}
```

Output screenshot:
![Serial Monitor Screenshot](/images/PartC_SerialMonitor.png)

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

[MyBlink Code](/code/MyBlink.ino)

Below is a video of the built-in LED blinking with the new code:

[Built-In LED Blink Video](https://youtu.be/Mj07bMg7gBw)


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

[External LED Blink Video](https://youtu.be/zyHayApGkGg)


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**\
Yes, the LED glows through the whole turning range of the potentiometer. At it's highest resistance it still emits a very faint glow. This is because there is still a small amount of current in the circuit despite there being the resistance from the potentiometer and the 220 Ohm resistor.

Below is a video of the implemented circuit:

[Manual Fade Video](https://youtu.be/M1O6f0q4NR4)

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
analogWrite() writes an analog value to a pin, and therefore allows a range of values as inputs. In the case of an LED connected to a pin, analogWrite() can be used to light it at varying brightness levels ranging from 0-255. Using digitalWrite() only allows you to set the state of a pin to either HIGH or LOW, meaning voltage or no voltage.

[Funky Fade Code](/code/NewFade.ino):
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
  // wait for 100 milliseconds to see the dimming effect
  delay(100);
}
```

Below is a video of the Arduino controlled fade:

[Arduino Fade Video](https://youtu.be/KBfzRxoezfQ)


## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 
For this section, I used an old radio remote controller:
![Radio Remote](/images/PartF_1_Remote.png)

Below are the system diagram and schematics:
![Radio Remote System Diagram](/images/PartF_1_RemoteSystemDiagram.png)


**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**\
There is no computation device within the remote. 

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**\
There are no sensors, only buttons within the remote. As they are pressed, information is encoded to an infrared transmitter that conveys that information to the radio unit, which then decodes the infrared transmission.

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**\
The device is powered by a 3V lithium battery. There is a capacitor that is regulating the power.

**d. Is information stored in your device? Where? How?**\
Information is not stored in this device while it is being used.

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**\
I tracked where the power was flowing through in the remote and tested the LED at various points in the circuit. Initially I thought it would be easiest to test the LED where the infrared LED is positioned at the top of the remote. However the LED did not light up at this location. So I instead positioned the LED in parallel with the capacitor in the circuit. See below for the video and new schematics.

### 3. Build your light!
![Updated Schematics](/images/PartF_3_FrankenlightSchematics.png)

**Make a video showing off your Frankenlight.**

[Frankenlight Video](https://youtu.be/-qDKHVOmNlA)


**Include any schematics or photos in your lab write-up.**
