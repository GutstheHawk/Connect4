#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "Chip.h"
using namespace std;

class Board
{
private:
	static const int num_rows = 6;

	static const int num_columns = 7;

	int board[num_columns][num_rows];

public:

	int winCount0, winCount1, winCount2, winCount3, winCount4, winCount5;
	int redOrGreen;

	Board();

	int getROG();

	void setROG(int);

	void dropChip(Chip, int);

	int isWinner();

	void toString();

	void tooString();

};