#include <Control_Surface.h>

USBMIDI_Interface midi;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
}

const AddressMatrix<1, 8> notes {{
    {60,61,62,63,64,65,66,67},
}};

NoteButtonMatrix<1,8> matrix {
    {6},
    {mux.pin(0),mux.pin(1),mux.pin(2),mux.pin(3),mux.pin(4),mux.pin(5),mux.pin(6),mux.pin(7),},
    notes,
    CHANNEL_1,
};

void setup() {
    Control_Surface.begin();
}

void loop() {
    Control_Surface.loop();
}