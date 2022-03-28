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

int S = 30;		//time between the frame-updates - sleep
int F = 200;	//number of updates that are performed by the program

int argc = 2;

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
	
	argc = 2;

	if (argc == 2)
	{
		ifstream Input{ "Input.txt" };
		if (!Input) 
		{
			cout << "Error: check Input file (numbers)" << endl;
			return -1;
		}

		Input >> n;
		Input.close();
	}

	cout << "the number of Atoms is: " << n << endl;

	return n;
}

//**********************************************************
//
//**********************************************************

void init(int n, Atom Atom[], int argc, const char* argv[]) {

	argc = 2;

	if (argc == 2)
	{
		ifstream Input{ "Input.txt" };
		if (!Input) {
			cout << "Error: check Input file (init)" << endl;
			return;
		}

		while (Input)
		{
			int n;
			Input >> n;
			for (int j = 0; j < n; j++)
			{
				Input >> Atom[j].c;
				Input >> Atom[j].rad;
				Input >> Atom[j].pos_x;
				Input >> Atom[j].pos_y;
				Input >> Atom[j].vel_x;
				Input >> Atom[j].vel_y;

				cout << "Atom " << j + 1 << " has the following values assigned:" << endl;
				cout << "Color" << j + 1 << " is      " << Atom[j].c << endl;
				cout << "Radius" << j + 1 << " is     " << Atom[j].rad << endl;
				cout << "x Pos." << j + 1 << " is     " << Atom[j].pos_x << endl;
				cout << "y Pos." << j + 1 << " is     " << Atom[j].pos_y << endl;
				cout << "vx" << j + 1 << " is         " << Atom[j].vel_x << endl;
				cout << "vy" << j + 1 << " is         " << Atom[j].vel_y << endl;
			}
		}

		Input.close();
	}
	else if(argc == 1) {
		for (int j = 0; j < n; j++) {
			Atom[j].c = random(000, 0xFFFFFF);
			Atom[j].rad = random(50, 150);
			Atom[j].vel_x = random(5, 25);
			Atom[j].vel_y = random(5, 25);
			Atom[j].pos_x = random(0, H);
			Atom[j].pos_y = random(0, W);

			cout << "Atom " << j + 1 << " has the following values assigned:" << endl;
			cout << "Color" << j + 1 << " is      " << Atom[j].c << endl;
			cout << "Radius" << j + 1 << " is     " << Atom[j].rad << endl;
			cout << "x Pos." << j + 1 << " is     " << Atom[j].pos_x << endl;
			cout << "y Pos." << j + 1 << " is     " << Atom[j].pos_y << endl;
			cout << "vx" << j + 1 << " is         " << Atom[j].vel_x << endl;
			cout << "vy" << j + 1 << " is         " << Atom[j].vel_y << endl;
		}
	}
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
	for (int j = 0; j < n; j++) {

		Atom[j].pos_x += Atom[j].vel_x;
		Atom[j].pos_y += Atom[j].vel_y;

		if (Atom[j].pos_x >= W - (Atom[j].rad / 2))
		{
			Atom[j].vel_x = -Atom[j].vel_x;
			Atom[j].pos_x = W - (Atom[j].rad / 2);
		}
		if (Atom[j].pos_x <= 0)
		{
			Atom[j].vel_x = -Atom[j].vel_x;
			Atom[j].pos_x = (Atom[j].rad / 2);
		}
		if (Atom[j].pos_y >= H - (Atom[j].rad / 2))
		{
			Atom[j].vel_y = -Atom[j].vel_y;
			Atom[j].pos_y = H - (Atom[j].rad / 2);
		}
		if (Atom[j].pos_y <= 0)
		{
			Atom[j].vel_y = -Atom[j].vel_y;
			Atom[j].pos_y = (Atom[j].rad / 2);
		}
	}
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