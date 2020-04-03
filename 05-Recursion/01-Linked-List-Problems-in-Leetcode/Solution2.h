//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION2_H
#define INC_05_RECURSION_SOLUTION2_H

class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head != nullptr && head->val == val)
            head = head->next;
        if(head == nullptr)
            return nullptr;
        ListNode* preNode = head;
        while(preNode->next != nullptr)
        {
            if(preNode->next->val == val)
                preNode->next = preNode->next->next;
            else
                preNode = preNode->next;
        }
        preNode = nullptr;
        delete preNode;
        return head;
    }
};

#endif //INC_05_RECURSION_SOLUTION2_H
