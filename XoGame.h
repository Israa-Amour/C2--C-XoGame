#pragma once
#include"xoGrid.h" ;

class XoGame
{
private:
	XoGrid grid;
	int turn;
public:
	XoGame();
	bool isDone();
	void drawXOGrid();
	void promptPlayerToEnterLocation();
	int getWinner();

};

