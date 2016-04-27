//
//  MorningGraph.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/25/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "MorningGraph.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class Type>
const int MorningGraph<Type> :: MAXIMUM;

template <class Type>
void MorningGraph<Type> :: addEdge(int source, int target)
{
    assert(source < size());
    assert(target < size());
    edges[source][target] = true;
}

template <class Type>
void MorningGraph<Type> :: addVertex(const Type& vertexLabel)
{
    int newVertexNumber;
    int otherNumber;
    
    assert(size() < MAXIMUM);
    newVertexNumber = manyVertices;
    ++manyVertices;
    
    for(otherNumber = 0; otherNumber < manyVertices; otherNumber++)
    {
        edges[otherNumber][newVertexNumber] = false;
        edges[newVertexNumber][otherNumber] = false;
    }
    
    labels[newVertexNumber] = vertexLabel;
}

template <class Type>
bool MorningGraph<Type> :: isEdge(int source, int target) const
{
    bool connected = false;
    
    assert(source < size() && target < size());
    connected = edges[source][target];
    
    return connected;
}

template <class Type>
Type& MorningGraph<Type> :: operator[](int vertex)
{
    assert(vertex < size());
    return labels[vertex];
}

template <class Type>
Type MorningGraph<Type> :: operator[](int vertex) const
{
    assert(vertex < size());
    return labels[vertex];
}

template <class Type>
std::set<int> MorningGraph<Type> :: neighbors(int vertex) const
{
    std::set<int> answer;
    assert(vertex < size());
    
    for(int index = 0; index < size(); index++)
    {
        if(edges[vertex][index])
        {
            answer.insert(index);
        }
    }
    
    return answer;
}

template <class Type>
void MorningGraph<Type> :: removeEdge(int source, int target)
{
    assert(source < size() && target < size());
    edges[source][target] = false;
}

template <class Type>
void MorningGraph<Type> :: depthFirstTraversal(MorningGraph<Type> graph, int vertex, bool markedVertices[])
{
    std::set<int> connections = graph.neighbors(vertex);
    std::set<int>::iterator setIterator;
    
    markedVertices[vertex] = true;
    cout << graph[vertex] << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!markedVertices[*setIterator])
        {
            depthFirstTraversal(graph, *setIterator, markedVertices);
        }
    }
    
}

template <class Type>
void MorningGraph<Type> :: breadthFirstTraversal(MorningGraph<Type> graph, int vertex)
{
    bool markedVertices[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    assert(vertex < graph.size());
    
    std::fill_n(markedVertices, graph.size(), false);
    markedVertices[vertex] = true;
    cout << graph[vertex] << endl;
    vertexQueue.push(vertex);
    while(!vertexQueue.empty())
    {
        connections = graph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        
    }
}

template <class Type>
void MorningGraph<Type> :: depthFirstTraversal(MorningGraph<Type> graph, int vertex)
{
    bool markedVertices[MAXIMUM];
    assert(vertex < graph.size());
    std::fill_n(markedVertices, graph.size(), false);
    depthFirstTraversal(graph, vertex, markedVertices);
}
