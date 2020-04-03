//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION4_H
#define INC_05_RECURSION_SOLUTION4_H

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;

        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* curr = dummyHead.next;
        ListNode* prev = &dummyHead;

        while(curr){
            if(curr->val == val){
                ListNode* tmp = curr;
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
