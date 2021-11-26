#include<iostream>
#include"xoGame.h" ;
#include"xoGrid.h" ;
using namespace std; 
void main()
{
	cout << "Welcome to our simple X-O game: " << endl;
	cout << "Player-1 plays  with X, and Player-2 plays with O." << endl;
	while (true) {
		XoGame* xoGame = new XoGame();
		while (!xoGame->isDone()) {
			xoGame->drawXOGrid();
			xoGame->promptPlayerToEnterLocation();
		}
		xoGame->drawXOGrid();
		int xx = xoGame->getWinner();
		if (xx == 1)
			cout << "The winner is player [X]" << endl;
		else if (xx == 2)
			cout << "The winner is  player [O] " << endl;
		else
			cout << "it an even game ." << endl;
		cout << "Do you want to play again? (y,n) " << endl;
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
	}
}