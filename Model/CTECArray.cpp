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
    Type temp = get(indexOne);
    set(indexOne, get(indexTwo));
    set(indexTwo, temp);
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



template<class Type>
int CTECArray<Type> :: seqSearch(int item [], const Type& value)
{
    int loc;
    bool found = false;
    
    for(loc = 0; loc < size; loc++)
    {
        if (item[loc] == value)
        {
            found = true;
            break;
        }
    }
    
    if (found)
    {
        return loc;
    }
    else
    {
        return -1;
    }
    
}

template <class Type>
int CTECArray<Type> :: indexOf(Type searchValue)
{
    assert(this->size > 0);
    
    int index = 0;
    
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    index = -1;
    return index;
}
