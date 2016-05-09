//
//  HashNode.hpp
//  Nodes
//
//  Created by Sadlier, Christina on 5/9/16.
//  Copyright © 2016 Sadlier, Christina. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <iostream> //For nullptr

template <class Type>
class HashNode
{
public:
    HashNode(int key, const Type& value);
    void setKey(int key);
    void setValue(const Type& value);
    int getKey();
    Type getValue();
    
    
private:
    int key;
    Type value;
    
    
};

#endif /* HashNode_hpp */
