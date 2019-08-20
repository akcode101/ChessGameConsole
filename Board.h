
#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED
#include <string>
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"

class Piece;



class Board
{
public:
	Board();
	~Board();
	void display();
	bool getWhiteKingTaken() { return whiteKingTaken; }
	bool getBlackKingTaken() { return blackKingTaken; }
	bool checkMove(std::string move, bool whitesTurn);
	bool checkPawnMove(int iRow, int iCol, int fRow, int fCol);
	bool checkBishopMove(int iRow, int iCol, int fRow, int fCol);
	bool checkRookMove(int iRow, int iCol, int fRow, int fCol);
	bool checkQueenMove(int iRow, int iCol, int fRow, int fCol);
	bool checkKingMove(int iRow, int iCol, int fRow, int fCol);
	bool checkKnightMove(int iRow, int iCol, int fRow, int fCol);
	bool inCheck();
	bool inCheckmate();
	

private:
	char chessBoard[8][8]= {
		{ 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
	{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
	{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' }
	};
	bool whiteKingTaken;
	bool blackKingTaken;
	
	//std::vector <Piece*> myPieces;
};

#endif