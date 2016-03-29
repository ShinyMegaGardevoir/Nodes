/*
 * Node.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: csad2045
 */

#include "Node.h"

//using namespace std;
template <class Type>
Node<Type>::Node() {
	pointers = nullptr;

}

template <class Type>
Node<Type>::Node(const Type& value)
{
	this->value = value;
	pointers = nullptr;
}


template <class Type>
Node<Type>::~Node()      //Node destructor, do not use.
{
	// TODO Auto-generated destructor stub
}

template <class Type>
Type Node<Type> :: getValue()
{
	return this->value;
}

template <class Type>
void Node<Type> :: setValue(const Type& value)
{
	this->value = value;
}

template <class Type>
Node<Type> * Node<Type> :: getPointers()
{
	return this->pointers; //Returns the pointers.
}

