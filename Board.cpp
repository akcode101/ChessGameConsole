#include "Board.h"
#include <iostream>
#include <algorithm>
using namespace std;



Board::Board()
{
	whiteKingTaken = false;
	blackKingTaken = false;
}


Board::~Board()
{
}

void Board::display()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j <= 7; j++)
		{
			cout << chessBoard[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
//Returns false if move, is invalid, does nothing
//if true, updates board and returns true
bool Board::checkMove(string move, bool whitesTurn)
{
	
	int initCol = move[0] - 'a';
	int initRow = move[1] - '1';
	int finalCol = move[2] - 'a';
	int finalRow = move[3] - '1';
	
	char piece = chessBoard[initRow][initCol];
	char initFinalPiece = chessBoard[finalRow][finalCol];
	if (isupper(piece) && !whitesTurn)
		return false;
	if (islower(piece) && whitesTurn)
		return false;
	
	if (piece == '-')
		return false;
	if (initRow < 0 || initRow>7 || finalRow < 0 || finalRow>7)
		return false;
	if (piece == 'P' || piece == 'p')
	{
		bool check = checkPawnMove(initRow, initCol, finalRow, finalCol);
		if (check == true)
		{
			if (initFinalPiece == 'K')
				whiteKingTaken = true;
			if (initFinalPiece == 'k')
				blackKingTaken = true;
		}

		return check;
	}
		
	if (piece == 'R' || piece == 'r')
	{
		bool check = checkRookMove(initRow, initCol, finalRow, finalCol);
		if (check == true)
		{
			if (initFinalPiece == 'K')
				whiteKingTaken = true;
			if (initFinalPiece == 'k')
				blackKingTaken = true;
		}

		return check;
	}
	
	if (piece == 'B' || piece == 'b')
	{
		bool check = checkBishopMove(initRow, initCol, finalRow, finalCol);
		if (check == true)
		{
			if (initFinalPiece == 'K')
				whiteKingTaken = true;
			if (initFinalPiece == 'k')
				blackKingTaken = true;
		}

		return check;
	}
	if (piece == 'Q' || piece == 'q')
	{
		bool check = checkQueenMove(initRow, initCol, finalRow, finalCol);
		
		if (check == true)
		{
			chessBoard[finalRow][finalCol] = piece;
			if (initFinalPiece == 'K')
				whiteKingTaken = true;
			if (initFinalPiece == 'k')
				blackKingTaken = true;
		}
		return check;
	}
		
	if (piece == 'K' || piece == 'k')
	{
		bool check = checkKingMove(initRow, initCol, finalRow, finalCol);
		if (check == true)
		{
			if (initFinalPiece == 'K')
				whiteKingTaken = true;
			if (initFinalPiece == 'k')
				blackKingTaken = true;
		}

		return check;
	}
	if (piece == 'N' || piece == 'n')
	{
		bool check = checkKnightMove(initRow, initCol, finalRow, finalCol);
		if (check == true)
		{
			if (initFinalPiece == 'K')
				whiteKingTaken = true;
			if (initFinalPiece == 'k')
				blackKingTaken = true;
		}

		return check;
	}
		

	return false;
}

bool Board::checkPawnMove(int iRow, int iCol, int fRow, int fCol)
{
	if (isupper(chessBoard[iRow][iCol]))
	{
		//forward moves
		if (iCol == fCol)
		{
			if (iRow == 1 && fRow == 3)
			{
				if (chessBoard[2][iCol] == '-' && chessBoard[3][iCol] == '-')
				{
					chessBoard[iRow][iCol] = '-';
					chessBoard[fRow][fCol] = 'P';
					return true;
				}
			}
			else if (iRow + 1 == fRow)
			{
				if (chessBoard[iRow + 1][iCol] == '-')
				{
					chessBoard[iRow][iCol] = '-';
					chessBoard[fRow][fCol] = 'P';
					return true;
				}
			}

		}
		else if (abs(fCol - iCol) == 1)
		{
			if (fRow == iRow + 1)
			{
				if (islower(chessBoard[fRow][fCol] ))
				{
					chessBoard[iRow][iCol] = '-';
					chessBoard[fRow][fCol] = 'P';
					return true;
				}
			}
		}
		
		return false;
	}
	else
	{
		
			//forward moves
			if (iCol == fCol)
			{
				if (iRow == 6 && fRow == 4)
				{
					if (chessBoard[5][iCol] == '-' && chessBoard[4][iCol] == '-')
					{
						chessBoard[iRow][iCol] = '-';
						chessBoard[fRow][fCol] = 'p';
						return true;
					}
				}
				else if (iRow - 1 == fRow)
				{
					if (chessBoard[iRow - 1][iCol] == '-')
					{
						chessBoard[iRow][iCol] = '-';
						chessBoard[fRow][fCol] = 'p';
						return true;
					}
				}

			}
			else if (abs(fCol - iCol) == 1)
			{
				if (fRow == iRow - 1)
				{
					if (isupper(chessBoard[fRow][fCol]))
					{
						chessBoard[iRow][iCol] = '-';
						chessBoard[fRow][fCol] = 'p';
						return true;
					}
				}
			}

			return false;
	}
}

bool Board::checkBishopMove(int iRow, int iCol, int fRow, int fCol)
{
	int rowDiff = abs(iRow - fRow);
	int colDiff = abs(iCol - fCol);
	if (rowDiff != colDiff)
		return false;
	if (iRow == fRow && iCol == fCol)
		return false;
	if (isupper(chessBoard[iRow][iCol]))
	{
			if (isupper(chessBoard[fRow][fCol]))
			{
				return false;
			}
		
			if (iRow < fRow && iCol < fCol)
			{
				for (int i = 1; i <= rowDiff-1; i++)
				{
					if (chessBoard[iRow + i][iCol + i] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'B';
				return true;
			}

			else if (iRow > fRow && iCol > fCol)
			{
				for (int i = 1; i <= rowDiff - 1; i++)
				{
					if (chessBoard[iRow - i][iCol - i] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'B';
				return true;
			}

			else if (iRow > fRow && iCol < fCol)
			{
				for (int i = 1; i <= rowDiff - 1; i++)
				{
					if (chessBoard[iRow - i][iCol + i] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'B';
				return true;
			}

			else if (iRow<fRow && iCol>fCol)
			{
				for (int i = 1; i <= rowDiff - 1; i++)
				{
					if (chessBoard[iRow + i][iCol - i] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'B';
				return true;
			}

		
	}
	else
	{
		if (islower(chessBoard[fRow][fCol]))
		{
			return false;
		}

		if (iRow < fRow && iCol < fCol)
		{
			for (int i = 1; i <= rowDiff - 1; i++)
			{
				if (chessBoard[iRow + i][iCol + i] != '-')
					return false;
			}
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'b';
			return true;
		}

		else if (iRow > fRow && iCol > fCol)
		{
			for (int i = 1; i <= rowDiff - 1; i++)
			{
				if (chessBoard[iRow - i][iCol - i] != '-')
					return false;
			}
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'b';
			return true;
		}

		else if (iRow > fRow && iCol < fCol)
		{
			for (int i = 1; i <= rowDiff - 1; i++)
			{
				if (chessBoard[iRow - i][iCol + i] != '-')
					return false;
			}
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'b';
			return true;
		}

		else if (iRow<fRow && iCol>fCol)
		{
			for (int i = 1; i <= rowDiff - 1; i++)
			{
				if (chessBoard[iRow + i][iCol - i] != '-')
					return false;
			}
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'b';
			return true;
		}
	}

	return false;
}

bool Board::checkRookMove(int iRow, int iCol, int fRow, int fCol)
{
	if (iRow != fRow && iCol != fCol)
		return false;
	if (iRow == fRow && iCol == fCol)
		return false;
	if (isupper(chessBoard[iRow][iCol]))
	{
		if (isupper(chessBoard[fRow][fCol]))
		{
			return false;
		}
		if (iRow != fRow)
		{
			if (iRow < fRow)
			{
				for (int k = iRow + 1; k <= fRow - 1; k++)
				{
					if (chessBoard[k][iCol] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'R';
				return true;

			}
			else
			{
				for (int k = iRow - 1; k >= fRow + 1; k--)
				{
					if (chessBoard[k][iCol] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'R';
				return true;

			}

		}
		else 
		{
			if (iCol < fCol)
			{
				for (int k = iCol + 1; k <= fCol - 1; k++)
				{
					if (chessBoard[iRow][k] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'R';
				return true;

			}
			else
			{
				for (int k = iCol - 1; k >= fCol + 1; k--)
				{
					if (chessBoard[iRow][k] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'R';
				return true;

			}

		}
		
	}
	else
	{
		if (islower(chessBoard[fRow][fCol]))
		{
			return false;
		}
		if (iRow != fRow)
		{
			if (iRow < fRow)
			{
				for (int k = iRow + 1; k <= fRow - 1; k++)
				{
					if (chessBoard[k][iCol] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'r';
				return true;

			}
			else
			{
				for (int k = iRow - 1; k >= fRow + 1; k--)
				{
					if (chessBoard[k][iCol] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'r';
				return true;

			}

		}
		else 
		{
			if (iCol < fCol)
			{
				for (int k = iCol + 1; k <= fCol - 1; k++)
				{
					if (chessBoard[iRow][k] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'r';
				return true;

			}
			else
			{
				for (int k = iCol - 1; k >= fCol + 1; k--)
				{
					if (chessBoard[iRow][k] != '-')
						return false;
				}
				chessBoard[iRow][iCol] = '-';
				chessBoard[fRow][fCol] = 'r';
				return true;

			}

		}
	}

	return false;
}

bool Board::checkQueenMove(int iRow, int iCol, int fRow, int fCol)
{
	return checkRookMove(iRow, iCol, fRow, fCol) || checkBishopMove(iRow, iCol, fRow, fCol);
}

bool Board::checkKingMove(int iRow, int iCol, int fRow, int fCol)
{
	if (iRow == fRow && iCol == fCol)
		return false;
	int rowDiff = abs(iRow - fRow);
	int colDiff = abs(iCol - fCol);
	if (rowDiff > 1 || colDiff > 1)
		return false;
	if (isupper(chessBoard[iRow][iCol]))
	{
		if (!isupper(chessBoard[fRow][fCol]))
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'K';
			return true;
		}
	}
	if (islower(chessBoard[iRow][iCol]))
	{
		if (!islower(chessBoard[fRow][fCol]))
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'k';
			return true;
		}
	}
	if (iRow == 0 && iCol == 4 && fRow == 0 && fCol == 6)
	{
		if (chessBoard[0][5] == '-' && chessBoard[0][6] == '-' && chessBoard[0][7] == 'R')
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'K';
			chessBoard[0][5] = 'R';
			return true;
		}
		return false;
	}
	if (iRow == 7 && iCol == 4 && fRow == 7 && fCol == 6)
	{
		if (chessBoard[7][5] == '-' && chessBoard[7][6] == '-' && chessBoard[7][7] == 'r')
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'k';
			chessBoard[7][5] = 'r';
			return true;
		}
		return false;
	}
	if (iRow == 0 && iCol == 4 && fRow == 0 && fCol == 6)
	{
		if (chessBoard[0][5] == '-' && chessBoard[0][6] == '-' && chessBoard[0][7] == 'R')
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'K';
			chessBoard[0][5] = 'R';
			return true;
		}
		return false;
	}
	if (iRow == 0 && iCol == 4 && fRow == 0 && fCol == 2)
	{
		if (chessBoard[0][3] == '-' && chessBoard[0][2] == '-' && chessBoard[0][1] == '-' && chessBoard[0][0]=='R')
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'K';
			chessBoard[0][3] = 'R';
			return true;
		}
		return false;
	}
	if (iRow == 7 && iCol == 4 && fRow == 7 && fCol == 2)
	{
		if (chessBoard[7][3] == '-' && chessBoard[7][2] == '-' && chessBoard[7][1] == '-' && chessBoard[7][0] == 'r')
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'k';
			chessBoard[7][3] = 'r';
			return true;
		}
		return false;
	}
	
	return false;
}

bool Board::checkKnightMove(int iRow, int iCol, int fRow, int fCol)
{
	if (iRow == fRow && iCol == fCol)
		return false;
	int rowDiff = abs(iRow - fRow);
	int colDiff = abs(iCol - fCol);
	if (!(rowDiff == 1 && colDiff == 2) && !(colDiff == 1 && rowDiff == 2))
	{
		return false;
	}
	if (isupper(chessBoard[iRow][iCol]))
	{
		if (!isupper(chessBoard[fRow][fCol]))
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'N';
			return true;
		}
	}
	if (islower(chessBoard[iRow][iCol]))
	{
		if (!islower(chessBoard[fRow][fCol]))
		{
			chessBoard[iRow][iCol] = '-';
			chessBoard[fRow][fCol] = 'n';
			return true;
		}
	}
	return false;

}

bool Board::inCheck()
{
	return false;
}

bool Board::inCheckmate()
{
	return false;
}
