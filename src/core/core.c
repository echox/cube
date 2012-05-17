#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "config.h"
#include "core.h"

volatile unsigned char count;

ISR(TIMER2_COMP_vect) {

PORTD = 0;
PORTA = out[0][count];
PORTC = out[1][count];
PORTD = layer[count];

if (count++ == 3)
        count = 0;
}

void drawCube() {

	int x;
	int y;
	int z;

	//TODO replace limit with constants
	for(z=0;z<=3;z++) {
		for(y=0;y<=3;y++) {
			for(x=0;x<=3;x++) {
				
				if(cube[x][y][z]) {
					*cubeRef[x][y][z] |= pinMask[x][y];
				} else {
					*cubeRef[x][y][z] &= ~(pinMask[x][y]);
				}	
			}
		}
	}
}

void toogleVoxel(char x, char y, char z) {
	cube[x][y][z] = ~(cube[x][y][z]);
	drawCube();
}

void fullCube() {

	int x;
	int y;
	int z;

	//TODO replace limit with constants
	for(z=0;z<=3;z++) {
		for(y=0;y<=3;y++) {
			for(x=0;x<=3;x++) {
				cube[x][y][z] = 1;
			}
		}
	}

	drawCube();
}

void clearCube() {

	int x;
	int y;
	int z;

	//TODO replace limit with constants
	for(z=0;z<=3;z++) {
		for(y=0;y<=3;y++) {
			for(x=0;x<=3;x++) {
				cube[x][y][z] = 0;		
			}
		}
	}
	
	drawCube();
}

void delay(int sec) {

	for (; sec > 0; sec--)
		_delay_ms(100);
}
