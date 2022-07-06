#pragma once

// code by Sebastian Lague

struct PieceList
{
    // Indices of squares occupied by given piece type (only elements up to Count are valid, the rest are unused/garbage)
    int occupiedSquares[32]{};
    // Map to go from index of a square, to the index in the occupiedSquares array where that square is stored
    int map[64]{};
    int numPieces{};

    PieceList() { }

    int Count() { return numPieces; }

    void AddPieceAtSquare(int square)
    {
        occupiedSquares[numPieces] = square;
        map[square] = numPieces;
        numPieces++;
    }

    void RemovePieceAtSquare(int square)
    {
        int pieceIndex = map[square]; // get the index of this element in the occupiedSquares array
        occupiedSquares[pieceIndex] = occupiedSquares[numPieces - 1]; // move last element in array to the place of the removed element
        map[occupiedSquares[pieceIndex]] = pieceIndex; // update map to point to the moved element's new location in the array
        numPieces--;
    }

    void MovePiece(int startSquare, int targetSquare)
    {
        int pieceIndex = map[startSquare]; // get the index of this element in the occupiedSquares array
        occupiedSquares[pieceIndex] = targetSquare;
        map[targetSquare] = pieceIndex;
    }

    int operator[](int index)
    {
        occupiedSquares[index];
    }
};