//
//  HashNode.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 5/9/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "HashNode.hpp"

template <class Type>
HashNode<Type> :: HashNode()
{
    
}

template <class Type>
HashNode<Type> :: ~HashNode()
{
    
}

template <class Type>
HashNode<Type> :: HashNode(int key, const Type& value)
{
    this->key = key;
    this->value = value;
}

template <class Type>
void HashNode<Type> :: setKey(int key)
{
    this->key = key;
}

template <class Type>
int HashNode<Type> :: getKey()
{
    return this->key;
}

template <class Type>
Type HashNode<Type> :: getValue()
{
    return this->value;
}

template <class Type>
void HashNode<Type> :: setValue(const Type& value)
{
    this->value = value;
}