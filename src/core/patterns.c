#include "core.h"
#include "patterns.h"

void fillAndEmptyCube() {

	clearCube();

	int x,y,z;
	for(z=0;z<=3;z++) {
		for(y=0;y<=3;y++) {
			for(x=0;x<=3;x++) {
				if (ir == 1) return;
				toogleVoxel(x,y,z);
				_delay_ms(200);
			}
		}
	}

	for(z=3;z>=0;z--) {
		for(y=3;y>=0;y--) {
			for(x=3;x>=0;x--) {
				if (ir == 1) return;
				toogleVoxel(x,y,z);
				_delay_ms(200);
			}
		}
	}

}

void flashCube() {

	fullCube();
	_delay_ms(500);
	clearCube();
	_delay_ms(500);

}

void drops() {

}
