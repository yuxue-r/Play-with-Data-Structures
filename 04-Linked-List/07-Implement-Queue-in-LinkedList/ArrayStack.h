//
// Created by yyz on 2020/3/27.
//

#ifndef INC_03_STACKS_AND_QUEUES_ARRAYSTACK_H
#define INC_03_STACKS_AND_QUEUES_ARRAYSTACK_H

#include "Stack.h"
#include "Array.h"

template <typename T>
class ArrayStack : public Stack<T>
{
private:
    Array<T> array;
public:
    ArrayStack(int capacity)
    {
        array = Array<T>(capacity);
    }
    ArrayStack()
    {
        array = Array<T>();
    }
    ~ArrayStack()
    {
//        delete []array;
    }
    void push(T e)
    {
        array.addLast(e);
    }
    T pop()
    {
        return array.removeLast();
    }
    T peek()
    {
        return array.getLast();
    }
    int getSize()
    {
        return array.getSize();
    }
    bool isEmpty()
    {
        return array.isEmpty();
    }
    void print() {
        std::cout << "ArrayStack: size = " << array.getSize() << ", capacity = " << array.getCapacity() << std::endl;
        std::cout << "bottom ";
        array.print();
        std::cout << " top" << std::endl;
    }

};

#endif //INC_03_STACKS_AND_QUEUES_ARRAYSTACK_H
