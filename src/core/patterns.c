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

void circle() {

	int x=0;
	int y=0;

	for (x=0;x<=3;x++) {
		if(x>0) {
			toogleVoxel(x-1,y,0);
			toogleVoxel(x-1,y,1);
			toogleVoxel(x-1,y,2);
			toogleVoxel(x-1,y,3);
		}
		toogleVoxel(x,y,0);
		toogleVoxel(x,y,1);
		toogleVoxel(x,y,2);
		toogleVoxel(x,y,3);
		_delay_ms(200);
		if (ir == 1) return;
	}
	toogleVoxel(3,0,0);
	toogleVoxel(3,0,1);
	toogleVoxel(3,0,2);
	toogleVoxel(3,0,3);

	x=3;
	y=0;


	for (y=0;y<=3;y++) {
		if(y>0) {
			toogleVoxel(x,y-1,0);
			toogleVoxel(x,y-1,1);
			toogleVoxel(x,y-1,2);
			toogleVoxel(x,y-1,3);
		}
		toogleVoxel(x,y,0);
		toogleVoxel(x,y,1);
		toogleVoxel(x,y,2);
		toogleVoxel(x,y,3);
		_delay_ms(200);
		if (ir == 1) return;
	}
	toogleVoxel(3,3,0);
	toogleVoxel(3,3,1);
	toogleVoxel(3,3,2);
	toogleVoxel(3,3,3);

	y=3;
	x=3;


	for (x=3;x>=0;x--) {
		if(x>=0) {
			toogleVoxel(x+1,y,0);
			toogleVoxel(x+1,y,1);
			toogleVoxel(x+1,y,2);
			toogleVoxel(x+1,y,3);
		}
		toogleVoxel(x,y,0);
		toogleVoxel(x,y,1);
		toogleVoxel(x,y,2);
		toogleVoxel(x,y,3);
		_delay_ms(200);
		if (ir == 1) return;
	}


	x=0;

	for (y=3;y>0;y--) {
		if(y>0) {
			toogleVoxel(x,y-1,0);
			toogleVoxel(x,y-1,1);
			toogleVoxel(x,y-1,2);
			toogleVoxel(x,y-1,3);
		}
		toogleVoxel(x,y,0);
		toogleVoxel(x,y,1);
		toogleVoxel(x,y,2);
		toogleVoxel(x,y,3);
		_delay_ms(200);
		if (ir == 1) return;
	}
	toogleVoxel(0,0,0);
	toogleVoxel(0,0,1);
	toogleVoxel(0,0,2);
	toogleVoxel(0,0,3);

}
