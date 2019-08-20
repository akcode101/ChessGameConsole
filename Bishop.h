#ifndef BISHOP_INCLUDED
#define BISHOP_INCLUDED
#include "Piece.h"
class Bishop: public Piece {
public:
	Bishop(int r, int c, bool white, Board * b) : Piece(r, c, white, b)
	{
	}
	~Bishop();
	virtual bool  checkMove(int finalRow, int finalCol);
private:
	
	
};
#endif
