//
// Created by yyz on 2020/3/28.
//

#ifndef INC_03_ARRAYQUEUE_H
#define INC_03_ARRAYQUEUE_H

#include "Array.h"
#include "Queue.h"

template <typename T>
class ArrayQueue : public Queue<T>
{
private:
    Array<T> array;
public:
    ArrayQueue(int capacity)
    {
        array = Array<T>(capacity);
    }
    ArrayQueue()
    {
        array = Array<T>();
    }
    ~ArrayQueue()
    {

    }
    void enqueue(T e)
    {
        array.addLast(e);
    }
    T dequeue()
    {
        return array.removeFirst();
    }
    T getFront()
    {
        return array.getFirst();
    }
    int getSize()
    {
        return array.getSize();
    }
    bool isEmpty()
    {
        return array.getSize()==0;
    }

    void print()
    {
        std::cout << "ArrayQueue: size = " << array.getSize() << ", capacity = " << array.getCapacity() << std::endl;
        std::cout << "front ";
        array.print();
        std::cout << " tail" << std::endl;
    }
};

#endif //INC_03_ARRAYQUEUE_H
