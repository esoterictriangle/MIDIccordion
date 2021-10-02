#include <Control_Surface.h>

USBMIDI_Interface midi;

const AddressMatrix<5, 2> notes {{
    {60,65},
    {61,66},
    {62,67},
    {63,68},
    {64,69},
}};

NoteButtonMatrix<5,2> matrix {
    {3,4,5,6,7},
    {8,9},
    notes,
    CHANNEL_1,
};

void setup() {
    Control_Surface.begin();
}

void loop() {
    Control_Surface.loop();
}
