#include <iomanip>
#include <iostream>
#include <string>
#include "Chip.h"
using namespace std;


Chip::Chip(int color)
{
	this->color = color;
}

int Chip::getColor()
{
	return color;
}

void Chip::toString()
{
	cout << "Chip Color (1 is red and 2 is gold): " << color << endl;
}

