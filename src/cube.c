#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char cube[4][4][4];
volatile unsigned char out[2][4];
volatile unsigned int count = 0;

char layer[4];

void setCube() {

int z=0;
int y=0;
int x=0;


for(z=0;z<=3;z++) {

out[0][z] = 0;
out[1][z] = 0;

for(y=0;y<=3;y++) {
for(x=0;x<=3;x++) {

	unsigned char val = cube[x][y][z];
	if (val != 0) {
	if(y==0) {
		if(x==0) {
			//PORTA |= (val<<PA2);		
			out[0][z] |= (val<<PA2);
		} else if(x==1) {
			//PORTA |= (val<<PA7);		
			out[0][z] |= (val<<PA7);
		} else if(x==2) {
			//PORTC |= (val<<PC4);		
			out[1][z] |= (val<<PC4);
		} else if(x==3) {
			//PORTC |= (val<<PC1);		
			out[1][z] |= (val<<PC1);
		}
	} else if(y==1) {
		if(x==0) {
			//PORTA |= (val<<PA1);		
			out[0][z] |= (val<<PA1);
		} else if(x==1) {
			//PORTA |= (val<<PA6);		
			out[0][z] |= (val<<PA6);
		} else if(x==2) {
			//PORTC |= (val<<PC5);		
			out[1][z] |= (val<<PA5);
		} else if(x==3) {
			//PORTC |= (val<<PC2);		
			out[1][z] |= (val<<PC2);
		}	
	} else if(y==2) {
		if(x==0) {
			//PORTA |= (val<<PA0);		
			out[0][z] |= (val<<PA0);
		} else if(x==1) {
			//PORTA |= (val<<PA5);		
			out[0][z] |= (val<<PA5);
		} else if(x==2) {
			//PORTC |= (val<<PC6);		
			out[1][z] |= (val<<PC6);
		} else if(x==3) {
			//PORTC |= (val<<PC3);		
			out[1][z] |= (val<<PC3);
		}
	} else if(y==3) {
		if(x==0) {
			//PORTA |= (val<<PA3);		
			out[0][z] |= (val<<PA3);
		} else if(x==1) {
			//PORTA |= (val<<PA4);		
			out[0][z] |= (val<<PA4);
		} else if(x==2) {
			//PORTC |= (val<<PC7);		
			out[1][z] |= (val<<PC7);
		} else if(x==3) {
			//PORTC |= (val<<PC0);		
			out[1][z] |= (val<<PC0);
		}
	}
	} 
	
}	

}

	//needed?
//	_delay_ms(500);
//	PORTA=0;
//	PORTC=0;	
}



}

void draw() {

setCube();

/*PORTD = layer[count];
PORTA = out[0][count];
PORTC = out[1][count];
*/
}

//ISR(TIMER1_OVF_vect) {

ISR(TIMER2_COMP_vect) {

PORTD = 0;
PORTA = out[0][count];
PORTC = out[1][count];
PORTD = layer[count];

if (count++ == 3)
	count = 0; 
}


void cleanCube() {
cube[0][0][0] = 0;
cube[1][0][0] = 0;
cube[2][0][0] = 0;
cube[3][0][0] = 0;
cube[0][1][0] = 0;
cube[1][1][0] = 0;
cube[2][1][0] = 0;
cube[3][1][0] = 0;
cube[0][2][0] = 0;
cube[1][2][0] = 0;
cube[2][2][0] = 0;
cube[3][2][0] = 0;
cube[0][3][0] = 0;
cube[1][3][0] = 0; 
cube[2][3][0] = 0; 
cube[3][3][0] = 0;

cube[0][0][1] = 0;
cube[1][0][1] = 0;
cube[2][0][1] = 0;
cube[3][0][1] = 0;
cube[0][1][1] = 0;
cube[1][1][1] = 0;
cube[2][1][1] = 0;
cube[3][1][1] = 0;
cube[0][2][1] = 0;
cube[1][2][1] = 0;
cube[2][2][1] = 0;
cube[3][2][1] = 0;
cube[0][3][1] = 0;
cube[1][3][1] = 0;
cube[2][3][1] = 0;
cube[3][3][1] = 0;

cube[0][0][2] = 0;
cube[1][0][2] = 0;
cube[2][0][2] = 0;
cube[3][0][2] = 0;
cube[0][1][2] = 0;
cube[1][1][2] = 0;
cube[2][1][2] = 0;
cube[3][1][2] = 0;
cube[0][2][2] = 0;
cube[1][2][2] = 0;
cube[2][2][2] = 0;
cube[3][2][2] = 0;
cube[0][3][2] = 0;
cube[1][3][2] = 0;
cube[2][3][2] = 0;
cube[3][3][2] = 0;

cube[0][0][3] = 0;
cube[1][0][3] = 0;
cube[2][0][3] = 0;
cube[3][0][3] = 0;
cube[0][1][3] = 0;
cube[1][1][3] = 0;
cube[2][1][3] = 0;
cube[3][1][3] = 0;
cube[0][2][3] = 0;
cube[1][2][3] = 0;
cube[2][2][3] = 0;
cube[3][2][3] = 0;
cube[0][3][3] = 0;
cube[1][3][3] = 0;
cube[2][3][3] = 0;
cube[3][3][3] = 0;

}

