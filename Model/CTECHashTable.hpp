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
        
        
        
    private:
        int capacity;
        double efficiencyPercentage;
        int size;
        HashNode<Type> * internalStorage;

        int findPosition(HashNode<Type> current);
        int handleCollision(HashNode<Type> current);
        void updateSize();
        
        int getNextPrime();
        bool isPrime(int candidateNumber);
    };


#endif /* CTECHashTable_hpp */
