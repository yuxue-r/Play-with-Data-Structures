//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_LISTNODE_H
#define INC_05_RECURSION_LISTNODE_H

#include <iostream>
#include <cassert>

template<typename T>
class ListNode{
public:
    T val;
    ListNode *next;

    ListNode(T x)
    {
        val = x;
    }

    ListNode(T arr[], int n)
    {
        assert(arr != nullptr && n!= 0);
        val = arr[0];
        ListNode<T> *cur = this;
        for (int i = 1; i < n; i++)
        {
            cur->next = new ListNode<T>(arr[i]);
            cur = cur->next;
        }
        cur = nullptr;
        delete cur;
    }

    void print()
    {
        ListNode<T> *cur = this;
        while(cur != nullptr)
        {
            std::cout << cur->val << "->";
            cur = cur->next;
        }
        std::cout << "NULL" <<std::endl;
        cur = nullptr;
    }
};

#endif //INC_05_RECURSION_LISTNODE_H
