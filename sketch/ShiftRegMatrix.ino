#include <Control_Surface.h>

USBMIDI_Interface midi;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
}
pin_t monitor = 6

Timer<millis> timer(25)

NoteButton buttons[] {
    {mux.pin(0), {note(C, 4), CHANNEL_1}, 127},
    {mux.pin(1), {note(D, 4), CHANNEL_1}, 127},
    {mux.pin(2), {note(E, 4), CHANNEL_1}, 127},
    {mux.pin(3), {note(F, 4), CHANNEL_1}, 127},
}

void setup() {
    pinMode(monitor, INPUT)
    Control_Surface.begin();
}

void loop(){
    Control_Surface.loop();
/*
Action 1: write all outputs high but one (011111 or 7F or 127) (here's the linchpin? doing bit manipulation inside of ControlSurface?)
Action 2: if reading pin == low, return button::falling, else button::rising
Action 3: shift low pin over by one
*/

if (timer) {
    for (uint8_t i = 0; i < mux.length(); i++) {
        for (uint8_t j = 0; j < mux.lentgh(); j++) { //write all high
            digitalWrite(mux.pin(j), HIGH)
        }
    digitalWrite(mux.pin(i), LOW) //set target low
    if (digitalRead(monitor) == LOW) { //the thought here is we're writing outputs only above; in order for these buttons to recieve input they need to be manually written
        button[i].update() == AH::Button::Falling
    } else { buttons[i].update() == AH::Button::Rising
    }
}
}
}