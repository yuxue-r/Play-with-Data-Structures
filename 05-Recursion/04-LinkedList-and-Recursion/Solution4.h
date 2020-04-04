//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION4_H
#define INC_05_RECURSION_SOLUTION4_H
#include "ListNode.h"
template <typename T>

class Solution4
{
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val)
    {
        if(head == nullptr)
            return head;
        head->next = removeElements(head->next,val);
        return head->val == val ? head->next : head;
    }
};
#endif //INC_05_RECURSION_SOLUTION4_H
