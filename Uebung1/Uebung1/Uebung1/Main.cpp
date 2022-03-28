//**********************************************************
//
//**********************************************************


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

#include  <string>	//defines the getline() function

int W = 640;	//W,H are the width and the height of the created window
int H = 480;

int S = 40;		//time between the frame-updates - sleep
int F = 200;	//number of updates that are performed by the program

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
	int rad;
	int vel_x;
	int vel_y;
	int pos_x;
	int pos_y;
};

//**********************************************************
// Funtion "random"
// 
// input: two int numbers which define the lower and the upper
// limits of the outputted random number
// 
// output: a random number in between the given limits
// including the limits
// 
//**********************************************************

int random(int llimit, int ulimit) {
	
	srand(time(0));

	return (rand() % (ulimit - llimit + 1)) + llimit;
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

void init(int n, Atom Atom[], int argc, const char* argv[]) {

	for (int j = 0; j < n; j++) {
		Atom[j].col = random(000, 0xFFFFFF);
		Atom[j].rad = random(50, 150);
		Atom[j].vel_x = random(20, 50);
		Atom[j].vel_y = random(20, 50);
		Atom[j].pos_x = random(0, H);
		Atom[j].pos_y = random(0, W);
	}
}

//**********************************************************
//
//**********************************************************

void draw(int n, Atom Atom[]) {
	fillRectangle(0, 0, W, H, 0xFFFFFF);

	for (int j = 0; j < n; j++) {
		fillEllipse(Atom[j].pos_x, Atom[j].pos_y, Atom[j].rad, Atom[j].rad, Atom[j].col);
	}
	
	flush();
}

//**********************************************************
//
//**********************************************************

void update(int n, Atom* Atom) {

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