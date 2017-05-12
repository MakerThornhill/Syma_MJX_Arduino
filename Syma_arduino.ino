
/*******************************************************************
  Reading Syma X5/X8 series camera signal
*******************************************************************
  Written by: Thornhill (https://github.com/EThornill)

  This sketch reads the signal wire from the Syma X5/X8 series of
  quadcopters and allows you to run your own code for other components
  that you might want to add (e.g. a servo, extra LEDs, sensors, 
  IR emitter etc.).

  Because there are two kinds of signal (picture, and video) you have
  two buttons on the transmitter to control these components.

 *******************************************************************

  Detecting the camera signal was adapted from a 'hold button'
  sketch at http://playground.arduino.cc/Code/HoldButton

 *******************************************************************/

int signal = 7; // The signal from the Syma signal wire

int current;         // Current state of the button
                     // (LOW is pressed b/c i'm using the pullup resistors)
long millis_held;    // Duration of signal (milliseconds)
long secs_held;      // Duration of signal (seconds)
long prev_secs_held; // Duration previously
byte previous = HIGH;
unsigned long firstTime; // how long since the signal was detected


void setup() 
{ 
  digitalWrite(signal, HIGH);
}

void loop() {
  current = digitalRead(signal);
  
  //--------------- Reading the camera signal ----------------
  //----------------------------------------------------------

  // if the state changes to low signal, remember the start time 
  if (current == LOW && previous == HIGH && (millis() - firstTime) > 200) {
    firstTime = millis();
  }

  millis_held = (millis() - firstTime);
  secs_held = millis_held / 1000;

  //debouncing tool... the low signal must have a duration for at least 100 milliseconds to be considered
  if (millis_held > 100) {
   
    // check that the low signal returned to high since we last checked
    if (current == HIGH && previous == LOW) {
      
      //------------ Controlling different components ------------
      //----------------------------------------------------------
 
      // PICTURE BUTTON (Low signal from Camera, 0.15 - 0.35s)
      if (millis_held > 150  && millis_held < 350) { 

        //Your code here

      } //end_if picture
      
     // VIDEO BUTTON (low signal from Camera, ~0.75s)
      if (millis_held > 500) {

      //Your code here
        
      }//end_if video
 
      //----------------------------------------------------------
      //----------------------------------------------------------
      
      }
  }

  previous = current;
  prev_secs_held = secs_held;
} //end loop

