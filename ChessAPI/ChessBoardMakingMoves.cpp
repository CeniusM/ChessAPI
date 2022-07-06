

#include "ChessBoard.h"

void ChessBoard::MakeMove(Move move)
{
	m_board[move.TargetSquare] = m_board[move.StartSquare];
	m_board[move.StartSquare] = 0;
	moveStack.Push(move);
}

void ChessBoard::UnMakeMove()
{
}

void ChessBoard::ChangePlayer()
{
}
