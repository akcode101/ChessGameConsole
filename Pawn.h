#ifndef PAWN_INCLUDED
#define PAWN_INCLUDED
//#include "Board.h"
#include "Piece.h"
class Board;
class Pawn: public Piece  
{
	public:
		Pawn(int r, int c, bool white, Board * board):Piece(r, c, white, board)
		{
			
		}
		virtual bool  checkMove(int finalRow, int finalCol);

	~Pawn();
	
};
#endif
