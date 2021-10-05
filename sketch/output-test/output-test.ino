#include <Control_Surface.h>
 
using namespace ExtIO; //without this declared I can't write to extended pins

USBMIDI_Interface midi;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
};

void setup() {
    Control_Surface.begin();
}

void loop(){
  /*
//move the lit LED down the line every half second
for (uint8_t i = 0; i < 4; i++) {
    digitalWrite(mux.pin(i), HIGH);
    delay(500);
    digitalWrite(mux.pin(i), LOW);
}
// second test, to write all pins using buffer, then update after a delay
if (digitalRead(mux.pin(0)) == LOW) {
  for (uint8_t i = 0; i < 4; i++)
    digitalWriteBuffered(mux.pin(i), HIGH);
} else {
  for (uint8_t i = 0; i < 4; i++)
    digitalWriteBuffered(mux.pin(i), LOW);
}
delay(500);
updateBufferedOutputs(); //for whatever reason this function is seen as not declared
*/

//third test, should actually behave exactly as second (it does--er. I think. The buffered functions don't seem to be working.)
if (digitalRead(mux.pin(0)) == LOW) {
  for (uint8_t i = 0; i < 4; i++)
    digitalWrite(mux.pin(i), HIGH);
} else {
  for (uint8_t i = 0; i < 4; i++)
    digitalWrite(mux.pin(i), LOW);
}
delay(500);
}
