#include <Control_Surface.h>

USBMIDI_Interface midi;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
}

void setup() {
    mux.begin()
}

void loop(){
//should move the lit LED down the line every half second
for (uint8_t i = 0; i < 4; i++) {
    digitalWrite(mux.pin(i), HIGH);
    delay(500);
    digitalWrite(mux.pin(i), LOW);
}
/* second test, to write all pins using buffer, then update after a delay
if (digitalRead(mux.pin(0)) == LOW) {
    digitalWriteBuffered({mux.pin(0), mux.pin(1), mux.pin(2), mux.pin(3)}, HIGH);
} else {
    digitalWriteBuffered({mux.pin(0), mux.pin(1), mux.pin(2), mux.pin(3)}, LOW);
}
delay(500);
updateBufferedInputs()

*/

/* third test, should actually behave exactly as second
if (digitalRead(mux.pin(0)) == LOW) {
    digitalWrite({mux.pin(0), mux.pin(1), mux.pin(2), mux.pin(3)}, HIGH);
} else {
    digitalWrite({mux.pin(0), mux.pin(1), mux.pin(2), mux.pin(3)}, LOW);
}
delay(500);

*/
}