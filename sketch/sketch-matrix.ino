#include <Control_Surface.h>

USBMIDI_Interface midi;

const addressmatrix<5,2> notes {{
    {60,61,62,63,64},
    {65,66,67,68,69}
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