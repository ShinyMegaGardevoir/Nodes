//
//  CTECHashTable.hpp
//  Nodes
//
//  Created by Sadlier, Christina on 5/5/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#ifndef CTECHashTable_hpp
#define CTECHashTable_hpp

#include <stdio.h>


    template <class Type>
    class CTECHashTable
    {
    public:
        CTECHashTable();
        ~CTECHashTable();
        
        void add(const Type& value);
        bool remove(const Type& value);
        bool contains(const Type& value);
        
        
        
        
    private:
        int capacity;
        double efficiencyPercentage;
        int size;
        Type * internalStorageArray;

        int findPosition(const Type& value);
        int handleCollision(const Type& value);
        void updateSize();
    };


#endif /* CTECHashTable_hpp */
