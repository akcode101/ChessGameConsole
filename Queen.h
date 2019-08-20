#ifndef QUEEN_INCLUDED
#define QUEEN_INCLUDED
#include "Piece.h"

class Queen: public Piece
{
public:
	Queen(int r, int c, bool white, Board * b): Piece(r, c, white, b )
	{
		
	}
	virtual bool  checkMove(int finalRow, int finalCol);
	~Queen();
private:
	
};
#endif

