//
//  CTECHashTable.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 5/5/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "CTECHashTable.hpp"
#include <cmath>

template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
    this->tableStorage = new CTECList<HashNode<Type>>[capacity];
}

template <class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
    delete [] internalStorage;
    delete [] tableStorage;
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
                //positionToInsert = (positionToInsert + 1) % capacity;
                positionToInsert = handleCollision(current);
            }
            
        }
        
        internalStorage[positionToInsert] = current;
    }
}

template <class Type>
bool CTECHashTable<Type> :: remove(HashNode<Type> current)
{
    bool wasRemoved = false;
    
    if(!contains(current))
    {
        int index = findPosition(current);
        while(internalStorage[index] != nullptr && !wasRemoved)
        {
            if(internalStorage[index].getValue() == current.getValue())
            {
                wasRemoved = true;
                internalStorage[index] = nullptr;
                size--;
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
    }
    
    return wasRemoved;
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
    bool isInTable = false;
    
    int index = findPosition(current);
    while(internalStorage[index] != nullptr && !isInTable)
    {
        if(internalStorage[index].getValue() == current.getValue())
        {
            isInTable = true;
        }
        else
        {
            index = (index + 1) % capacity;
        }
    }
    
    return isInTable;
}

template <class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> current)
{
    int reHashedPosition = findPosition(current);
    int random = rand();
    reHashedPosition = (random + (reHashedPosition * reHashedPosition)) % capacity;
    
    return reHashedPosition;
}

template <class Type>
void CTECHashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> * updatedStorage = new HashNode<Type>[updatedCapacity];
    
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
        
    }
    
    internalStorage = updatedStorage;
}

template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
int CTECHashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool CTECHashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber <= 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}

template <class Type>
void CTECHashTable<Type> :: addToTable(HashNode<Type> current)
{
    if(this->tableSize/this->tableCapacity >= this->efficiencyPercentage)
    {
        updateTableCapacity();
    }
    
    int positionToInsert = findPosition(current);
    
    //If the spot is empty, make a new list and add the node.
    if(tableStorage[positionToInsert] == nullptr)
    {
        CTECList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] = hashList;
        hashList.addEnd(current);
    }
    else //Just add the node.
    {
        tableStorage[positionToInsert].addEnd(current);
    }
}

template <class Type>
void CTECHashTable<Type> :: updateTableCapacity()
{
    int updatedCapacity = getNextPrime();
    CTECList<HashNode<Type>> * updateTable = new CTECList<HashNode<Type>>[updatedCapacity];
    int oldTableCapacity = tableCapacity;
    tableCapacity = updatedCapacity;
    
    for(int index = 0; index < oldTableCapacity; index++)
        {
        
            if(tableStorage[index] != nullptr)
            {
                CTECList<HashNode<Type>> temp = tableStorage[index];
                for(int innerIndex = 0; innerIndex < tableStorage[index].getSize(); innerIndex++)
                {
                    int updatedTablePosition = findPosition(temp.get(index));
                    if(updateTable[updatedTablePosition] == nullptr)
                    {
                        CTECList<HashNode<Type>> updatedList;
                        updatedList.addEnd(temp.get(index));
                    }
                    else
                    {
                        updateTable[updatedTablePosition].addEnd(temp.get(index));
                    }
                }
            }
        }
    
    tableStorage = updateTable;
}

template <class Type>
int CTECHashTable<Type> :: findTablePosition(HashNode<Type>)
{
    int tableCapacity = getNextPrime();
    HashNode<Type> * updatedStorage = new HashNode<Type>[tableCapacity];
    
    int oldCapacity = capacity;
    capacity = tableCapacity;
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
        
    }
    
    internalStorage = updatedStorage;

}
