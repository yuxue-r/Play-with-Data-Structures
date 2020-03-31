//
// Created by yyz on 2020/3/31.
//

#ifndef INC_04_LINKED_LIST_LINKEDLISTSTACK_H
#define INC_04_LINKED_LIST_LINKEDLISTSTACK_H

#include "Stack.h"
#include "LinkList.h"

template <typename T>
class LinkedListStack : public Stack<T>
{
private:
    LinkList<T> stack;
public:
    LinkedListStack()
    {
        stack = LinkList<T>();
    }

    int getSize()
    {
        return stack.getSize();
    }

    bool isEmpty()
    {
        return stack.isEmpty();
    }

    void push(T e)
    {
        stack.addFirst(e);
    }

    T pop()
    {
        return stack.removeFirst();
    }

    T peek()
    {
        return stack.getFirst();
    }

    void print()
    {
        std::cout << "ArrayStack: size = " << stack.getSize()<<std::endl;
        std::cout << "top ";
        stack.print();
        std::cout << " bottom" << std::endl;
    }
};

#endif //INC_04_LINKED_LIST_LINKEDLISTSTACK_H
