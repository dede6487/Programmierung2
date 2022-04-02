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
#include "Auxiliary.h"

int W = 640;	//W,H are the width and the height of the created window
int H = 480;

int S = 40;		//time between the frame-updates - sleep
int F = 200;	//number of updates that are performed by the program

//**********************************************************
// struct "Atom"
// 
// defines the data structure for an Atom
// Atoms hold the values:
// c ... colour
// r ... radius
// vx ... velocity in x
// vy ... velocity in y
// x ... x-value for position
// y ... y-value for position
// 
//**********************************************************

typedef struct Atom
{
	int c;
	int r;
	int vx;
	int vy;
	int x;
	int y;
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

	if (argc == 2)
	{
		ifstream Input{ argv[1] };
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

	if (argc == 2)
	{
		ifstream Input{ argv[1] };
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
				Input >> Atom[j].r;
				Input >> Atom[j].x;
				Input >> Atom[j].y;
				Input >> Atom[j].vx;
				Input >> Atom[j].vy;

				cout << "Atom " << j + 1 << " has the following values assigned:" << endl;
				cout << "Color" << j + 1 << " is      " << Atom[j].c << endl;
				cout << "Radius" << j + 1 << " is     " << Atom[j].r << endl;
				cout << "x Pos." << j + 1 << " is     " << Atom[j].x << endl;
				cout << "y Pos." << j + 1 << " is     " << Atom[j].y << endl;
				cout << "vx" << j + 1 << " is         " << Atom[j].vx << endl;
				cout << "vy" << j + 1 << " is         " << Atom[j].vy << endl;
			}
		}

		Input.close();
	}
	else if(argc == 1) {
		srand(time(0));
		for (int j = 0; j < n; j++) {
			Atom[j].c = random(000, 0xFFFFFF);
			Atom[j].r = random(20, 40);
			Atom[j].vx = random(5, 25);
			Atom[j].vy = random(5, 25);
			Atom[j].x = random(Atom[j].r, W - Atom[j].r);
			Atom[j].y = random(Atom[j].r, H - Atom[j].r);
			
			//the following function should check, if Atoms were to overlap

			bool valid=true;

			for (int l = 0; l <= j; l++) {
				int m = 0;
				if (sqrt(pow(Atom[j].x - Atom[l].x, 2) + pow(Atom[j].y - Atom[l].y, 2)) < Atom[j].r + Atom[l].r && j != l && valid)
				{
					Atom[j].x = random(Atom[j].r, W - Atom[j].r);
					Atom[j].y = random(Atom[j].r, H - Atom[j].r);

					m++;

					if (m >= 2) {
						valid = false;
					}
				}
				else if(!valid){
					cout << "Error: Atoms would overlap, please try again!" << endl;
					exit(1);
				}
			}

			cout << "Atom " << j + 1 << " has the following values assigned:" << endl;
			cout << "Color" << j + 1 << " is      " << Atom[j].c << endl;
			cout << "Radius" << j + 1 << " is     " << Atom[j].r << endl;
			cout << "x Pos." << j + 1 << " is     " << Atom[j].x << endl;
			cout << "y Pos." << j + 1 << " is     " << Atom[j].y << endl;
			cout << "vx" << j + 1 << " is         " << Atom[j].vx << endl;
			cout << "vy" << j + 1 << " is         " << Atom[j].vy << endl;
		}
	}
	else { cout << "Error: Please give a valid Argument!"; }
}

//**********************************************************
// Function "Draw"
// 
// Input: number of Atoms and values of these Atoms
// 
// Output: none
// 
// The draw function draws each individual "Frame" of the animation
// by first drawing a blank background and then drawing each individual Atom
// at its respective position. All of this is updated as one "Frame". 
//**********************************************************

void draw(int n, Atom Atom[]) {
	fillRectangle(0, 0, W, H, 0xFFFFFF);

	for (int j = 0; j < n; j++) {
		fillEllipse(Atom[j].x - Atom[j].r, Atom[j].y - Atom[j].r, 2 * Atom[j].r, 2 * Atom[j].r, Atom[j].c);
	}
	
	flush();
}

//**********************************************************
// Funtion "Update"
// 
// Input:number of Atoms and Values of Atoms
// 
// Output: none
// 
// The "Update" Function determines the position of every Atom
// by calculation their position through their velocities in x and y.
// It also handles Atom bouncing from Walls and later also themselves.
//**********************************************************

void update(int n, Atom Atom[]) {

	double Vx = 0;
	double Vy = 0;

	for (int j = 0; j < n; j++) {

		Atom[j].x += Atom[j].vx;
		Atom[j].y += Atom[j].vy;

		//checks for collisions between atoms and walls

		if (Atom[j].x >= W - Atom[j].r)
		{
			Atom[j].vx = -Atom[j].vx;
			Atom[j].x = W - Atom[j].r;
		}
		if (Atom[j].x <= Atom[j].r)
		{
			Atom[j].vx = -Atom[j].vx;
			Atom[j].x = Atom[j].r;
		}
		if (Atom[j].y >= H - Atom[j].r)
		{
			Atom[j].vy = -Atom[j].vy;
			Atom[j].y = H - Atom[j].r;
		}
		if (Atom[j].y <= Atom[j].r)
		{
			Atom[j].vy = -Atom[j].vy;
			Atom[j].y = Atom[j].r;
		}

		//checks for collisions between different atoms
		for (int l = 0; l <= j; l++) {

			int dx = Atom[j].x - Atom[l].x;
			int dy = Atom[j].y - Atom[l].y;
			int rsum = Atom[j].r + Atom[l].r;

			if (sqrt(pow(dx,2)+ pow(dy,2)) <= rsum && j != l)
			{

				double alpha = atan2(dy,dx);
				int dx1 = cos(alpha) * rsum;
				int dy1 = sin(alpha) * rsum;

				Atom[j].x += dx1 - dx;
				Atom[j].y += dy1 - dy;

				double beta = 3.1415926 - alpha;

				double a;
				double r;
				double vx1;
				double vy1;

				toPolar(Atom[j].vx, Atom[j].vy, r, a);
				a - beta;
				toCartesian(r, a, vx1, vy1);

				Atom[j].vx = vx1;
				Atom[j].vy = vy1;

				toPolar(Atom[l].vx, Atom[l].vy, r, a);
				a - beta;
				toCartesian(r, a, vx1, vy1);

				Atom[l].vx = vx1;
				Atom[l].vy = vy1;

				Vx = (pow(Atom[l].r, 2) * Atom[l].vx + pow(Atom[j].r, 2) * Atom[j].vx) / (pow(Atom[j].r, 2) + pow(Atom[l].r, 2));
				Vy = (pow(Atom[l].r, 2) * Atom[l].vy + pow(Atom[j].r, 2) * Atom[j].vy) / (pow(Atom[j].r, 2) + pow(Atom[l].r, 2));

				Atom[j].vx = 2 * Vx - Atom[j].vx;
				Atom[j].vy = 2 * Vy - Atom[j].vy;

				Atom[l].vx = 2 * Vx - Atom[l].vx;
				Atom[l].vy = 2 * Vy - Atom[l].vy;

				cout << "Kollision" << endl;//for debugging
			}
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