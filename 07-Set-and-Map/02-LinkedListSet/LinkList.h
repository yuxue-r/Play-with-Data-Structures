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
        dummyHead = nullptr;
        delete dummyHead;
    }
    // 获取链表中的元素个数
    int getSize()
    {
        return size;
    }
    // 返回链表是否为空
    bool isEmpty()
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
    // 获得链表的第index(0-based)个位置的元素
    // 在链表中不是一个常用的操作，练习用：）
    T get(int index)
    {
        assert(index >= 0 && index < size);
        Node<T>*node = dummyHead;
        for ( int i = 0; i <= index; ++i )
        {
            node = node->next;
        }
        return node->data;
    }
    // 获得链表的第一个元素
    T getFirst()
    {
        return get(0);
    }

    // 获得链表的最后一个元素
    T getLast()
    {
        return get(size - 1);
    }
    // 修改链表的第index(0-based)个位置的元素为e
    // 在链表中不是一个常用的操作，练习用：）
    void set(int index,T e)
    {
        assert(index >= 0 && index < size);
        Node<T>*node = dummyHead;
        for ( int i = 0; i <= index; ++i )
        {
            node = node->next;
        }
        node->data = e;
    }
    // 查找链表中是否有元素e
    bool contains(T e)
    {
        Node<T>*node = dummyHead->next;
        while (node != nullptr)
        {
            if(node->data == e)
                return true;
            node = node->next;
        }
        return false;
    }
    // 从链表中删除index(0-based)位置的元素, 返回删除的元素
    // 在链表中不是一个常用的操作，练习用：）
    T remove(int index)
    {
        assert(index>=0 && index < size);
        Node<T>*node = dummyHead;
        for ( int i = 0; i < index; ++i )
        {
            node = node->next;
        }
        Node<T>*delNode = node->next;
        node->next = delNode->next;
        delNode->next= nullptr;
        size--;
        return  delNode->data;
    }
    // 从链表中删除第一个元素, 返回删除的元素
    T removeFirst()
    {
        return remove(0);
    }
    // 从链表中删除最后一个元素, 返回删除的元素
    T removeLast()
    {
        return remove(size-1);
    }
    void removeElements(T e)
    {
        Node<T>*node = dummyHead;
        while(node->next != nullptr)
        {
            if(node->next->data == e)
                break;
            node = node->next;
        }
        if(node->next != nullptr)
        {
            Node<T>*delNode = node->next;
            node->next = delNode->next;
            delNode->next = nullptr;
            size --;
        }
        node = nullptr;
    }
    void print()
    {
        Node<T> *prev = dummyHead;
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
        std::cout << "]";
    }

};

#endif //INC_04_LINKED_LIST_LINKLIST_H
