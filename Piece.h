#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
class Board;

class Piece
{
public:
	Piece(int r, int c, bool white, Board* board)
	{
		row = r;
		col = c;
		isWhite = white;
		isCaptured = false;
		myBoard = board;
	}
	~Piece();
	int getRow()
	{
		return row;
	}
	void setRow(int otherR)
	{
		row = otherR;
	}
	int getColumn()
	{
		return col;
	}
	void setColumn(int otherC)
	{
		col = otherC;
	}
	bool isPieceWhite()
	{
		return isWhite;
	}
	void setIsPieceWhite(bool color)
	{
		isWhite = color;
	}
	bool setState(bool state)
	{
		isCaptured = state;
	}
	bool getState()
	{
		return isCaptured;
	}
	Board * getBoard()
	{
		return myBoard;
	}
	virtual bool checkMove(int finalRow, int finalCol) = 0;


private:
	int row;
	int col;
	bool isWhite;
	bool isCaptured;
	Board * myBoard;
};
#endif

