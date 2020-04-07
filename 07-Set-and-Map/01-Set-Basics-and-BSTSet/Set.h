//
// Created by yyz on 2020/4/7.
//

#ifndef INC_07_SET_AND_MAP_SET_H
#define INC_07_SET_AND_MAP_SET_H
template <typename T>
class Set
{
    virtual void add(T e)=0;

    virtual void remove(T e)=0;

    virtual bool contains(T e)=0;

    virtual int getSize()=0;

    virtual bool isEmpty()=0;
};

#endif //INC_07_SET_AND_MAP_SET_H
