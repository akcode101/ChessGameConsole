#ifndef ROOK_INCLUDED
#define ROOK_INCLUDED
#include "Board.h"
#include "Piece.h"
class Rook: public Piece {
public:
	
	~Rook();
	Rook(int r, int c, bool white, Board * b): Piece(r, c, white, b)
	{
		
	}
	virtual bool  checkMove(int finalRow, int finalCol);
private:
	int row;
	int col;
	bool isWhite;
	bool isCaptured;
};
#endif

