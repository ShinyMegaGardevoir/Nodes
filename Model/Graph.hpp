//
//  Graph.hpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/25/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

namespace CTECData
{
    template <class Type>
    class Graph
    {
    private:
        
        
    public:
        Graph();
        virtual ~Graph();
        
        void addVertex(const Type& label);
        void addEdge(int source, int target);
        void removeEdge(int source, int taret);
        Type& operator [] (int vertex);
        
    };
}

#endif /* Graph_hpp */
