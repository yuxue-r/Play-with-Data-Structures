//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION4_H
#define INC_05_RECURSION_SOLUTION4_H
#include "ListNode.h"
template <typename T>

class Solution4{
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val) {
        if(head == nullptr)
            return head;

        ListNode<T> dummyHead(0);
        dummyHead.next = head;
        ListNode<T>* curr = dummyHead.next;
        ListNode<T>* prev = &dummyHead;

        while(curr){
            if(curr->val == val){
                ListNode<T>* tmp = curr;
                curr = curr->next;
                prev->next = curr;
                delete tmp;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummyHead.next;

    }
};
#endif //INC_05_RECURSION_SOLUTION4_H
