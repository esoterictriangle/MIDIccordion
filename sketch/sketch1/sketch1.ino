#include <Control_Surface.h>

USBMIDI_Interface midi;

Timer<millis> timer = 10;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
};

const MIDIAddress note_0 {60, CHANNEL_1};
const MIDIAddress note_1 {61, CHANNEL_1};
const MIDIAddress note_2 {62, CHANNEL_1};
const MIDIAddress note_3 {63, CHANNEL_1};
const MIDIAddress note_4 {64, CHANNEL_1};
const MIDIAddress note_5 {65, CHANNEL_1};
const MIDIAddress note_6 {66, CHANNEL_1};
const MIDIAddress note_7 {67, CHANNEL_1};

void setup() {
    pinMode(6, INPUT);
    Control_Surface.begin();
}

void loop(){
    Control_Surface.loop();
    if(timer) {
        for(int j=0; j<50; j++)
        delayMicroseconds(1000);

        byte check = 1;
        for (int i = 0; i < 8; i++) {
            digitalWrite(mux.pin(check), HIGH);
            if (digitalRead(6) == HIGH)
                midi.sendNoteOn(i, 127);
            else
                midi.sendNoteOff(i, 0);

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
