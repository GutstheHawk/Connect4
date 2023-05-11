#include <iomanip>
#include <iostream>
#include <string>
#include "Chip.h"
#include "Board.h"
#include "Player.h"
#include <ctime>
using namespace std;

int main()
{
	Board gameboard{};

	int turn = 0;
	int row = 0;
	bool winCheck = false;
	int color1 = 0; 
	int color2 = 0;
	string actname, name1, name2, strcolor1, strcolor2, colorInput;

	cout << "Welcome to connect 4!\n" << endl;

	gameboard.toString();

	cout << "Please enter player 1's name." << endl;
	cin >> name1;
	cout << "\nPlease enter player 2's name." << endl;
	cin >> name2;

	cout << "\nChoose your color player 1. Press 1 for red or 2 for green." << endl;
	cin >> colorInput;

	if (colorInput == "1")
	{
		color1 = 1;
		color2 = 2;
		
		strcolor1 = "Red";
		strcolor2 = "Green";
	}
	else if (colorInput == "2")
	{
		color1 = 2;
		color2 = 1;

		strcolor1 = "Green";
		strcolor2 = "Red";
	}

	while ((colorInput != "1") && (colorInput != "2"))
	{
		cout << "\nThat is not a valid color choice! Please enter either 1 for red or 2 for green." << endl;
		cin >> colorInput;

		if (colorInput == "1")
		{
			color1 = 1;
			color2 = 2;

			strcolor1 = "Red";
			strcolor2 = "Green";
		}
		else if (colorInput == "2")
		{
			color1 = 2;
			color2 = 1;

			strcolor1 = "Green";
			strcolor2 = "Red";
		}
	}


	Player player1{ name1, strcolor1 };
	Player player2{ name2, strcolor2 };
	
	Chip chipR{ color1 };
	Chip chipG{ color2 };

	cout << name1 << " is " << strcolor1 << "!" << endl;
	cout << name2 << " is " << strcolor2 << "!" << endl;
	cout << name1 << " goes first!\n" << endl;

	while (turn < 42 && winCheck == false)
	{
		if ((turn % 2) == 0)
		{
			cout << name1 << ", choose the row to drop your chip! (1-7)" << endl;
			cin >> row;
			gameboard.setROG(1);
			gameboard.dropChip(chipR, (row - 1));
			actname = name1;
		}
		else
		{
			cout << name2 << ", choose the row to drop your chip! (1-7)" << endl;
			cin >> row;
			gameboard.setROG(2);
			gameboard.dropChip(chipG, (row - 1));
			actname = name2;
		}

		gameboard.toString();

		if (gameboard.isWinner() == 1)
		{
			cout << actname << " is the winner!" << endl;
			winCheck = true;
		}
		else
		{
			turn++;
		}

		if (turn >= 42)
		{
			cout << "Tie Game...Try again next time!" << endl;
		}
	}
}
