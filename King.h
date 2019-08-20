#ifndef KING_INCLUDED
#define KING_INCLUDED
#include "Piece.h"
class King : public Piece {

public:
	King(int r, int c, bool white, Board * board):Piece(r, c, white, board )
	{
		
	}
	~King();
	virtual bool  checkMove(int finalRow, int finalCol);
private:
	
};
#endif

