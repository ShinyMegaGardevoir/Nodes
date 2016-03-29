/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: csad2045
 */

#include "ArrayNode.h"

template<class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()
{
	//Next is null
	this->next = nullptr;

}

template<class Type>
ArrayNode<Type>::~ArrayNode()
{
	// TODO Auto-generated destructor stub
}

template<class Type>
ArrayNode<Type>::ArrayNode(const Type& value) : Node<Type>(value)
{
	//The value equals the value and next equals null
	this->setValue(value);
	this->next = nullptr;
}

template<class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode<Type> * next) : Node<Type>(value)
{
	this->setValue(value);
	this->setNext(next);
}

template <class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext()
{
	//Returns the next value
	return this->next;
}

template <class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{
	//Sets the next value
	this->next = next;
}

