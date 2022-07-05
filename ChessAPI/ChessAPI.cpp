// ChessAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "PrintChessBoard.h"

int main()
{
    std::cout << "Hello World!\n";

    ChessBoard chessGame;
    chessGame.m_board[0] = Piece::BRook;
    chessGame.m_board[1] = Piece::BKnight;
    chessGame.m_board[2] = Piece::BBishop;
    chessGame.m_board[3] = Piece::BQueen;
    chessGame.m_board[4] = Piece::BKing;
    chessGame.m_board[5] = Piece::BBishop;
    chessGame.m_board[6] = Piece::BKnight;
    chessGame.m_board[7] = Piece::BRook;

    chessGame.m_board[56] = Piece::WRook;
    chessGame.m_board[57] = Piece::WKnight;
    chessGame.m_board[58] = Piece::WBishop;
    chessGame.m_board[59] = Piece::WKing;
    chessGame.m_board[60] = Piece::WQueen;
    chessGame.m_board[61] = Piece::WBishop;
    chessGame.m_board[62] = Piece::WKnight;
    chessGame.m_board[63] = Piece::WRook;

    for (int i = 0; i < 8; i++)
    {
        chessGame.m_board[8 + i] = Piece::BPawn;
        chessGame.m_board[48 + i] = Piece::WPawn;
    }

    chessGame.m_playerTurn = 8;
    //chessGame.m_enPassantPiece = 20; // e6
    chessGame.m_enPassantPiece = 43; // d3
    chessGame.m_castle = 0b0101;
    chessGame.m_halfMove = 0;
    chessGame.m_fullMove = 0;

    PrintChessBoardAndStats(chessGame);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
