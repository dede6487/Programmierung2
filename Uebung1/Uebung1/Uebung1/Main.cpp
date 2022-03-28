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
#include <fstream>

int W = 640;	//W,H are the width and the height of the created window
int H = 480;

int S = 20;		//time between the frame-updates - sleep
int F = 20;	//number of updates that are performed by the program

//**********************************************************
// struct "Atom"
// 
// defines the data structure for an Atom
// Atoms hold the values:
// c ... colour
// rad ... radius
// vel ... velocity
// pos_x ... x-value for position
// pos_y ... y-value for position
// 
//**********************************************************

typedef struct Atom
{
	int c;
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
	
	ifstream Input{ "Input.txt" };
	if (!Input) {
		cout << "Dateifehler" << endl;
		return;
	}

	while (Input)
	{
		int n;
		Input >> n;
		for (int j = 0; j < n; j++)
		{
			Atom[j].c 
			Atom[j].rad
			Atom[j].pos_x
			Atom[j].pos_y
			Atom[j].vel_x
			Atom[j].vel_y

			cout << "Color of Atom " << j + 1 << " is      " << Atom[j].c << endl;
			cout << "Radius of Atom " << j + 1 << " is     " << Atom[j].rad << endl;
			cout << "vx of Atom " << j + 1 << " is         " << Atom[j].vel_x << endl;
			cout << "vy of Atom " << j + 1 << " is         " << Atom[j].vel_y << endl;
			cout << "x Position of Atom " << j + 1 << " is " << Atom[j].pos_x << endl;
			cout << "y Position of Atom " << j + 1 << " is " << Atom[j].pos_y << endl;
		}
	}

	//for (int j = 0; j < n; j++) {
	//	Atom[j].c = random(000, 0xFFFFFF);
	//	Atom[j].rad = random(50, 150);
	//	Atom[j].vel_x = random(20, 50);
	//	Atom[j].vel_y = random(20, 50);
	//	Atom[j].pos_x = random(0, H);
	//	Atom[j].pos_y = random(0, W);

	//	cout << "Color of Atom " << j+1 << " is      " << Atom[j].c << endl;
	//	cout << "Radius of Atom " << j+1 << " is     " << Atom[j].rad<< endl;
	//	cout << "vx of Atom " << j+1 << " is         " << Atom[j].vel_x << endl;
	//	cout << "vy of Atom " << j+1 << " is         " << Atom[j].vel_y << endl;
	//	cout << "x Position of Atom " << j+1 << " is " << Atom[j].pos_x << endl;
	//	cout << "y Position of Atom " << j+1 << " is " << Atom[j].pos_y << endl;
	//}
}

//**********************************************************
//
//**********************************************************

void draw(int n, Atom Atom[]) {
	fillRectangle(0, 0, W, H, 0xFFFFFF);

	for (int j = 0; j < n; j++) {
		fillEllipse(Atom[j].pos_x, Atom[j].pos_y, Atom[j].rad, Atom[j].rad, Atom[j].c);
	}
	
	flush();
}

//**********************************************************
//
//**********************************************************

void update(int n, Atom Atom[]) {
	//for (int j = 0; j < n; j++) {

	//}
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