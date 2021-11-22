#ifndef ITERATOR_H
#define ITERATOR_H

#include "../Spacecraft/Payload.h"

/**
 * @brief The Iterator class.
 * This class will allow the iteration of Payload objects in a linked list fashion.
 * This class functions as the iterator participant.
 * @author Ctrl Alt Defeat
 */
class Iterator
{
private:
	Payload* first;
	Payload* current;
public:
	/**
	 * @brief Construct a new Iterator object*
	 *
	 */
	Iterator();
	/**
	 * @brief Destroy the Iterator object.
	 *
	 */
	Iterator(Payload*);
	/**
	 * @brief Construct a new Iterator object.
	 *
	 * @param first The Payload object that will be the head of the linked list.
	 */
	~Iterator();
	/**
	 * @brief Returns the first Payload item.
	 *
	 * @return Payload*
	 */
	Payload* firstItem();
	/**
	 * @brief Sets the current pointer to the next item in the list and returns it.
	 *
	 * @return Payload*
	 */
	Payload* nextItem();
	/**
	 * @brief Returns the current item in the iteration.
	 *
	 * @return Payload*
	 */
	Payload* currentItem();
	/**
	 * @brief Returns whether the end of the list has been reached or not.
	 *
	 * @return true
	 * @return false
	 */
	bool isDone();
	/**
	 * @brief Returns whether the current item in the list is the last.
	 *
	 * @return true
	 * @return false
	 */
	bool isLast();
	/**
	 * @brief Resets the current pointer to the first item in the list.
	 *
	 */
	void reset();
};

#endif
