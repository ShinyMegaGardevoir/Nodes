//
//  TreeNode.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/13/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "TreeNode.hpp"
using namespace CTECData;

template <class Type>
TreeNode<Type> :: TreeNode() : Node<Type>()
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
}

template <class Type>
TreeNode<Type> :: TreeNode(const Type& value) : Node<Type>(value)
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
    
    this->setValue(value);
}

template <class Type>
TreeNode<Type> :: TreeNode(const Type& value, TreeNode<Type> * parent) : TreeNode<Type>(value)
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}