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

/*NoteButton notes[] {
  {mux.pin(0), {60, CHANNEL_1}},
  {mux.pin(1), {61, CHANNEL_1}},
  {mux.pin(2), {62, CHANNEL_1}},
  {mux.pin(3), {63, CHANNEL_1}},
  {mux.pin(4), {64, CHANNEL_1}},
  {mux.pin(5), {65, CHANNEL_1}},
  {mux.pin(6), {66, CHANNEL_1}},
  {mux.pin(7), {67, CHANNEL_1}},
  {mux.pin(8), {68, CHANNEL_1}},
  {mux.pin(9), {69, CHANNEL_1}},
};*/

NoteButtons<10> notes {
 {mux.pin(0), mux.pin(1), mux.pin(2), mux.pin(3), mux.pin(4), mux.pin(5), mux.pin(6), mux.pin(7), mux.pin(8),mux.pin(9)}, //array of pins
 {60, CHANNEL_1}, //address of first button
  1, //increment size
  127, //velocity
};
  
  // Initialize the Control Surface
void setup() {
  Control_Surface.begin();
}
 
// Update the Control Surface
void loop() {
  Control_Surface.loop();
}
