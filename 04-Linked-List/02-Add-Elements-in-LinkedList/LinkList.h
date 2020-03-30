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

template <typename T>
class LinkList
{
private:
    Node<T> *head;
    int size;

public:
    LinkList()
    {
        head = nullptr;
        size = 0;
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
    // 在链表头添加新的元素e
    void addFirst(T e)
    {
        Node<T>* node = new Node<T>(e);
        node->next = head;
        head = node;
        size++;
//        delete node;
//        node = nullptr;
    }
    // 在链表的index(0-based)位置添加新的元素e
    // 在链表中不是一个常用的操作，练习用：）
    void add(int index,T e)
    {
        assert(index >= 0 && index <= size);
        if(index == 0)
            addFirst(e);
        else
        {
            Node<T>* node = new Node<T>(e);
            Node<T>* prev = head;
            for ( int i = 0; i < index - 1; ++i )
            {
                prev = prev->next;
            }
            node->next = prev->next;
            prev->next = node;
            size++;
        }
    }
    void addLast(T e)
    {
        add(size,e);
    }

};

#endif //INC_04_LINKED_LIST_LINKLIST_H
