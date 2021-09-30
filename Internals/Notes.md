## Bass:
Currently this is basically one row of 24 switches with a common ground. Each switch has a 22000ohm resistor; a random mix of gold and siver bands for tolerance. The connections are all straight forward and it should be easy to desolder everything and work in my new matrix. The wiring does not currently disconnect anywhere on the bass side, meaning the bass side is essentially always mated with the bellows. Will need some connectors on the bass side plus some flex tube or cable wrap for the snake inside the bellows.
![bass internals wiring](https://github.com/esoterictriangle/MIDIccordion/blob/Internals/internals%20photos/bass.jpg)

## Voicing Switches:
Voice switches are set up with a lot of circuit logic I can't quite follow--would be nice to see the schematic just to see how it all goes a little better--but that's not necessary for my purposes, really. Most are currently set to be high when the switch is **off** and low when **on**, with the exception of the power switch. Using it as the example, it's clear we can shift the springs so they run high when toggled on. There's lots of places to solder wire here, so it should end up looking much leaner with a simple matrix or 74HC595 mux daisy chain. 17 switches plus power.
![voice switches front](https://github.com/esoterictriangle/MIDIccordion/blob/Internals/internals%20photos/voice%20switch%20fronts.jpg)
![voice switches back](https://github.com/esoterictriangle/MIDIccordion/blob/Internals/internals%20photos/voice%20switch%20backs.jpg)

## Treble:
This was a bit trickier to access--you need to both remove each key and open up the bottom panel underneath the keyboard. (side note: it's really neat how the key removal tool is mounted to the frame and everything is laid out; it clearly was a machine meant to be maintained). When reassembling keyboard, place the Rmost key or two in first, then go L to R. The electronics are mounted on a piece of wood/custom breadboard that's screwed both from the top and the bottom, inside the bottom panel. One wire per key with a common ground, same type of resistor--similar to the bass side. There's ~3/8" of space beneath the breadboard and about a 1/4 above it (but only use the upper space as a last resort), plus a nicely sized channel. 41 switches.
![treble side wiring](https://github.com/esoterictriangle/MIDIccordion/blob/Internals/internals%20photos/treble.jpg)


The top screws are the black ones:  
<img src="https://github.com/esoterictriangle/MIDIccordion/blob/Internals/internals%20photos/top%20screws.jpg" width="100" alt="black top screws">  
The bottom screws are silver; the middle screw has a shorter threaded section for some reason:  
<img src="https://github.com/esoterictriangle/MIDIccordion/blob/Internals/internals%20photos/center%20back%20screw.jpg" width="100" alt="silver middle screw">

## Serial Cable Mount:
The cable's mount should be reusable for the microcontroller, ports, and maybe a dial or two. A 3D printed case shouldn't be too hard to work out; there are 3 mounting screws and an unmeasured (but at *least* 1/2") available depth. I could, theoretically, make a mounting bar that travels the width of the accordion. Just gotta make sure there's enough clearance for the valves.
