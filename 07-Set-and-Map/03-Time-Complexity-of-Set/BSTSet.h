//
// Created by yyz on 2020/4/7.
//

#ifndef INC_07_SET_AND_MAP_BSTSET_H
#define INC_07_SET_AND_MAP_BSTSET_H

#include "Set.h"
#include "BST.h"

template <typename T>
class BSTSet : public Set<T>
{
private:
    BST<T> bst;
public:
    BSTSet()
    {
        bst = BST<T>();
    }
    int getSize()
    {
        return bst.getSize();
    }
    bool isEmpty()
    {
        return bst.isEmpty();
    }
    void add(T e)
    {
        bst.add(e);
    }
    void remove(T e)
    {
        bst.remove(e);
    }
    bool contains(T e)
    {
        return  bst.contain(e);
    }
};

#endif //INC_07_SET_AND_MAP_BSTSET_H
