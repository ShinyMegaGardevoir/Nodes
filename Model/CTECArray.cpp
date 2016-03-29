/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: csad2045
 */

#include "CTECArray.h"
#include <iostream>
#include <assert.h>

using namespace std;

template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	head = nullptr;

	assert(size > 0);

	for (int index = 0; index < size; index++)
	{
		if (head != nullptr)
		{	//We have more than one ArrayNode
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			head = nextNode;

		}
		else
		{	//This is the first node in the array.
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;

		}
	}
}

template<class Type>
CTECArray<Type>::~CTECArray() //Deconstructs the ArrayNode.
{
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++)
	{
		if (deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}
		delete deleteMe->getNext();
		deleteMe = head;

	}
	delete head;
}

template<class Type>
int CTECArray<Type>::getSize() //Returns the size as an int.
{
	return this->size;
}

template<class Type>
Type CTECArray<Type>::get(int position)
{
	//Bounds check for size and negative.

	assert(position < size && position >= 0);

	ArrayNode<Type> * current = head;
	//Inclusive because I am inside the bounds.
	for (int i = 0; i <= position; i++)
	{
		if (i != position)
		{
			current = current->getNext();
		}
		else
		{
			return current->getValue();
		}

	}
    return current->getValue();

}

template<class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
	assert(position < size && position >= 0);

	ArrayNode<Type> * current = head;
	//Inclusive because I am inside the bounds.
	for (int i = 0; i <= position; i++)
	{
		if (i != position)
		{
			current = current->getNext();
		}
		else
		{
			current->setValue(value);
		}
	}

}

template<class Type>
void CTECArray<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    ArrayNode<Type> * first = get(indexOne);
    ArrayNode<Type> * second = get(indexTwo);
    ArrayNode<Type> * temp = new ArrayNode<Type>();
    
    temp->setValue(first->getValue());
    first->setValue(second->geValue());
    second->setValue(temp->getValue());
    
    delete temp;
}

template<class Type>
void CTECArray<Type> :: selectionSort()
{
    int innerLoop, outerLoop;
    
    for(outerLoop= 0; outerLoop < this->size-1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        for(innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(get(innerLoop) < get(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
            
        }
        
        if(selectedMinimum != outerLoop)
        {
            swap(outerLoop, selectedMinimum);
        }
    }
}


