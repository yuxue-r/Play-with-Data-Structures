//
// Created by yyz on 2020/4/8.
//

#ifndef INC_07_SET_AND_MAP_LINKEDLISTMAP_H
#define INC_07_SET_AND_MAP_LINKEDLISTMAP_H

#include "Map.h"
#include "cassert"

template <typename K,typename V>
class Node
{
public:
    K key;
    V value;
    Node *next;
    Node(K key,V value,Node *next)
    {
        this->key = key;
        this->value = value;
        this->next = next;
    }
    Node(K key)
    {
        this->key = key;
        this->next = nullptr;
    }
    Node()
    {
        this->next = nullptr;
    }
};

template <typename K,typename V>
class LinkedListMap : public Map<K,V>
{
private:
    Node<K,V> *dummyHead;
    int size;
    Node<K,V>* getNode(K key)
    {
        Node<K,V>* cur = dummyHead->next;
        while (cur!= nullptr)
        {
            if(cur->key == key)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
public:
    LinkedListMap()
    {
        dummyHead = new Node<K,V>();
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool contains(K key)
    {
        return (getNode(key)!= nullptr);
    }
    V get(K key)
    {
        assert(contains(key));
        Node<K,V>* newNode = getNode(key);
        return newNode->value;

    }
    void add(K key,V value)
    {
        Node<K,V>* node = getNode(key);
        if(node == nullptr)
        {
            dummyHead->next = new Node<K,V>(key,value,dummyHead->next);
            size++;
        } else
        {
            node->value = value;
        }

    }
    void set(K key,V value)
    {
        Node<K,V>* node = getNode(key);
        assert(node != nullptr);
        node->value = value;
    }
    V remove(K key)
    {
        Node<K,V>* preNode = dummyHead;
        while (preNode->next != nullptr)
        {
            if(preNode->next->key == key)
                break;
            preNode = preNode->next;
        }
        if (preNode->next != nullptr)
        {
            Node<K,V> *delNode = preNode->next;
            preNode->next = delNode->next;
            delNode->next = nullptr;
            size--;
            return delNode->value;
        } else
        {
            return preNode->value;
        }
    }

};

#endif //INC_07_SET_AND_MAP_LINKEDLISTMAP_H
