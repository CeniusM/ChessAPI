#pragma once


#include "MoveStack.h"
#include "Move.h"
#include "Piece.h"

class ChessBoard
{
public:
	static const int WhiteMask = 0b00001000;
	static const int BlackMask = 0b00010000;
	static const int ColorMask = WhiteMask | BlackMask;

	MoveStack moveStack;
	int m_board[64]{0};
	int m_castle = 0;
	int m_enPassantPiece = 64;
	int m_halfMove = 0;
	int m_fullMove = 0;
	int m_playerTurn = 8; // 8 = white, 16 = black

	void MakeMove();
	void UnMakeMove();
	void ChangePlayer();

	ChessBoard();
	ChessBoard(MoveStack moveStack, int m_board[64], int m_castle, int m_enPassantPiece, int m_halfMove, int m_fullMove, int m_playerTurn);
	~ChessBoard();

private:

};