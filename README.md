# IR_RC_LIGHT_CONTROL

 Arduino code for controlling dimmer switches with a servo and an arduino V0.5
 
 This is just a prototype and a proof of concept for me, excuse the badly annotated code and lack of a built in function to print the inputs the arduino is using; it was never designed for anything more than personal use.
 
 
 FUTURE VERSIONS:
 
 Later versions will be wifi controlled instead of IR remote controlled to remove the inherent limitations of IR communication.
 I also plan on adding a transistor to reduce the current drain on the idle servo and reduce the clockspeed to reduce current drain also.
 
 As this is only a prototype I will not upload the thingiverse files I used to make a 3D printed mount to attach everything to my dimmer switch/lightswitch, however when I complete this project properly all of this will be included.
 
 THINGS TO BEAR IN MIND WHEN MAKING YOUR OWN:
 
 You will need to identify which buttons on your remote control you would like to use and then what hexadecimal values are read by the IR sensor on the arduino and then modify the code to change the servo position as needed.
 It is important to identify all of the values which can be read by the arduino when one button is pushed on your remote, as in my case there were two different hexadecimal readouts from the same button push and this is likely to be the case with yours also
 
 ADIOS MAKERS:
 
 I love all of you!! Keep making fun stuff! Keep smiling! and YOU'RE BREATHTAKING!
 
 - TomTheTerriblyTerifficTragedy
