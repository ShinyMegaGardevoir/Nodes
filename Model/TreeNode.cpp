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
/**
template <class Type>
void insertIntoTree(TreeNode<Type>* &root, TreeNode<Type> *newNode, bool& isTaller)
{
    if (root == nullptr)
    {
        root = newNode;
        isTaller = true;
    }
    else if (root->info == newNode->info)
    {
        cerr << "No duplicates are allowed." << endl;
    }
    else if (root->info > newNode->info) //Goes to the left.
    {
        insertIntoTree(root->leftChild, newNode, isTaller);
        
        if (isTaller)
            
        {
            switch(root->bfactor)
            {
                case -1:
                {
                    balanceFromLeft(root);
                    isTaller = false;
                    break;
                }
                case 0:
                {
                    root->bfactor = -1;
                    isTaller = true;
                    break;
                }
                case 1:
                {
                    root->bfactor = 0;
                    isTaller = false;
                }
      
            }
        }
    }
    
    else
    {
        insertIntoTree(root->rightChild, newNode, isTaller);
        
        
        if (isTaller)
        {
            switch(root->bfactor)
            {
                case -1:
                {
                    root->bfactor = 0;
                    isTaller = false;
                    break;
                }
                case 0:
                {
                    root->bfactor = 1;
                    isTaller = true;
                    break;
                }
                case 1:
                {
                    balanceFromRight(root);
                    isTaller = false;
                }
 
            }
        }

    }
}
**/
