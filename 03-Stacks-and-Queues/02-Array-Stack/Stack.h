//
// Created by yyz on 2020/3/27.
//

#ifndef INC_03_STACKS_AND_QUEUES_STACK_H
#define INC_03_STACKS_AND_QUEUES_STACK_H

template<typename T>
class Stack {
public:
    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;

    virtual void push(T e) = 0;

    virtual T pop() = 0;

    virtual T peek() = 0;
};

#endif //INC_03_STACKS_AND_QUEUES_STACK_H
