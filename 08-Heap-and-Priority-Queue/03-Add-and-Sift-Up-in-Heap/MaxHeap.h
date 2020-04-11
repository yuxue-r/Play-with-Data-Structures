//
// Created by yyz on 2020/4/11.
//

#ifndef INC_08_HEAP_AND_PRIORITY_QUEUE_MAXHEAP_H
#define INC_08_HEAP_AND_PRIORITY_QUEUE_MAXHEAP_H

#include "Array.h"
#include "cassert"

template <typename T>
class MaxHeap
{
private:
    Array<T> array;
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
    int parent(int index)
    {
        assert(index != 0);
        return (index-1)>>1;
    }
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
    int leftChild(int index)
    {
        return (index<<1)+1;
    }
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
    int rightChild(int index)
    {
        return (index<<1)+2;
    }
    void shiftUp(int index)
    {
        while (index > 0 && array.get(parent(index)) < array.get(index))
        {
            array.swap(index , parent(index));
            index = parent(index);
        }
    }

public:
    MaxHeap()
    {
        array = Array<T>();
    }
    MaxHeap(int capacity)
    {
        array = Array<T>(capacity);
    }
    ~MaxHeap()
    {
    }
    // 返回堆中的元素个数
    int getSize()
    {
        return array.getSize();
    }
    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty()
    {
        return array.isEmpty();
    }
    // 向堆中添加元素
    void add(T data)
    {
        array.addLast(data);
        shiftUp(array.getSize() - 1);
    }
};

#endif //INC_08_HEAP_AND_PRIORITY_QUEUE_MAXHEAP_H
