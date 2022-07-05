#pragma once
#include <string>
#include <iostream>
#include <bitset>

#include "ChessBoard.h"

char GetCharFromPiece(char p)
{
    switch (p)
    {
    case Piece::WPawn:
        return 'P';
    case Piece::WKnight:
        return 'N';
    case Piece::WBishop:
        return 'B';
    case Piece::WRook:
        return 'R';
    case Piece::WQueen:
        return 'Q';
    case Piece::WKing:
        return 'K';
    case Piece::BPawn:
        return 'p';
    case Piece::BKnight:
        return 'n';
    case Piece::BBishop:
        return 'b';
    case Piece::BRook:
        return 'r';
    case Piece::BQueen:
        return 'q';
    case Piece::BKing:
        return 'k';
    default:
        return -1;
    }
}

void PrintChessBoard(ChessBoard& chessGame);

void PrintChessBoardAndStats(ChessBoard& chessGame)
{
    PrintChessBoard(chessGame);

    std::cout << "Player Turn: " << (chessGame.m_playerTurn == 8 ? "White" : (chessGame.m_playerTurn == 16 ? "Black" : "Error")) << "\n";
    std::cout << "EnPassent Piece: " << static_cast<char>(chessGame.m_enPassantPiece % 8 + 'a') << static_cast<char>( 8 - (chessGame.m_enPassantPiece >> 3) + '0') << "\n";
    std::bitset<4> foo(chessGame.m_castle);
    std::cout << "Castle: " << foo << "\n";
    std::cout << "HalfMove: " << chessGame.m_halfMove << "\n";
    std::cout << "FullMove: " << chessGame.m_fullMove << "\n";
}

void PrintChessBoard(ChessBoard& chessGame)
{
	const std::string line = "+---+---+---+---+---+---+---+---+";

	for (int i = 0; i < 8; i++)
	{
		std::cout << "   " << line << "\n";
        std::cout << " " << (8 - i) << " ";
		for (int j = 0; j < 8; j++)
		{
            std::cout << "| " << GetCharFromPiece(chessGame.m_board[(i * 8) + j]) << " ";
		}
        std::cout << "|\n";
	}
    std::cout << "   " << line << "\n";
    std::cout << "     A   B   C   D   E   F   G   H" << "\n";
}