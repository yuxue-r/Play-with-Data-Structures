//
// Created by yyz on 2020/3/30.
//

#ifndef INC_04_LINKED_LIST_LINKLIST_H
#define INC_04_LINKED_LIST_LINKLIST_H

#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node *next;
public:
    Node(T data,Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->data = NULL;
        this->next = nullptr;
    }

};

#endif //INC_04_LINKED_LIST_LINKLIST_H
