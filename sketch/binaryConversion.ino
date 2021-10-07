//goal eventually is to take the input of 8 switches and convert to a binary string, which is then sent as a program change MIDI message
//I think the workflow will look like: 1) toggle button 9 to start listening 2) flip switches to binary number 3) toggle button 9 off to send message

//String(number, BIN) //converts to binary string; DEC for decimal, HEX for hex
//digitalRead(pin) //shows the value
int pin1 = 6;
int pin2 = 7;
int pin3 = 8;
int pin4 = 9;

void setup() {
    Serial.begin(115200);
    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
    pinMode(pin3, INPUT);
    pinMode(pin4, INPUT);
}

void loop() 
    Control_Surface.loop();
    String num1 = digitalRead(pin1);
    String num2 = digitalRead(pin2);
    String num3 = digitalRead(pin3);
    String num4 = digitalRead(pin4);

    String num = String(pin4 + pin3 + pin2 + pin1, BIN);
    num.toInt();
    Serial.println(num);
}