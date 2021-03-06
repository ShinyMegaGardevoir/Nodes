//
//  CTECBinaryTree.cpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/13/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#include "CTECBinaryTree.hpp"

using namespace CTECData;
using namespace std;

template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
CTECBinaryTree<Type> :: ~CTECBinaryTree()
{

}


template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " " ;
        inorderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        cout << currentNode->getValue() << " " ;
        inorderTraversal(currentNode->getLeftChild());
        inorderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        inorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " ;
    }
}

template <class Type>
int CTECBinaryTree<Type> :: getSize()
{
    size = 0;
    calculateSize(root);
    return size;
}

template <class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        size++;
    }
    
    
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    /*
     Is the value in root? - return true else
     If the value is not in the root and is less than root - vall contains on left child
     Else if the value is not in the root and is greater than the root - call contains on right child
     
    */
    bool isInTree = false;
    if(root == nullptr)
    {
        isInTree = false;
    }
    else if(root->getValue() == value)
    {
        isInTree = true;
    }
    else if(value < root->getValue())
    {
        isInTree = contains(value, root->getLeftChild());
    }
    else
    {
        isInTree = contains(value, root->getRightChild());
    }
    
    return isInTree;
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, TreeNode<Type> * currentTree)
{
    /*
     Is the value in root? - return true else
     If the value is not in the root and is less than root - vall contains on left child
     Else if the value is not in the root and is greater than the root - call contains on right child
     
     */
    
    if(currentTree == nullptr)
    {
        return false;
    }
    
    if(currentTree->getValue() == value)
    {
        return true;
    }
    else if(value < currentTree->getValue())
    {
        return contains(value, currentTree->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRightChild());
    }
    
    
    
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRoot()
{
    return root;
}

template <class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    TreeNode<Type> * insertedNode = new TreeNode<Type>(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root  = insertedNode;
        }
        else
        {
            current = root;
            trailingCurrent = current;
            while (current != nullptr)
            {
                trailingCurrent = current;
                
                if (current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            if(trailingCurrent->getValue() > value)
            {
                trailingCurrent->setLeftChild(insertedNode);
                insertedNode->setParent(trailingCurrent);
            }
            else
            {
                trailingCurrent->setRightChild(insertedNode);
                insertedNode->setParent(trailingCurrent);
            }
            
        }
        return true;
    }

}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    while(leftNode->getLeftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}


template <class Type>
void CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> * trailing = current;
    
    if(!contains(value))
    {
        return;
    }
    else
    {
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
 
//       Find the node.
//        Check to see how many child nodes.
//       if 0
//           delete that node
//        else if only left
//           replace with left
//           delete old one
//        else if only right
//           replace with right
//           delete old one
//        else both
//           find LMC/RMC
//            Swap with
//            do - left only/right only
 
        if (current == root)
        {
            remove(root);
        }
        else if(trailing->getValue() > value) //Only left
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->getRightChild());
        }
    }
}

template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToBeDeleted)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToBeDeleted == nullptr)
    {
        cerr << "You can't remove an empty value." << endl;
    }
    else if(nodeToBeDeleted->getRightChild() == nullptr && nodeToBeDeleted->getLeftChild() == nullptr)
    {
        temp = nodeToBeDeleted;
        nodeToBeDeleted = nullptr;
        delete temp;
    }
    else if(nodeToBeDeleted->getRightChild() == nullptr)
    {
        temp = nodeToBeDeleted;
        nodeToBeDeleted = temp->getLeftChild();
        delete temp;
    }
    else if(nodeToBeDeleted->getLeftChild() == nullptr)
    {
        temp = nodeToBeDeleted;
        nodeToBeDeleted = temp->getRightChild();
        delete temp;
    }
    else
    {
        current = nodeToBeDeleted->getLeftChild();
        trailing = nullptr;
        while(current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToBeDeleted->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToBeDeleted->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }
}
