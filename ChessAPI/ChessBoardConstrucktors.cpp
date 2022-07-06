

#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
}

ChessBoard::ChessBoard(MoveStack moveStack, int m_board[64], int m_castle, int m_enPassantPiece, int m_halfMove, int m_fullMove, int m_playerTurn)
{
	this->moveStack = moveStack;
	for (int i = 0; i < 64; i++)
	{
		this->m_board[i] = m_board[i];
		if (m_board[i] != 0)
			pieceList.AddPieceAtSquare(i);
	}
	this->m_castle = m_castle;
	this->m_enPassantPiece = m_enPassantPiece;
	this->m_halfMove = m_halfMove;
	this->m_fullMove = m_fullMove;
	this->m_playerTurn = m_playerTurn;
}

ChessBoard::~ChessBoard()
{
}