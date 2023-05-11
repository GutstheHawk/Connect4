#include <iomanip>
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;



	Player::Player(string name, string color)
	{
		this->name = name;
		this->color = color;
	}

	string Player::getName()
	{
		return this->name;
	}

	void Player::setName(string name)
	{
		this->name = name;
	}

	string Player::getColor()
	{
		return color;
	}

	void Player::setColor(string color)
	{
		this->color = color;
	}

	void Player::toString()
	{
		cout << "Player name: " << name << "\nPlayer color: " << color << endl;
	}
