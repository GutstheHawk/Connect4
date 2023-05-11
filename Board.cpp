#include <iostream>
#include <iomanip>
#include <string>
#include "Chip.h"
#include "Board.h"
using namespace std;


	Board::Board()
	{
		int winCount0 = 0;
		int	winCount1 = 0;
		int	winCount2 = 0;
		int winCount3 = 0;
		int winCount4 = 0;
		int winCount5 = 0;
		int redOrGreen = 0;

		for (int j = 0; j < 6; j++)
		{
			for (int i = 0; i < 7; i++)
			{
				board[i][j] = { 0 };
			}
		}
	}

	int Board::getROG()
	{
		return redOrGreen;
	}

	void Board::setROG(int rog)
	{
		redOrGreen = rog;
	}

	void Board::dropChip(Chip chippy, int dropSlot)
	{
		while (((dropSlot > -1) != true) && ((dropSlot < 7) != true))
		{
			int row = 0;
			cout << "The row you have entered is outside the range of 1 - 7. Please enter a new row for your chip:" << endl;
			cin >> row;
			dropSlot = (row - 1);
		}
		if ((dropSlot > -1) && (dropSlot < 7))
		{
			if (board[dropSlot][0] == 1 || board[dropSlot][0] == 2)
			{
				cout << "The row you have chosen is full, please enter a new row: ";
				cin >> dropSlot;
			}
			else
			{
				int iter = 5;

					if ((board[dropSlot][iter] == 1) || (board[dropSlot][iter] == 2))
					{
						iter = iter - 1;
						if ((board[dropSlot][iter] == 1) || (board[dropSlot][iter] == 2))
						{
							iter = iter - 1;
							if ((board[dropSlot][iter] == 1) || (board[dropSlot][iter] == 2))
							{
								iter = iter - 1;
								if ((board[dropSlot][iter] == 1) || (board[dropSlot][iter] == 2))
								{
									iter = iter - 1;
									if ((board[dropSlot][iter] == 1) || (board[dropSlot][iter] == 2))
									{
										iter = iter - 1;
										if ((board[dropSlot][iter] == 1) || (board[dropSlot][iter] == 2))
										{
											iter = iter - 1;
										}
										else
										{
											board[dropSlot][iter] = { chippy.getColor() };
										}
									}
									else
									{
										board[dropSlot][iter] = { chippy.getColor() };
									}
								}
								else
								{
									board[dropSlot][iter] = { chippy.getColor() };
								}
							}
							else
							{
								board[dropSlot][iter] = { chippy.getColor() };
							}
						}
						else
						{
							board[dropSlot][iter] = { chippy.getColor() };
						}
					}
					else
					{
						board[dropSlot][iter] = { chippy.getColor() };
					}
			}
		}
	}

	int Board::isWinner()
	{
		bool winState = false;

		for (int numColumn = 6; numColumn > -1; numColumn--)
		{
			for (int check = 5; check > 2; check--)
			{
				winCount0 = 0;
				if (board[numColumn][check] == redOrGreen)
				{
					winCount0++;
					if (board[numColumn - 1][check - 1] == redOrGreen)
					{
						winCount0++;
						if (board[numColumn - 2][check - 2] == redOrGreen)
						{
							winCount0++;
							if (board[numColumn - 3][check - 3] == redOrGreen)
							{
								winCount0++;
								if (winCount0 == 4)
								{
									winState = true;
								}
							}
						}
					}
				}
			}
		}

		for (int numColumn = 0; numColumn < 7; numColumn++)
		{
			for (int check = 5; check > 2; check--)
			{
				winCount1 = 0;
				if (board[numColumn][check] == redOrGreen)
				{
					winCount1++;
					if (board[numColumn + 1][check - 1] == redOrGreen)
					{
						winCount1++;
						if (board[numColumn + 2][check - 2] == redOrGreen)
						{
							winCount1++;
							if (board[numColumn + 3][check - 3] == redOrGreen)
							{
								winCount1++;
								if (winCount1 == 4)
								{
									winState = true;
								}
							}
						}
					}
				}
			}
		}

		/*
		cout << numColumn << "wincount2 check 1: " << winCount2 << endl;
		*/

		for (int numColumn = 0; numColumn < 7; numColumn++)
		{
			for (int check = 5; check > 2; check--)
			{
				winCount2 = 0;
				if (board[numColumn][check] == redOrGreen)
				{
					winCount2++;
					if (board[numColumn][check - 1] == redOrGreen)
					{
						winCount2++;
						if (board[numColumn][check - 2] == redOrGreen)
						{
							winCount2++;
							if (board[numColumn][check - 3] == redOrGreen)
							{
								winCount2++;
								if (winCount2 == 4)
								{
									winState = true;
								}
							}
						}
					}
				}
			}
		}

		for (int numRow = 5; numRow > 0; numRow--)
		{
			for (int check1 = 0; check1 < 4; check1++)
			{
				winCount3 = 0;
				if (board[check1][numRow] == redOrGreen)
				{
					winCount3++;
					if (board[check1 + 1][numRow] == redOrGreen)
					{
						winCount3++;
						if (board[check1 + 2][numRow] == redOrGreen)
						{
							winCount3++;
							if (board[check1 + 3][numRow] == redOrGreen)
							{
								winCount3++;
								if (winCount3 == 4)
								{
									winState = true;
								}
							}
						}
					}
				}
			}
		}

		if (winState == true)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}


	void Board::toString()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (board[j][i] == 0)
				{
					cout << "X ";
				}
				else if (board[j][i] == 1)
				{
					cout << "R ";
				}
				else if (board[j][i] == 2)
				{
					cout << "G ";
				}
				else
				{
					cout << "Something went wrong with your array!";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	/*
	void Board::tooString()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << board[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/

