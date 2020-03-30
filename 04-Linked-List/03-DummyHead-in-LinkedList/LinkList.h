//
// Created by yyz on 2020/3/30.
//

#ifndef INC_04_LINKED_LIST_LINKLIST_H
#define INC_04_LINKED_LIST_LINKLIST_H

#include <iostream>
#include "cassert"

template <typename T>
class Node
{
public:
    T data;
    Node *next;
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
        this->next = nullptr;
    }

};

template <typename T>
class LinkList
{
private:
    Node<T> *dummyHead;
    int size;

public:
    LinkList()
    {
        dummyHead = new Node<T>();
        size = 0;
    }
    ~LinkList()
    {
        delete dummyHead;
        dummyHead = nullptr;
    }
    // 获取链表中的元素个数
    int getSize()
    {
        return size;
    }
    // 返回链表是否为空
    bool inEmpty()
    {
        return size == 0;
    }

    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用：）
    void add(int index,T e)
    {
        assert(index >= 0 && index <= size);
            Node<T>* prev = dummyHead;
            for ( int i = 0; i < index; ++i )
            {
                prev = prev->next;
            }
            prev->next = new Node<T>(e,prev->next);
            size++;

    }
    // 在链表头添加新的元素e
    void addFirst(T e)
    {
        add(0,e);
    }
    void addLast(T e)
    {
        add(size,e);
    }
    
    void print()
    {
        Node<T> *prev = dummyHead;
        std::cout << "LinkedList: size = " << size << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i)
        {
            prev = prev->next;
            std::cout << prev->data;
            if (i < size - 1)
            {
                std::cout << "->";
            }
        }
        std::cout << "]" << std::endl;
    }

};

#endif //INC_04_LINKED_LIST_LINKLIST_H
