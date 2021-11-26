#include "xoGame.h"
#include<iostream>
using namespace std;
XoGame:: XoGame()
{
	turn = 1;
}
bool XoGame:: isDone()
{
	int winner = getWinner();
	if (winner != 0)
		return true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			if (grid.getEntry(i, j) == -1)
				return false;
		}
	}

	return true;
}
void XoGame:: drawXOGrid() {
	grid.print();
}
void XoGame:: promptPlayerToEnterLocation() {
	char playerName;
	if (turn == 1) {
		playerName = grid.x;
	}
	else {
		playerName = grid.o;
	}
	int currentRow, currentColumn;
	while (true) {
		cout << "Player [" << playerName << "] turn to play , please enter row and column values between 0 and 2 " << endl;
		while (true) {
			cin >> currentRow;
			if (currentRow < 0 || currentRow > 2)
				cout << "Invalid row value " << endl;
			else
				break;
		}
		while (true) {
			cin >> currentColumn; if (currentColumn < 0 || currentColumn > 2)
				cout << "Invalid column value " << endl;
			else
				break;
		}
		int oldEntry = grid.getEntry(currentRow, currentColumn);
		if (oldEntry != -1) {
			cout << "Entry is already filled , please choose different row , column values" << endl;
		}
		else
			break;
	}
	if (turn == 1)
	{
		grid.setEntry(currentRow, currentColumn, grid.x);
		turn = 2;
	}
	else if (turn == 2)
	{
		grid.setEntry(currentRow, currentColumn, grid.o);
		turn = 1;
	}
}
int  XoGame::getWinner() {
	for (int i = 1; i <= 2; i++) {
		char mychar;
		if (i == 1)
			mychar = grid.x;
		else
			mychar = grid.o;
		if (grid.getEntry(0, 0) == mychar && grid.getEntry(0, 0) == grid.getEntry(0, 1) && grid.getEntry(0, 0) == grid.getEntry(0, 2))
			return i;
		else if (grid.getEntry(1, 0) == mychar && grid.getEntry(1, 0) == grid.getEntry(1, 1) && grid.getEntry(1, 0) == grid.getEntry(1, 2))
			return i;
		else if (grid.getEntry(2, 0) == mychar && grid.getEntry(2, 0) == grid.getEntry(2, 1) && grid.getEntry(2, 0) == grid.getEntry(2, 2))
			return i;
		else if (grid.getEntry(0, 0) == mychar && grid.getEntry(0, 0) == grid.getEntry(1, 0) && grid.getEntry(0, 0) == grid.getEntry(2, 0))
			return i;
		else if (grid.getEntry(0, 1) == mychar && grid.getEntry(0, 1) == grid.getEntry(1, 1) && grid.getEntry(0, 1) == grid.getEntry(2, 1))
			return i;
		else if (grid.getEntry(0, 2) == mychar && grid.getEntry(0, 2) == grid.getEntry(1, 2) && grid.getEntry(0, 2) == grid.getEntry(2, 2))
			return i;
		else if (grid.getEntry(0, 0) == mychar && grid.getEntry(0, 0) == grid.getEntry(1, 1) && grid.getEntry(0, 0) == grid.getEntry(2, 2))
			return i;
		else if (grid.getEntry(2, 0) == mychar && grid.getEntry(2, 0) == grid.getEntry(1, 1) && grid.getEntry(2, 0) == grid.getEntry(0, 2))
			return i;
	}
	return 0;
}
