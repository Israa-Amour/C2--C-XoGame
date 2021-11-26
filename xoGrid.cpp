#include<iostream>
#include"XoGrid.h" 
using namespace std; 
XoGrid::XoGrid()
{
	rows = 3, cols = 3;
	grid = new int*[rows];
	for (int i = 0; i <= rows; i++)
		grid[i] = new int[cols];
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j <= cols; j++)
			grid[i][j] = -1;
	}
}
void XoGrid::print()
{
	cout << endl;
	cout << char(grid[0][0]) << "   |  " << char(grid[0][1]) << " |  " << char(grid[0][2]) << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << char(grid[1][0]) << "   |  " << char(grid[1][1]) << " |  " << char(grid[1][2]) << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |     " << endl;
	cout << char(grid[2][0]) << "   |  " << char(grid[2][1]) << " |  " << char(grid[2][2]) << endl;
}
void XoGrid::setEntry(int rows, int cols, int value)
{
	grid[rows][cols] = value; // value = x || o  
}
int XoGrid::getEntry(int rows, int cols)
{
	return grid[rows][cols];
}
XoGrid :: ~XoGrid()
{
	for (int i = 0; i < 3; i++)
		delete[]grid[i];
	delete[]grid; 
}
