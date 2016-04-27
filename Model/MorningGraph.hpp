//
//  MorningGraph.hpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/25/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#ifndef MorningGraph_hpp
#define MorningGraph_hpp

#include <set>



    template <class Type>
    class MorningGraph
    {
    private:
        static const int MAXIMUM = 20;
        bool edges [MAXIMUM][MAXIMUM];
        Type labels [MAXIMUM];
        int manyVertices;
        void depthFirstTraversal(MorningGraph<Type> graph, int vertex, bool markedVertices[]);
        bool * markedVertices;
        int vertex;
        MorningGraph<Type> graph;
        
    public:
        MorningGraph();
        virtual ~MorningGraph();
        
        void addVertex(const Type& label);
        void addEdge(int source, int target);
        void removeEdge(int source, int taret);
        Type& operator [] (int vertex);
        int size() const;
        bool isEdge(int source, int target) const;
        std::set<int> neighbors(int vertex) const;
        Type operator [] (int vertex) const;
        void depthFirstTraversal(MorningGraph<Type> graph, int vertex);
        void breadthFirstTraversal(MorningGraph<Type> graph, int vertex);
        
        
    };


#endif /* MorningGraph_hpp */
