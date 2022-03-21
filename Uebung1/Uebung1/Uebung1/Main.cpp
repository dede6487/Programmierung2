#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Drawing.h"

#if defined(_WIN32) || defined (_WIN64)
#include <windows.h>
#else
#include <time.h>
static void Sleep(int ms)
{
	struct timespec ts;
	ts.tv_sec = ms / 1000;
	ts.tv_nsec = (ms % 1000) * 1000000;
	nanosleep(&ts, NULL);
}
#endif

using namespace std;
using namespace compsys;

int W = 640;	//W,H are the width and the height of the created window
int H = 480;

//**********************************************************
// struct "Atom"
// 
// defines the data structure for an Atom
// Atoms hold the values:
// col ... colour
// rad ... radius
// vel ... velocity
// pos_x ... x-value for position
// pos_y ... y-value for position
// 
//**********************************************************

typedef struct Atom
{
	int col;
	float rad;
	double vel;
	double pos_x;
	double pos_y;
};

//**********************************************************
//	Function "number"
//	
//	creates Atoms with their initial Values as stated above
//	N Atoms will be created with random colour, random size and
//	random velocity at a random position.
//
//**********************************************************

double number() {
	int N = 3;

	while (N >= 1) {
		struct Atom AtomN;
		AtomN.col = 1;
		AtomN.rad = 2;
		AtomN.vel = 3;
		AtomN.pos_x = 4;
		AtomN.pos_y = 5;
		N--;
	}
}

//**********************************************************
//
//**********************************************************

double init(int N, struct Atom) {

}

//**********************************************************
//
//**********************************************************

double draw() {

}

//**********************************************************
//
//**********************************************************

double update(int N, struct Atom) {

}


int main(int argc, const char* argv[])
{
	beginDrawing(W, H, "Atoms", 0xFFFFFF, false);
	int n = number(argc, argv);
	Atom* atoms = new Atom[n];
	init(n, atoms, argc, argv);
	draw(n, atoms);
	cout << "Press <ENTER> to continue..." << endl;
	string s; getline(cin, s);
	for (int i = 0; i < F; i++)
	{
		update(n, atoms);
		draw(n, atoms);
		Sleep(S);
	}
	delete[] atoms;
	cout << "Close window to exit..." << endl;
	endDrawing();
}