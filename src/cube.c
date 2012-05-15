#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "core/config.h"
#include "core/core.h"

void draw() {
	setCube();
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

init();

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

	}
}
