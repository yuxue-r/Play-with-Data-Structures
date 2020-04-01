//
// Created by yyz on 2020/3/31.
//

#ifndef INC_04_LINKED_LIST_LINKEDLISTQUEUE_H
#define INC_04_LINKED_LIST_LINKEDLISTQUEUE_H

#include "Queue.h"
#include "LinkList.h"
#include "cassert"

template <typename T>
class LinkedListQueue : public Queue<T>
{
private:
    Node<T>* dummyHead;
    Node<T>* tail;
    int size;
public:
    LinkedListQueue()
    {
        dummyHead = new Node<T>();
        tail = nullptr;
        size = 0;
    }
    ~LinkedListQueue()
    {
        dummyHead = tail = nullptr;
        delete dummyHead;
        delete tail;
    }
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T e)
    {
        Node<T>* insNode = new Node<T>(e);
        if(tail == nullptr)
        {
            tail = insNode;
            dummyHead->next = tail;
        }
        else
        {
            insNode->next = tail->next;
            tail->next = insNode;
            tail = insNode;
        }
        size++;
    }
    T dequeue()
    {
        assert(isEmpty() == false);
        Node<T>* delNode = dummyHead->next;
        dummyHead->next = delNode->next;
        delNode->next = nullptr;
        if(dummyHead->next == nullptr)
            tail = nullptr;
        size--;
        return delNode->data;
    }
    T getFront()
    {
        assert(isEmpty()!=0);
        return dummyHead->next->data;
    }
    void print()
    {
        Node<T> *prev = dummyHead;
        std::cout << "front [";
        for (int i = 0; i < size; ++i)
        {
            prev = prev->next;
            std::cout << prev->data;
            if (i < size - 1)
            {
                std::cout << "->";
            }
        }
        std::cout << "->NULL] tail"<<std::endl;
    }

};

#endif //INC_04_LINKED_LIST_LINKEDLISTQUEUE_H
