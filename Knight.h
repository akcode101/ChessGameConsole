#ifndef KNIGHT_INCLUDED
#define KNIGHT_INCLUDED
#include "Piece.h"
class Knight: public Piece {
public:
	Knight(int r, int c, bool white, Board * b): Piece(r, c, white, b)
	{
		
	}
	~Knight();
	virtual bool  checkMove(int finalRow, int finalCol);
private:
	
};
#endif
