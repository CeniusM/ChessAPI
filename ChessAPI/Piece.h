#pragma once

struct Piece
{
    static const int ColorBits = 24;
    static const int PieceBits = 7;
    static const int None = 0;
    static const int Pawn = 1;
    static const int Rook = 2;
    static const int Knight = 3;
    static const int Bishop = 4;
    static const int Queen = 5;
    static const int King = 6;
    static const int White = 8;
    static const int Black = 16;
    static const int WPawn = 1 + White;
    static const int WRook = 2 + White;
    static const int WKnight = 3 + White;
    static const int WBishop = 4 + White;
    static const int WQueen = 5 + White;
    static const int WKing = 6 + White;
    static const int BPawn = 1 + Black;
    static const int BRook = 2 + Black;
    static const int BKnight = 3 + Black;
    static const int BBishop = 4 + Black;
    static const int BQueen = 5 + Black;
    static const int BKing = 6 + Black;
};