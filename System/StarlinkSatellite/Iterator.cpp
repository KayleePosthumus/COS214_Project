#include "Iterator.h"

Iterator::Iterator()
	: first(nullptr), current(nullptr)
{
}

Iterator::~Iterator()
{
}

Iterator::Iterator(Payload *first)
	: first(first), current(first)
{
}

Payload *Iterator::firstItem()
{
	return first;
}

Payload *Iterator::nextItem()
{
	if (!isDone())
	{
		current = current->GetNext();
		return current;
	}

	return nullptr;
}

Payload *Iterator::currentItem()
{
	return current;
}

bool Iterator::isDone()
{
	return !(first && current);
}

bool Iterator::isLast()
{
	return !(current && current->GetNext());
}

void Iterator::reset()
{
	current = first;
}