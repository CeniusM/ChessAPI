// ChessAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "PrintChessBoard.h"
#include "FENHandler.h"

int main()
{
    std::cout << "Hello World!\n";

    //ChessBoard chessGame;
    //chessGame.m_board[0] = Piece::BRook;
    //chessGame.m_board[1] = Piece::BKnight;
    //chessGame.m_board[2] = Piece::BBishop;
    //chessGame.m_board[3] = Piece::BQueen;
    //chessGame.m_board[4] = Piece::BKing;
    //chessGame.m_board[5] = Piece::BBishop;
    //chessGame.m_board[6] = Piece::BKnight;
    //chessGame.m_board[7] = Piece::BRook;
    //
    //chessGame.m_board[56] = Piece::WRook;
    //chessGame.m_board[57] = Piece::WKnight;
    //chessGame.m_board[58] = Piece::WBishop;
    //chessGame.m_board[59] = Piece::WKing;
    //chessGame.m_board[60] = Piece::WQueen;
    //chessGame.m_board[61] = Piece::WBishop;
    //chessGame.m_board[62] = Piece::WKnight;
    //chessGame.m_board[63] = Piece::WRook;
    //
    //for (int i = 0; i < 8; i++)
    //{
    //    chessGame.m_board[8 + i] = Piece::BPawn;
    //    chessGame.m_board[48 + i] = Piece::WPawn;
    //}
    //chessGame.m_board[51] = Piece::None;
    //chessGame.m_board[35] = Piece::WPawn;
    //
    //chessGame.m_playerTurn = 8;
    ////chessGame.m_enPassantPiece = 20; // e6
    //chessGame.m_enPassantPiece = 43; // d3
    //chessGame.m_castle = 0b0101;
    //chessGame.m_halfMove = 0;
    //chessGame.m_fullMove = 0;
    //
    //chessGame.moveStack.Push(Move(51, 35, 0, 0));
    //chessGame.moveStack.Push(Move(5, 6, 0, 0));
    //chessGame.moveStack.Push(Move(47, 20, 0, 0));

    ChessBoard* boardPtr = FENHandler::GetBoard("rnbqkb1r/p1p1p2p/8/1pPnP1p1/3p1p2/1Q1B1N2/PP1P1PPP/RNB2RK1 w kq g6 0 9");
    ChessBoard& chessGame = *boardPtr;

    std::string str;
    while (true)
    {
        PrintChessBoardAndStats(chessGame);
        std::getline(std::cin, str);

        if (str == "Back")
        {
            chessGame.moveStack.Pop();
        }
        else if (str == "Set EnPassent")
        {

        }
        else if (str == "Dump Board")
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (chessGame.m_board[(i * 8) + j] < 10)
                        std::cout << " " << chessGame.m_board[(i * 8) + j] << ".";
                    else
                        std::cout << chessGame.m_board[(i * 8) + j] << ".";
                }
                std::cout << "\n";
            }
            std::getline(std::cin, str);
        }
        else if (str.length() == 5) // make move, fx f7 e3
        {
            int move1, move2;
            move1 = str[0] - 'a' + 8 + ((8 - (str[1] - '0') - 1) * 8);
            move2 = str[3] - 'a' + 8 + ((8 - (str[4] - '0') - 1) * 8);
            chessGame.MakeMove(Move(move1,move2,0));
        }
        else if (str.length() == 2) // print possible moves for sertin square
        {
            int move1;
            move1 = str[0] - 'a' + 8 + ((8 - (str[1] - '0') - 1) * 8);
        }
    }
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
