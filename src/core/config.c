#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"


void init() {

DDRA = 0xFF;
DDRC = 0xFF;
DDRD = 0xFF;

PORTD = 0x00;
PORTC = 0x00;
PORTA = 0x00;

// bitmask for the layers
layer[0] = 0x10;
layer[1] = 0x20;
layer[2] = 0x80;
layer[3] = 0x40;

// bitmask for the output registers
pinMask[0][0] = (1 << PA2);
pinMask[1][0] = (1 << PA7);
pinMask[2][0] = (1 << PC4);
pinMask[3][0] = (1 << PC1);
pinMask[0][1] = (1 << PA1);
pinMask[1][1] = (1 << PA6);
pinMask[2][1] = (1 << PA5);
pinMask[3][1] = (1 << PC2);
pinMask[0][2] = (1 << PA0);
pinMask[1][2] = (1 << PA5);
pinMask[2][2] = (1 << PC6);
pinMask[3][2] = (1 << PC3);
pinMask[0][3] = (1 << PA3);
pinMask[1][3] = (1 << PA4);
pinMask[2][3] = (1 << PC7);
pinMask[3][3] = (1 << PC0);

// mapping between output register and cube array
cubeRef[0][0][0] = &(out[0][0]);
cubeRef[1][0][0] = &(out[0][0]);
cubeRef[2][0][0] = &(out[1][0]);
cubeRef[3][0][0] = &(out[1][0]);
cubeRef[0][1][0] = &(out[0][0]);
cubeRef[1][1][0] = &(out[0][0]);
cubeRef[2][1][0] = &(out[1][0]);
cubeRef[3][1][0] = &(out[1][0]);
cubeRef[0][2][0] = &(out[0][0]);
cubeRef[1][2][0] = &(out[0][0]);
cubeRef[2][2][0] = &(out[1][0]);
cubeRef[3][2][0] = &(out[1][0]);
cubeRef[0][3][0] = &(out[0][0]);
cubeRef[1][3][0] = &(out[0][0]);
cubeRef[2][3][0] = &(out[1][0]);
cubeRef[3][3][0] = &(out[1][0]);

cubeRef[0][0][1] = &(out[0][1]);
cubeRef[1][0][1] = &(out[0][1]);
cubeRef[2][0][1] = &(out[1][1]);
cubeRef[3][0][1] = &(out[1][1]);
cubeRef[0][1][1] = &(out[0][1]);
cubeRef[1][1][1] = &(out[0][1]);
cubeRef[2][1][1] = &(out[1][1]);
cubeRef[3][1][1] = &(out[1][1]);
cubeRef[0][2][1] = &(out[0][1]);
cubeRef[1][2][1] = &(out[0][1]);
cubeRef[2][2][1] = &(out[1][1]);
cubeRef[3][2][1] = &(out[1][1]);
cubeRef[0][3][1] = &(out[0][1]);
cubeRef[1][3][1] = &(out[0][1]);
cubeRef[2][3][1] = &(out[1][1]);
cubeRef[3][3][1] = &(out[1][1]);

cubeRef[0][0][2] = &(out[0][2]);
cubeRef[1][0][2] = &(out[0][2]);
cubeRef[2][0][2] = &(out[1][2]);
cubeRef[3][0][2] = &(out[1][2]);
cubeRef[0][1][2] = &(out[0][2]);
cubeRef[1][1][2] = &(out[0][2]);
cubeRef[2][1][2] = &(out[1][2]);
cubeRef[3][1][2] = &(out[1][2]);
cubeRef[0][2][2] = &(out[0][2]);
cubeRef[1][2][2] = &(out[0][2]);
cubeRef[2][2][2] = &(out[1][2]);
cubeRef[3][2][2] = &(out[1][2]);
cubeRef[0][3][2] = &(out[0][2]);
cubeRef[1][3][2] = &(out[0][2]);
cubeRef[2][3][2] = &(out[1][2]);
cubeRef[3][3][2] = &(out[1][2]);

cubeRef[0][0][3] = &(out[0][3]);
cubeRef[1][0][3] = &(out[0][3]);
cubeRef[2][0][3] = &(out[1][3]);
cubeRef[3][0][3] = &(out[1][3]);
cubeRef[0][1][3] = &(out[0][3]);
cubeRef[1][1][3] = &(out[0][3]);
cubeRef[2][1][3] = &(out[1][3]);
cubeRef[3][1][3] = &(out[1][3]);
cubeRef[0][2][3] = &(out[0][3]);
cubeRef[1][2][3] = &(out[0][3]);
cubeRef[2][2][3] = &(out[1][3]);
cubeRef[3][2][3] = &(out[1][3]);
cubeRef[0][3][3] = &(out[0][3]);
cubeRef[1][3][3] = &(out[0][3]);
cubeRef[2][3][3] = &(out[1][3]);
cubeRef[3][3][3] = &(out[1][3]);

// enable interupt for multiplexing
TCNT2 = 0x00;
TCNT2 = 0x00;
TIMSK |= (1 << OCIE2);
OCR2 = 0xFF;
TCCR2 = 0x05;
TCCR2 |= (1 << WGM01);

MCUCSR |= (0 << ISC2);
GICR |= (1 << INT2);
sei();

}
