//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION3_H
#define INC_05_RECURSION_SOLUTION3_H
class Solution3 {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* preNode = dummyHead;
        while(preNode->next != nullptr)
        {
            if(preNode->next->val == val)
                preNode->next = preNode->next->next;
            else
                preNode = preNode->next;
        }
        preNode = nullptr;
        delete preNode;
        return dummyHead->next;
    }
};

#endif //INC_05_RECURSION_SOLUTION3_H
