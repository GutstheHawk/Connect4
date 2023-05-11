#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string name, color;
public:

	Player(string, string);

	string getName();

	void setName(string);

	string getColor();

	void setColor(string color);

	void toString();
};