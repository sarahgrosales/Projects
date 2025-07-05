// This code is meant to progressively turn on and off an LED or multiple.

const int RED = 6;       // Uses digital #6
const int ORANGE = 5;    // Uses digital #5
const int YELLOW = 3;    // Uses digital #3

const int wait = 10;     // Sets wait as 10 miliseconds.

void setup()             // Happens only once, the arduino hunts for setup.
  { 
    pinMode(RED, OUTPUT);        // Tells the LED to Output. 
    pinMode(ORANGE, OUTPUT);     // Tells the LED to Output. 
    pinMode(YELLOW, OUTPUT);     // Tells the LED to Output. 
}

void loop(){                      // Starts after void setup.

    for (int i = 0; i < 250; i++){        // This for loop progressively increases the brightness of the LED. (Max is 250)
	analogWrite(RED, i);            // Tells the LED to be set to the brightness.
      	analogWrite(ORANGE, i);         // Tells the LED to be set to the brightnes.
      	analogWrite(YELLOW, i);         // Tells the LED to be set to the brightness. 
        delay (wait);                   // Wait 10 miliseconds.
    }
    for (int i = 250; i > 0; i--){      // This for loop progressively decreases the brightness of the LED. 
    	analogWrite(RED, i);
      	analogWrite(ORANGE, i);
      	analogWrite(YELLOW, i);
        delay (wait);
     } 
  }

