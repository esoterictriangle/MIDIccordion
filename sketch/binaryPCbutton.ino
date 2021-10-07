//basic idea: 1 toggle turns on this mode, remaps all of the pins in question (does this mean those pins need to be assigned in loop or setup instead of globally?)
//1 toggle starts listening for the binary. When all switches are in the correct position, this toggle is flipped back, sending the program change with the value from the binary switches.
  
//taken from https://tttapa.github.io/Control-Surface-doc/Doxygen/d4/d3b/Custom-MIDI-Output-Element_8ino-example.html
  void update() final override {
    AH::Button::State state = button.update();        // Read the button
    if (state == AH::Button::Falling) {               // if pressed
        //I'm not sure if there needs to be anything done here if the binary switches are just always being listened to
    } else if (state == AH::Button::Rising) {         // if released
      Control_Surface.sendProgramChange(address); // program change is sent (address needs to be the variable that's similar to num in binaryConversion.ino)
    }
  }