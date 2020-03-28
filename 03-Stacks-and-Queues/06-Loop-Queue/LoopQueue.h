//
// Created by yyz on 2020/3/28.
//

#ifndef INC_03_LOOPQUEUE_H
#define INC_03_LOOPQUEUE_H

#include "Queue.h"

template <typename T>
class LoopQueue : public Queue<T>
{
private:
    T *data;
    int front,tail;
    int capacity;

public:
    LoopQueue(int capacity)
    {
        data = new T[capacity+1];
        front = tail = 0;
        this->capacity = capacity;
    }
    LoopQueue()
    {
        data = new T[10];
        front = tail = 0;
        this->capacity = 10;
    }
    ~LoopQueue()
    {
        delete []data;
        data = nullptr;
    }
    int getSize()
    {
        return (tail - front + capacity + 1 ) % (capacity + 1);
    }
    bool isEmpty()
    {
        return front == tail;
    }
    // 下一小节再做具体实现
    void enqueue(T e)
    {

    }
    // 下一小节再做具体实现
    T dequeue()
    {
        return NULL;
    }
    // 下一小节再做具体实现
    T getFront()
    {
        return NULL;
    }


};

#endif //INC_03_LOOPQUEUE_H
