#include "Iterator.h"

Iterator::Iterator()
	: first(nullptr), current(nullptr)
{}

Iterator::~Iterator()
{}

Iterator::Iterator(StarlinkSatellite *first)
	: first(first), current(first)
{}

StarlinkSatellite *Iterator::firstItem() {
	return first;
}

StarlinkSatellite *Iterator::nextItem()
{
	if (!isDone()) {
		current = current->getNext();
		return current;
	}

	return nullptr;
}

StarlinkSatellite *Iterator::currentItem() {
	return current;
}

bool Iterator::isDone()
{
	return !(first && current->getNext());
}
