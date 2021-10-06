#include <Control_Surface.h>
using namespace ExtIO;

USBMIDI_Interface midi;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
};
pin_t monitor = 6;

Timer<millis> timer(25);

NoteButton buttons[] {
    {mux.pin(0), {60, CHANNEL_1}, 127},
    {mux.pin(1), {61, CHANNEL_1}, 127},
    {mux.pin(2), {62, CHANNEL_1}, 127},
    {mux.pin(3), {63, CHANNEL_1}, 127},
};

void setup() {
    pinMode(monitor, INPUT_PULLUP); //PULLUP leaves everything off always. Regular INPUT makes LEDs flash very quickly (related to timer?) and then turn off when any button is held.
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
    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 4; j++) { //write all high
            digitalWrite(mux.pin(j), HIGH);
        }
    digitalWrite(mux.pin(i), LOW); //set target low
    if (digitalRead(monitor) == LOW) {
        digitalWrite(mux.pin((i + 4)), HIGH); //turn on LED on register pins 4-8
    } else { digitalWrite(mux.pin((i+4)), LOW); //turn off LED
    }
}
}
}
/*
void shiftRegisterMatrix() {
    for (uint8_t i = 0; i < mux.length(); i++) {
        for (uint8_t j = 0; j < mux.length(); j++) { //write all high
            digitalWrite(mux.pin(j), HIGH);
        }
    digitalWrite(mux.pin(i), LOW); //set target low
    if (digitalRead(monitor) == LOW) { //the thought here is we're writing outputs only above; in order for these buttons to recieve input they need to be manually written
        //action to write the button falling/play the correct note/do the thing
    } else { //action to write the button rising/stop the note/undo the thing
    }
}
}
*/
