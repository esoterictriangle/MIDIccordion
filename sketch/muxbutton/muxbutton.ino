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

NoteButton notes[] {
  {mux.pin(0), {MIDI_Notes::C(4), CHANNEL_1}},
  {mux.pin(1), {MIDI_Notes::D(4), CHANNEL_1}},
  {mux.pin(2), {MIDI_Notes::E(4), CHANNEL_1}},
  {mux.pin(3), {MIDI_Notes::F(4), CHANNEL_1}},
  {mux.pin(4), {MIDI_Notes::G(4), CHANNEL_1}},
  {mux.pin(5), {MIDI_Notes::A(4), CHANNEL_1}},
  {mux.pin(6), {MIDI_Notes::B(4), CHANNEL_1}},
  {mux.pin(7), {MIDI_Notes::C(5), CHANNEL_1}},
  {mux.pin(8), {MIDI_Notes::D(5), CHANNEL_1}},
  {mux.pin(9), {MIDI_Notes::E(5), CHANNEL_1}},
};
  
  // Initialize the Control Surface
void setup() {
  Control_Surface.begin();
}
 
// Update the Control Surface
void loop() {
  Control_Surface.loop();
}
