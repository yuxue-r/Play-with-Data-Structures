//
// Created by yyz on 2020/3/28.
//

#ifndef INC_03_QUEUE_H
#define INC_03_QUEUE_H

template <typename T>
class Queue
{
    virtual void enqueue(T e)=0;

    virtual T getFront()=0;

    virtual T dequeue()=0;

    virtual int getSize()=0;

    virtual bool isEmpty()=0;
};

#endif //INC_03_QUEUE_H
