#include <Control_Surface.h>

USBMIDI_Interface midi;

Timer<millis> timer = 10;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
}

NoteButton scale {
    {mux.pin(0), {MIDI_Notes::C(4), CHANNEL_1}, velocity=127},
    {mux.pin(1), {MIDI_Notes::D(4), CHANNEL_1}, velocity=127},
    {mux.pin(2), {MIDI_Notes::E(4), CHANNEL_1}, velocity=127},
    {mux.pin(4), {MIDI_Notes::F(4), CHANNEL_1}, velocity=127},
    {mux.pin(5), {MIDI_Notes::G(4), CHANNEL_1}, velocity=127},
    {mux.pin(6), {MIDI_Notes::A(4), CHANNEL_1}, velocity=127},
    {mux.pin(7), {MIDI_Notes::B(4), CHANNEL_1}, velocity=127},
    {mux.pin(8), {MIDI_Notes::C(5), CHANNEL_1}, velocity=127},
};

void setup() {
    pinMode(2, Input);
    Control_Surface.begin();
}

void loop(){
    Control_Surface.loop();
    if(timer) {
        for(j=0; j<50; j++)
        delayMicroseconds(1000);

        check=1;
        for (i = 0; i < 8; i++) {
            mux.digitalWrite(check, HIGH);
            if (digitalRead(6) == HIGH)
                digitalWrite(i, HIGH);
            else
                digitalWrite(i, LOW);

        check = check<<1;
        }
    }
}

/*
bit from kevindarrah's output scan example:
for(j=0; j<50; j++)
    delayMicroseconds(1000);

    Check=1;
    for(j=0; j<8; j++){
  SPI.transfer(Check);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  delayMicroseconds(500);
  if(digitalRead(2)==HIGH)
      bitWrite(Output, j, 1);
  else
      bitWrite(Output, j, 0);
  
  
  Check = Check<<1;
    }//j

https://wbsimms.com/use-74hc595-monitor-many-digital-inputs/
https://tttapa.github.io/Control-Surface-doc/Doxygen/df/d9e/2_8RGB-LED-Chaser_8ino-example.html
https://forum.arduino.cc/t/74hc595-used-for-shift-input-not-output/160028/3
https://www.kevindarrah.com/download/arduino_code/ShiftRegisterInput2_piano.ino
*/
