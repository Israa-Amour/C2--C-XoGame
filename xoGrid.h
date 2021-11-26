#pragma once
class XoGrid {
private:
	int rows;
	int cols;
	int** grid;
public:
	char x = 'X';
	char o = 'O';
	XoGrid();
	void print();
	void setEntry(int row, int clos, int value);
	int getEntry(int row, int column);
	~XoGrid();
};

