#include <Control_Surface.h>
using namespace ExtIO; //try commenting this out if this works

USBMIDI_Interface midi;

const AddresssMatrix<8,1> addresses {{
    {60},
    {61},
    {62},
    {63},
    {64},
    {65},
    {66},
    {67},
}};

ShiftRegisterOut<8> sreg {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
};

NoteButtonMatrix<8,1> keyboard {
    {sreg.pin(0), sreg.pin(1), sreg.pin(2), sreg.pin(3), sreg.pin(4), sreg.pin(5), sreg.pin(6), sreg.pin(7)}, //rows--output
    {6}, //column
    addresses,
    CHANNEL_1,
};

void setup() {
    Control_Surface.begin();
}

void loop(){
    Control_Surface.loop();
}