//
//  CTECHashTable.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 5/5/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "CTECHashTable.hpp"

template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
}

template <class Type>
void CTECHashTable<Type> :: add(HashNode<Type> current)
{
    if(!contains(current))
    {
        
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        
        int positionToInsert = findPosition(current);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
                
            }
            
            internalStorage[positionToInsert] = current;
        }
        else
        {
            internalStorage[positionToInsert] = current;
        }
    }
}

template <class Type>
bool CTECHashTable<Type> :: remove(HashNode<Type> current)
{
    
}


/*
 
 Very basice hashing Algorithm.
 Simply assigns a position based on modulo.
 
 */
template <class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> current)
{
    int position = 0;
    
    position = current.getKey() % capacity;
    
    return position;
}

template <class Type>
bool CTECHashTable<Type> :: contains(HashNode<Type> current)
{
    
}

template <class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> current)
{
    
}

template <class Type>
void CTECHashTable<Type> :: updateSize()
{
    
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}