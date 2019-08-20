#include "Board.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	cout << "Welcome to my awesome two-player chess game!" << endl;
	cout << "In this chess game, we will be using algebraic notation..." << endl;
	cout << "Thus, to specify a move, we will use 4 characters" << endl;
	cout << "Squares are specified using column, row; where the bottom left square is represented by a1 and the top right square is h8." << endl;
	cout << "Thus, to specify a move: specify square of piece you intend to move and square of final position" << endl;
	cout << "To specify the king's pawn opening, we would say e2e4" << endl;
	cout << "To rage quit at any time, type the string: quit when prompted for a move." << endl;
	cout << "Now, let's start!" << endl;
	cout << endl;
	Board board = Board();
	board.display();
	while (!board.getWhiteKingTaken() && !board.getBlackKingTaken())
	{
		cout << "Enter your move, white, in the proper notation!: ";
		string w;
		cin >> w;
		cout << endl;
		bool white = board.checkMove(w, true);
		while (white == false)
		{
			cout << "Enter your move, white, in the proper notation!: ";
			cin >> w;
			if (w == "quit") exit(0);
			white=board.checkMove(w, true);
			cout << endl;
		}
		cout << endl;
		board.display();
		cout << "********" << endl;
		
		string b;
		bool black;
		do
		{ 
			cout << "Enter your move, black, in the proper notation!: ";
			cin >> b;
			if (b == "quit") exit(0);
			black = board.checkMove(b, false);
			cout << endl;
		} while (black == false);
		cout << endl;
		board.display();
		cout << "********"<< endl;
	}
	if (board.getWhiteKingTaken() == true)
		cout << "Congratulations, Black, you have won this game!" << endl;
	else if (board.getBlackKingTaken() == true)
		cout << "Congratulations, White, you have won this game!" << endl;
}
