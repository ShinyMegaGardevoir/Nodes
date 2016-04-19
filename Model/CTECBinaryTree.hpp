//
//  CTECBinaryTree.hpp
//  Nodes
//
//  Created by Sadlier, Christina on 4/13/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include "TreeNode.cpp"
namespace CTECData
{
    template <class Type>
    class CTECBinaryTree
    {
    private:
        TreeNode<Type> * root;
        int height;
        bool balanced;
        bool contains(Type value, CTECBinaryTree<Type> * currentTree);
        void calculateSize(TreeNode<Type> * currentNode);
        int size;
        void insert(const Type& value, CTECBinaryTree<Type> * currentTree);
        TreeNode<Type> * getRightMostChild(CTECBinaryTree * leftSubTree);
        TreeNode<Type> * getLeftMostChild(CTECBinaryTree * rightSubTree);
        
    public:
        CTECBinaryTree();
        ~CTECBinaryTree();
        bool insert(const Type& value);
        bool contains(Type value);
        Type remove(const Type& value);
        int getHeight();
        bool isBalanced();
        TreeNode<Type> * getRoot();
        void inorderTraversal(TreeNode<Type> * currentNode);
        void postorderTraversal(TreeNode<Type> * currentNode);
        void preorderTraversal(TreeNode<Type> * currentNode);
        int getSize();
    };
}

#endif /* CTECBinaryTree_hpp */
