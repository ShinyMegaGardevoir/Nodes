//
//  CTECHashTable.hpp
//  Nodes
//
//  Created by Sadlier, Christina on 5/5/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include "CTECArray.cpp"
#include "HashNode.cpp"
#include "CTECList.cpp"

    template <class Type>
    class CTECHashTable
    {
    public:
        CTECHashTable();
        ~CTECHashTable();
        
        void add(HashNode<Type> current);
        bool remove(HashNode<Type> current);
        bool contains(HashNode<Type> current);
        int getSize();
        void addToTable(HashNode<Type> current);
        
        
    private:
        int capacity;
        double efficiencyPercentage;
        int size;
        HashNode<Type> * internalStorage;
        CTECList<HashNode<Type>> * tableStorage;
        int tableCapacity;
        int tableSize;

        int findPosition(HashNode<Type> current);
        int handleCollision(HashNode<Type> current);
        void updateSize();
        
        int getNextPrime();
        bool isPrime(int candidateNumber);
        
        void updateTableCapacity();
        int findTablePosition(HashNode<Type>);
        
    };


#endif /* CTECHashTable_hpp */
