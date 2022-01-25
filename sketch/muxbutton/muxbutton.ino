// Include the library
#include <Control_Surface.h>
 
// Instantiate a MIDI Interface to use
USBMIDI_Interface midi;
 
// Instantiate an analog multiplexer
CD74HC4067 mux {
  A10,              // analog pin
  {21, 20, 19, 18}, // Address pins S0, S1, S2, S3
  // 7, // Optionally, specify the enable pin
};

NoteButton {
  
};
  
  // Initialize the Control Surface
void setup() {
  Control_Surface.begin();
}
 
// Update the Control Surface
void loop() {
  Control_Surface.loop();
}
