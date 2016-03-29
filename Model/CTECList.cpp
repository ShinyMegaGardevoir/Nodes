/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: csad2045
 */

#include "CTECList.h"
#include <assert.h>

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}

/**
 * 1: Start at head
 * 2:
 * 3:
 * 4:
 * 5:
 **/
template <class Type>
CTECList<Type>::~CTECList()
{
	ArrayNode<Type> * current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

template <class Type>
int CTECList<Type>::getSize() //
{
	return this->size;
}

template <class Type>
Type CTECList<Type>::getFront() //
{
	assert(size >= 0);

	return head->getValue();

}

template <class Type>
Type CTECList<Type>::getEnd() //
{
	assert(size >= 0);
	ArrayNode<Type> * current = head;
	for(int i = 0; i < size; i++)
	{
		
		if(i == size-1)
		{
			return current->getValue();
		}
        current = current->getNext();
	}
    
    return current->getValue();

}

template <class Type>
Type CTECList<Type>::getFromIndex(int index) //
{
	//Bounds check for size and negative.

	assert(index < size && index >= 0);

	ArrayNode<Type> * current = head;
	//Inclusive because I am inside the bounds.
	for (int i = 0; i <= index; i++)
	{
		if (i != index)
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

template <class Type>
Type CTECList<Type>::removeFromFront() //
{
	assert(this->size > 0);

	Type thingToRemove;
	//create a pointer that is after head
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	//Delete what head is pointing to
	delete this->head;
	//Set head to new head
	this->head = newHead;

	this->calculateSize();
	return thingToRemove;


}

template <class Type>
void CTECList<Type>::calculateSize() //
{
	assert(size >= 0);


	ArrayNode<Type> * counterPointer = head;
	int count = 0;
	if(counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;

		}

		this->size = count;
	}


}


template <class Type>
Type CTECList<Type>::removeFromEnd() //
{
	assert(size > 0);
	Type valueToRemove;
	if(size == 1)
	{
		valueToRemove = removeFromFront();
		end = nullptr;
	}
	else
	{
	ArrayNode<Type> * current = head;
	//Loop over Size
	for(int index = 0; index < size-1; index ++)
	{
		current = current->getNext();
	}

/**	Does the same thing as looping over size, just another way of doing it.
	ArrayNode<Type> * pointer = head;
	while(pointer->getNext()->getNext() != nullptr)
	{
		pointer = pointer->getNext();
	}
**/

	valueToRemove = current->getNext()->getValue();
	end = current;
	delete current->getNext();
	}

	this->calculateSize();
	return valueToRemove;
}

template <class Type>
Type CTECList<Type>::removeFromIndex(int index) //
{
	assert(this->size > 0);
	assert(index >= 0 && index < size);

			Type thingToRemove;
			ArrayNode<Type> * previous, deleteMe, newNext;
			if(index == 0)
			{
				thingToRemove = removeFromFront();
			}
			else if(index == size - 1)
			{
				thingToRemove = removeFromEnd();
			}
			else
			{
				ArrayNode<Type> * newHead = new ArrayNode<Type>();
				newHead = head;
				for(int spot = 0; spot < index+1; spot++)
				{

					if(spot == index)
					{
						//Delete what head is pointing to
						delete this->head;
						//Set head to new head
						this->head = newHead;

					}
					else
					{
						head = head->getNext();
					}
				}
				this->calculateSize();
			}

			return thingToRemove;
}

template <class Type>
Type CTECList<Type>::set(int index, const Type& value) //
{
	assert(index < size && index >= 0);

		ArrayNode<Type> * current = head;
		//Inclusive because I am inside the bounds.
		for (int i = 0; i <= index; i++)
		{
			if (i != index)
			{
				current = current->getNext();
			}
			else
			{
				return current->setValue(value);
			}
		}


}

template <class Type>
void CTECList<Type>::addToFront(const Type& value) //
{

	ArrayNode<Type> * newNode; //pointer to the new node
	newNode = new ArrayNode<Type>; //creates the new node
	newNode->setValue(value); //sets the new node value to the value
	if(head == nullptr)
	{
		head = newNode;
		newNode->setNext(nullptr);
		end = newNode;
	}
	else
	{
		newNode->setNext(head); //links the new node to the first one
		head = newNode; //moves the head to the new node
	}

	this->calculateSize();

}

template <class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	ArrayNode<Type> * newNode; //creates a pointer to the new node
	newNode = new ArrayNode<Type>(value); //creates the new node



	if(head == nullptr) //runs if the head is null (meaning the size is 0)
	{
		head = newNode;
		end = newNode;
		newNode->setNext(nullptr);

	}
	else
	{
		end->setNext(newNode); //links the last node to the new node
		end = newNode; //makes new node the new end
	}

	this->calculateSize();
}

template <class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	assert(index >= 0); //make sure the index is less than the size and the index is greater than or equal to 0.
	ArrayNode<Type> * newNode; //Creates Pointer newNode
	ArrayNode<Type> * previous; //Creates Pointer previous
	ArrayNode<Type> * current; //Creates Pointer
	newNode = new ArrayNode<Type>; //Makes newNode a new ArrayNode (of Type).
    previous = head;


	newNode->setValue(value); //Sets the newNode value to value.
	newNode->setNext(nullptr); //Sets the newNode link to null.

	if(head == nullptr) //If there is nothing in the List, makes it the item in the list.
	{
		head = newNode;
		end = newNode;
		newNode->setNext(nullptr);
	}
	else
	{
		current = head; //Current is equal to head





		for(int spot = 0; spot < index; spot++)
		{
			if(spot == index) //If current is equal to the index
			{
				previous->setNext(newNode); //Previous links to the new Node
				newNode->setNext(current); //New Node links to current
			}
			else //If current is not equal to the index
			{
				previous = current; //previous equals current
				current = current->getNext(); //current equals the next item
			}
		}

		if (current == head) //If next is null and current equals the head
		{
			newNode->setNext(head); //New node links to whatever the head is
			head = newNode; //The head is now the new Node
		}
		else //If next is null and current is not the head
		{
			previous->setNext(newNode);
			newNode->setNext(current);

			if(current == nullptr)
			{
				end = newNode;
			}
		}
	}

	this->calculateSize();



}

template<class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    ArrayNode<Type> * first = getFromIndex(indexOne);
    ArrayNode<Type> * second = getFromIndex(indexTwo);
    ArrayNode<Type> * temp = new ArrayNode<Type>();
    
    temp->setValue(first->getValue());
    first->setValue(second->geValue());
    second->setValue(temp->getValue());
    
    delete temp;
}

template<class Type>
void CTECList<Type> :: selectionSort()
{
    int innerLoop, outerLoop;
    
    for(outerLoop= 0; outerLoop < this->size-1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        for(innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
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