int main() {

	DDRA = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF; 

	PORTD = 0x00;
	PORTC = 0x00;
	PORTA = 0x00;
	
	layer[0] = 0x10;
	layer[1] = 0x20;
	layer[2] = 0x80;
	layer[3] = 0x40;



/*
TCNT1 = 0x00;
TIMSK |= (1 << TOIE1);
//OCR1B = 0xFF;
TCCR1B |= 0x15;
//TCCR1B |= (1 << WGM01);
*/

TCNT2 = 0x00;
TIMSK |= (1 << OCIE2);
OCR2 = 0xFF;
TCCR2 = 0x05;
TCCR2 |= (1 << WGM01);

sei();
int a;
int b;
int c;
	while (1) {
		for(c=0;c<=3;c++) {
		for(b=0;b<=3;b++) {
		for(a=0;a<=3;a++) {
		cube[a][b][c] = 1;
		draw();
		_delay_ms(200);
		}
		}
		}


		for(c=3;c>=0;c--) {
		for(b=3;b>=0;b--) {
		for(a=3;a>=0;a--) {
		cube[a][b][c] = 0;
		draw();
		_delay_ms(200);
		}
		}
		}


		_delay_ms(2000);
		
		a=0;
		b=0;
		c=0;

		for(a=0;a<=3;a++) {
		cube[0][0][a] = 1;
		cube[0][3][a] = 1;
		cube[3][0][a] = 1;
		cube[3][3][a] = 1;
		_delay_ms(1000);
		draw();
		}

		_delay_ms(1000);
		cube[1][0][3] = 1;
		cube[2][0][3] = 1;
		draw();
		_delay_ms(1000);
		cube[0][1][3] = 1;
		cube[0][2][3] = 1;
		draw();
		_delay_ms(1000);
		cube[3][1][3] = 1;
		cube[3][2][3] = 1;
		draw();
		_delay_ms(1000);
		cube[1][3][3] = 1;
		cube[2][3][3] = 1;
		
		draw();		
		_delay_ms(1000);

		cube[1][0][0] = 1;
		cube[2][0][0] = 1;
		draw();
		_delay_ms(1000);
		cube[0][1][0] = 1;
		cube[0][2][0] = 1;
		draw();
		_delay_ms(1000);
		cube[3][1][0] = 1;
		cube[3][2][0] = 1;
		draw();
		_delay_ms(1000);
		cube[1][3][0] = 1;
		cube[2][3][0] = 1;
		
		draw();
		_delay_ms(2000);

		cube[1][1][3] = 1;
		draw();
		_delay_ms(1000);
		cube[2][1][3] = 1;
		draw();
		_delay_ms(1000);
		cube[1][2][3] = 1;
		draw();
		_delay_ms(1000);
		cube[2][2][3] = 1;
		draw();
		_delay_ms(2000);

		for(a=3;a>=0;a--) {
		cube[0][0][a] = 0;
		cube[0][3][a] = 0;
		cube[3][0][a] = 0;
		cube[3][3][a] = 0;
		_delay_ms(1500);
		draw();
		}

		cube[1][0][0] = 0;
		cube[2][0][0] = 0;
		draw();
		_delay_ms(1000);
		cube[0][1][0] = 0;
		cube[0][2][0] = 0;
		draw();
		_delay_ms(1000);
		cube[3][1][0] = 0;
		cube[3][2][0] = 0;
		draw();
		_delay_ms(1000);
		cube[1][3][0] = 0;
		cube[2][3][0] = 0;
		draw();
		_delay_ms(2000);
		
		cube[1][0][3] = 0;
		cube[2][0][3] = 0;
		cube[0][1][3] = 0;
		cube[0][2][3] = 0;
		cube[3][1][3] = 0;
		cube[3][2][3] = 0;
		cube[1][3][3] = 0;
		cube[2][3][3] = 0;
		draw();
		_delay_ms(500);

		for(a=3;a>=0;a--) {
		cube[1][1][a] = 1;
		cube[1][2][a] = 1;
		cube[2][2][a] = 1;
		cube[2][1][a] = 1;

		cube[1][1][a+2] = 0;
		cube[1][2][a+2] = 0;
		cube[2][2][a+2] = 0;
		cube[2][1][a+2] = 0;

		draw();
		_delay_ms(500);
		}

		_delay_ms(500);
		
		cube[1][1][2] = 0;
		cube[1][2][2] = 0;
		cube[2][2][2] = 0;
		cube[2][1][2] = 0;
		draw();
		
		_delay_ms(500);

cube[0][0][0] = 1;
cube[1][0][0] = 1;
cube[2][0][0] = 1;
cube[3][0][0] = 1;
cube[0][1][0] = 1;
cube[1][1][0] = 1;
cube[2][1][0] = 1;
cube[3][1][0] = 1;
cube[0][2][0] = 1;
cube[1][2][0] = 1;
cube[2][2][0] = 1;
cube[3][2][0] = 1;
cube[0][3][0] = 1;
cube[1][3][0] = 1; 
cube[2][3][0] = 1; 
cube[3][3][0] = 1;

draw();

_delay_ms(500);

		cube[1][1][1] = 0;
		cube[1][2][1] = 0;
		cube[2][2][1] = 0;
		cube[2][1][1] = 0;
		draw();
		_delay_ms(300);

		cube[1][1][1] = 0;
		cube[1][2][1] = 0;
		cube[2][2][1] = 0;
		cube[2][1][1] = 0;
		draw();

		_delay_ms(500);
	cube[0][0][0] = 0;
cube[1][0][0] = 0;
cube[2][0][0] = 0;
cube[3][0][0] = 0;
cube[0][1][0] = 0;
cube[1][1][0] = 0;
cube[2][1][0] = 0;
cube[3][1][0] = 0;
cube[0][2][0] = 0;
cube[1][2][0] = 0;
cube[2][2][0] = 0;
cube[3][2][0] = 0;
cube[0][3][0] = 0;
cube[1][3][0] = 0; 
cube[2][3][0] = 0; 
cube[3][3][0] = 0;
draw();

		_delay_ms(4000);
		
		cleanCube();
		draw();
		_delay_ms(2000);	

int x=0;
int z=0;
int k;
		for(a=3;a>0;a--){
		
		for(z=0;z<=3;z++){
		for(x=0;x<=3;x++) {
			
			for(b=0;b<2;b++){
			
				for(c=a;c<=3;c++) {
				if (c>0) cube[c-1][x][z] = 0;
				cube[c][x][z] = 1;
				draw();
				for(k=1;k<=a;k++) {
					_delay_ms(50);
				}
				}
				for(c=3;c>=0;c--) {
				if(c<3) cube[c+1][x][z] = 0;
				cube[c][x][z] = 1;
				draw();
				for(k=1;k<=a;k++) {
					_delay_ms(50);
				}

				}

			}
		}
		}

			}

cleanCube();
draw();
_delay_ms(2000);

/*
				cube[0][3][0] = 0;
				cube[0][3][1] = 0;
				cube[0][3][2] = 0;
				cube[0][3][3] = 0;
				cube[0][0][0] = 0;
				cube[0][0][1] = 0;
				cube[0][0][2] = 0;
				cube[0][0][3] = 0;
				cube[0][0][1] = 0;
				cube[0][3][2] = 0;
				cube[0][3][1] = 0;
				cube[0][0][2] = 0;

	for(a=3;a>0;a--){
		
		for(z=0;z<=3;z++){
		for(x=0;x<=3;x++) {
			
			for(b=0;b<2;b++){
			
				for(c=a;c<=3;c++) {
				if (c>0) cube[c-1][1][1] = 0;
				if (c>0) cube[c-1][2][1] = 0;
				if (c>0) cube[c-1][1][2] = 0;
				if (c>0) cube[c-1][2][2] = 0;
				cube[c][1][1] = 1;
				cube[c][2][1] = 1;
				cube[c][1][2] = 1;
				cube[c][2][2] = 1;
				draw();
				for(k=1;k<=a;k++) {
					_delay_ms(100);
				}
				}
				for(c=3;c>=0;c--) {
				if(c<3) cube[c+1][1][1] = 0;
				if(c<3) cube[c+1][2][1] = 0;
				if(c<3) cube[c+1][1][2] = 0;
				if(c<3) cube[c+1][2][2] = 0;
				cube[c][1][1] = 1;
				cube[c][1][1] = 1;
				cube[c][2][2] = 1;
				cube[c][2][2] = 1;
				draw();
				for(k=1;k<=a;k++) {
					_delay_ms(100);
				}

				}

			}
		}
		}

			}

*/



		

	}
}
