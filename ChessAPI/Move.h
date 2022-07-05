#pragma once

struct Move
{
    struct Flag // Move::Flag::foo
    {
        static const char None = 0;
        static const char EnPassantCapture = 1;
        static const char Castling = 2;
        static const char PromoteToQueen = 3;
        static const char PromoteToKnight = 4;
        static const char PromoteToRook = 5;
        static const char PromoteToBishop = 6;
        static const char PawnTwoForward = 7;
    };

    char StartSquare;
    char TargetSquare;
    char MoveFlag;
    char CapturedPiece;

    Move(char startSquare, char targetSquare, char flag, char capturedPiece = 0)
    {
        StartSquare = startSquare;
        TargetSquare = targetSquare;
        MoveFlag = flag;
        CapturedPiece = capturedPiece;
    }
};