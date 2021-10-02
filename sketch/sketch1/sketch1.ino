#include <Control_Surface.h>

USBMIDI_Interface midi;

byte check;
int i;

Timer<millis> timer = 10;

ShiftRegisterOut<8> mux {
    7, //data (DS or SER)
    8, //clock (SH_CP or SRCLK)
    9, //latch (ST_CP or RCLK)
    MSBFIRST
};

NoteButton scale[] {
    {mux.pin(0), {60, CHANNEL_1}, 127},
    {mux.pin(1), {61, CHANNEL_1}, 127},
    {mux.pin(2), {62, CHANNEL_1}, 127},
    {mux.pin(4), {63, CHANNEL_1}, 127},
    {mux.pin(5), {64, CHANNEL_1}, 127},
    {mux.pin(6), {65, CHANNEL_1}, 127},
    {mux.pin(7), {66, CHANNEL_1}, 127},
    {mux.pin(8), {67, CHANNEL_1}, 127},
};

void setup() {
    Control_Surface.begin();
}

void loop(){
    Control_Surface.loop();
    if(timer) {
        for(i=0; i<50; i++)
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
    };
}

/*
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
