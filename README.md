# Syma_Arduino
## Adding transmitter controllable components to Syma X5/X8 quadcopters with an Arduino/Arduino compatible board, via the camera port
---

### How it works:

Despite being in different shells, most models of the Syma X5 & X8 series quadcopters feature the same type of camera, controllable using the stock transmitter/radio. When the picture or video buttons are pressed on the transmitter a signal is sent to the camera via the yellow signal wire on the Syma.

The signal wire starts high (3.7v for X5 models, 5v for the X8's) dropping to 0v for _0.25 seconds_ for picture, and _0.75 seconds_ for video.

Using an small, lightweight Arduino/Arduino compatible board, this sketch reads the signal wire from the Syma and allows you to run your own code for components that you might want to add to the quad. (e.g. a [servo](https://github.com/EThornill/Syma_X5C_servo), extra LEDs, sensors, IR emitter etc.). These components can be controlled from the stock transmitter using the picture/video buttons.

The Arduino board can be soldered directly into the quads (for a more pearmeant setup) or utilise the different camera ports to make it removeable.


### Compatible Syma models:

The sketch has been tested on a Syma X5C using an [Adafruit Trinket (3.3 v)](https://www.adafruit.com/product/1500) to control a [servo](https://github.com/EThornill/Syma_X5C_servo), however this technique should also be applicable to the following models (please get in contact is this does or does not work for you):

**X5 Series**
- X5C/X5C-1 
- X5S/X5SW
- X5HW

! The X5UC/X5UW's are a noticeably different to older X5 models and use a new camera with 4 wires. It's not clear what kind of signal is sent to the camera to activate it.

**X8 Series**
- X8C/X8HC
- X8W/X8HW
- X8G/X8HG <-- Different camera, but signal _should_ be the same


### References

- Camera signal; [RCGroups](https://www.rcgroups.com/forums/showpost.php?p=31397718&postcount=5415)
- Code adapted from a ['hold button' sketch](http://playground.arduino.cc/Code/HoldButton)

