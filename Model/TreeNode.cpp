//
//  TreeNode.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/13/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "TreeNode.hpp"
using namespace CTECData;
using namespace std;

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

template <class Type>
TreeNode<Type> * TreeNode<Type> :: getLeftChild()
{
    return this->leftChild;
}

template <class Type>
TreeNode<Type> * TreeNode<Type> :: getRightChild()
{
    return this->rightChild;
}

template <class Type>
void TreeNode<Type> :: setRightChild(TreeNode<Type> * rightChild)
{
    this->rightChild = rightChild;
}

template <class Type>
void TreeNode<Type> :: setLeftChild(TreeNode<Type> * leftChild)
{
    this->leftChild = leftChild;
}

template <class Type>
TreeNode<Type> * TreeNode<Type> :: getParent()
{
    return this->parent;
}

template <class Type>
void TreeNode<Type> :: setParent(TreeNode<Type> * parent)
{
    this->parent = parent;
}
