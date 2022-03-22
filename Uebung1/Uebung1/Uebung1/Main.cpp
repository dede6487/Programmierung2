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

int S = 40;		//time between the frame-updates - sleep

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
//	Funtion "random"
// 
//	input: two numbers which define the lower and the upper
//	limits of the outputted random number
// 
//	output: a random nunmber in between the given limits
// 
//**********************************************************

double random(int ulimit, int llimit) {
	double random;

	srand(time(0));
	random = (rand() / RAND_MAX) * (llimit-ulimit) + ulimit;

	return random;
}

//**********************************************************
//	Function "number"
//	
//	creates Atoms with their initial Values as stated above
//	N Atoms will be created with random colour, random size and
//	random velocity at a random position.
//
//**********************************************************

double number(int argc, const char* argv[]) {
	int n = 3;

	return n;
}

//**********************************************************
//
//**********************************************************

void init(int n, struct Atom,int argc, const char* argv[]) {
	struct Atom Atom[n];

	while (int i = 0 < n) {
		Atom[i].col = random(000, 255);
		Atom[i].rad = random(50, 150);
		Atom[i].vel = random(20, 50);
		Atom[i].pos_x = random(0, H);
		Atom[i].pos_y = random(0, W);
		i++;
	}
}

//**********************************************************
//
//**********************************************************

void draw(int n, struct Atom) {
	fillRectangle(0, 0, W, H, 0000);

	//Atoms need to be drawn here
	flush();
}

//**********************************************************
//
//**********************************************************

void update(int n, struct Atom) {

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