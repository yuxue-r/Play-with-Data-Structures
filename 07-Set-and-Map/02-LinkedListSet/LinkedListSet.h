//
// Created by yyz on 2020/4/7.
//

#ifndef INC_07_SET_AND_MAP_LINKEDLISTSET_H
#define INC_07_SET_AND_MAP_LINKEDLISTSET_H

#include "LinkList.h"
#include "Set.h"

template <typename T>
class LinkedListSet : public Set<T>
{
private:
    LinkList<T> linkList = LinkList<T>();
public:
    int getSize()
    {
        return linkList.getSize();
    }
    bool isEmpty()
    {
        return linkList.isEmpty();
    }
    bool contains(T e)
    {
        return linkList.contains(e);
    }
    void add(T e)
    {
        if(!linkList.contains(e))
            linkList.addFirst(e);
    }
    void remove(T e)
    {
        linkList.removeElements(e);
    }
};

#endif //INC_07_SET_AND_MAP_LINKEDLISTSET_H
