//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION_H
#define INC_05_RECURSION_SOLUTION_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            ListNode* delNode = head;
            head = head->next;
            delNode->next = nullptr;
        }
        if(head == nullptr)
            return nullptr;
        ListNode* preNode = head;
        while(preNode->next != nullptr)
        {
            if(preNode->next->val == val)
            {
                ListNode *delNode = preNode->next;
                preNode->next = delNode->next;
                delNode->next = nullptr;
            }
            else
            {
                preNode = preNode->next;
            }
        }
        preNode = nullptr;
        delete preNode;
        return head;
    }
};

#endif //INC_05_RECURSION_SOLUTION_H
