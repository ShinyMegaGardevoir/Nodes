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
    this->internalStorage = new Type[capacity];
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
}

template <class Type>
void CTECHashTable<Type> :: add(const Type& value)
{
    if(!contains(value))
    {
        
        if(size/capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        
        int positionToInsert = findPosition(value);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % size;
                
            }
            
            internalStorage[positionToInsert] = value;
        }
        else
        {
            internalStorage[positionToInsert] = value;
        }
    }
}

template <class Type>
bool CTECHashTable<Type> :: remove(const Type& value)
{
    
}

template <class Type>
int CTECHashTable<Type> :: findPosition(const Type& value)
{
    
}

template <class Type>
bool CTECHashTable<Type> :: contains(const Type &value)
{
    
}

template <class Type>
int CTECHashTable<Type> :: handleCollision(const Type &value)
{
    
}

template <class Type>
void CTECHashTable<Type> :: updateSize()
{
    
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size();
}