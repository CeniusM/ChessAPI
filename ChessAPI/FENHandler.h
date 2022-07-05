#pragma once
#include <string>
#include <exception>

#include "ChessBoard.h"

class FENHandler
{
public:

    static int GetPiece(char c)
    {
        switch (c)
        {
        case 'P':
            return Piece::WPawn;
        case 'N':
            return Piece::WKnight;
        case 'B':
            return Piece::WBishop;
        case 'R':
            return Piece::WRook;
        case 'Q':
            return Piece::WQueen;
        case 'K':
            return Piece::WKing;
        case 'p':
            return Piece::BPawn;
        case 'n':
            return Piece::BKnight;
        case 'b':
            return Piece::BBishop;
        case 'r':
            return Piece::BRook;
        case 'q':
            return Piece::BQueen;
        case 'k':
            return Piece::BKing;
        default:
            return -1;
        }
    }

    static char GetChar(int i)
    {
        switch (i)
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

	static ChessBoard* GetBoard(std::string string) // end at null
	{
        int FENPointer = 0;
        ChessBoard* boardPtr = new ChessBoard();
        ChessBoard& board = *boardPtr;

        int boardPointer = 0;
        while (true)
        {
            if (boardPointer > 64)
                throw std::exception("Board pointer out of range");
            if (FENPointer > 72)
                throw std::exception("FEN string too long");

            char c = string[FENPointer];

            if (isdigit(c))
            {
                boardPointer += c - '0' - 1;
            }
            if (c == '/')
            {
                boardPointer--;
            }
            else
            {
                if (!isdigit(c) && c != ' ')
                    board.m_board[boardPointer] = GetPiece(c);
            }
            if (c == ' ')
                break;
            boardPointer++;
            FENPointer++;
        }
        FENPointer++;

        if (string[FENPointer] == 'w')
            board.m_playerTurn = 8;
        else
            board.m_playerTurn = 16;
        FENPointer += 2;

        board.m_castle = 0;
        for (int i = 0; i < 4; i++)
        {
            if (string[FENPointer] == 'K')
            {
                board.m_castle = (board.m_castle | 0b1000);
            }
            else if (string[FENPointer] == 'Q')
            {
                board.m_castle = (board.m_castle | 0b0100);
            }
            else if (string[FENPointer] == 'k')
            {
                board.m_castle = (board.m_castle | 0b0010);
            }
            else if (string[FENPointer] == 'q')
            {
                board.m_castle = (board.m_castle | 0b0001);
            }
            else if (string[FENPointer] == ' ')
                break;
            FENPointer++;
        }
        FENPointer++;

        board.m_enPassantPiece = 0;
        if (string[FENPointer] != '-')
        {
            board.m_enPassantPiece += string[FENPointer] - 'a';
            FENPointer++;
            board.m_enPassantPiece += 64 - ((string[FENPointer] - '0') * 8);
        }
        else
            board.m_enPassantPiece = 64;
        FENPointer++;
        FENPointer++;

        if (string[FENPointer + 1] != ' ')
        {
            board.m_halfMove += (string[FENPointer] - '0') * 10;
            FENPointer++;
            board.m_halfMove += (string[FENPointer] - '0');
        }
        else
            board.m_halfMove += (string[FENPointer] - '0');
        FENPointer++;
        FENPointer++;

        if (string.length() > FENPointer + 1 && string[FENPointer] + 1 != ' ')
        {
            board.m_fullMove += (string[FENPointer] - '0') * 10;
            FENPointer++;
            board.m_fullMove += (string[FENPointer] - '0');
        }
        else
            board.m_fullMove += (string[FENPointer] - '0');



        return boardPtr;
	}

	static std::string GetString(ChessBoard board) // end at null
	{
        
	}
};