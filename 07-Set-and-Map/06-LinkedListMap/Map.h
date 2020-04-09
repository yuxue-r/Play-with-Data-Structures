//
// Created by yyz on 2020/4/8.
//

#ifndef INC_07_SET_AND_MAP_MAP_H
#define INC_07_SET_AND_MAP_MAP_H

template <typename K,typename V>
class Map
{
    virtual void add(K key,V value) = 0;
    virtual V remove(K key) = 0;
    virtual bool contains(K key) = 0;
    virtual V get(K key) = 0;
    virtual void set(K key,V value) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};

#endif //INC_07_SET_AND_MAP_MAP_H
