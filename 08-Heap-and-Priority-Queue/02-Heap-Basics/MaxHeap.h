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

public:
    MaxHeap()
    {
        array = Array<T>();
    }
    MaxHeap(int capacity)
    {
        array = Array<T>(capacity);
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
};

#endif //INC_08_HEAP_AND_PRIORITY_QUEUE_MAXHEAP_H
