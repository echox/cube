// references to the output register array
volatile unsigned char* cubeRef[4][4][4];
volatile unsigned char cube[4][4][4];

// output register which is used to draw the cube
volatile unsigned char out[2][4];

char layer[4];

char pinMask[4][4];

void init();
