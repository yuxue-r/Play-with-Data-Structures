//
// Created by yyz on 2020/3/28.
//

#ifndef INC_03_LOOPQUEUE_H
#define INC_03_LOOPQUEUE_H

#include "Queue.h"
#include "assert.h"

template <typename T>
class LoopQueue : public Queue<T>
{
private:
    T *data;
    int front,tail;
    int capacity;

    void resize(int capacity)
    {
        T *newdata;
        newdata = new T[capacity+1];
        int sz = getSize();
        for ( int i = 0; i < sz ; ++i )
        {
            newdata[i] = data[(i + front) % (this->capacity+1)];
        }
        data = newdata;
        front = 0;
        tail = sz;
        this->capacity=capacity;
        newdata = nullptr;
        delete []newdata;

    }

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
    int getCapacity()
    {
        return capacity;
    }
    int getSize()
    {
        return (tail - front + capacity + 1 ) % (capacity + 1);
    }
    bool isEmpty()
    {
        return front == tail;
    }
    void enqueue(T e)
    {
        if((tail + 1) % (capacity + 1) == front)
            resize( capacity * 2);
        data[tail] = e;
        tail = (tail + 1) % (capacity + 1);
    }

    T dequeue()
    {
        assert( front != tail );
        {
            T ret = data[front];
//            data[front] = NULL;
            front = (front + 1) % (capacity + 1);
            if (getSize() == capacity / 4 && capacity / 2 != 0)
            {
                resize(capacity / 2);
            }
            return ret;
        }
    }

    T getFront()
    {
        assert( front != tail );
        return data[front];
    }

    void print()
    {
        std::cout << "ArrayQueue: size = " << getSize() << ", capacity = " << getCapacity() << std::endl;
        std::cout << "front [";
        for ( int i = front; i != tail; i = (i + 1) % (capacity+1) )
        {
            if((i + 1) % (capacity + 1) != tail)
                std::cout<<data[i]<<"，";
            else
                std::cout<<data[i]<<"] tail"<<std::endl;
        }
    }
};

#endif //INC_03_LOOPQUEUE_H
