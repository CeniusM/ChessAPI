#pragma once


#include "Move.h"

class MoveStack
{
public:

	void Push(Move move);
	Move Pop();
	Move Peek();
	int Count();
	int Capacity();
	void Clear(int newCapacity);

	MoveStack();
	MoveStack(int newCapacity);
	~MoveStack();

private:
	Move* moves;

	int m_count; // stack ptr
	int m_capacity;

	void IncreaseCapacity();
};