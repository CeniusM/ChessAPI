#include <stdexcept>

#include "MoveStack.h"

const int StanderdNewCapacity = 10;

void MoveStack::Push(Move move)
{
	if (m_count == m_capacity) // overflow
		IncreaseCapacity();
	moves[m_count] = move;
	m_count++;
}

Move MoveStack::Pop()
{
	if (m_count == 0)
		throw std::out_of_range("Pop out of range");
	m_count--;
	return moves[m_count];
}

Move MoveStack::Peek()
{
	return moves[m_count - 1];
}

int MoveStack::Count()
{
	return m_count;
}

int MoveStack::Capacity()
{
	return m_capacity;
}

void MoveStack::Clear(int newCapacity)
{
	free(moves);
	m_count = 0;
	m_capacity = newCapacity;
	moves = (Move*)malloc(sizeof(Move) * m_capacity);
}

MoveStack::MoveStack()
{
	m_capacity = StanderdNewCapacity;
	m_count = 0;
	moves = (Move*)malloc(sizeof(Move) * m_capacity);
}

MoveStack::MoveStack(int newCapacity)
{
	m_capacity = newCapacity;
	if (m_capacity == 0)
		m_capacity = StanderdNewCapacity;
	m_count = 0;
	moves = (Move*)malloc(sizeof(Move) * m_capacity);	
}

MoveStack::~MoveStack()
{
	free(moves);
}

void MoveStack::IncreaseCapacity()
{
	// set capacity
	if (m_capacity == 0)
		m_capacity = StanderdNewCapacity;
	int oldCapacity = m_capacity;
	m_capacity = m_capacity * 2;

	// init array
	Move* newMoves = (Move*)malloc(sizeof(Move) * m_capacity);
	if (newMoves)
		throw std::exception("newMoves = nullPtr");

#pragma warning( push )
#pragma warning( disable : 6011)
	for (int i = 0; i < oldCapacity; i++)
		newMoves[i] = moves[i];
#pragma warning( pop ) 

	// free and set
	free(moves);
	moves = newMoves;
}
