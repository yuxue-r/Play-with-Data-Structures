//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION2_H
#define INC_05_RECURSION_SOLUTION2_H
template<typename T>
class Solution2 {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val)
    {
        while(head != nullptr && head->val == val)
        {
            head = head->next;
        }

        if(head == nullptr)
        {
            return head;
        }

        ListNode<T> *prev = head;
        while(prev->next != nullptr)
        {
            if(prev->next->val == val)
            {
                prev->next = prev->next->next;
            } else
            {
                prev = prev->next;
            }
        }
        prev = nullptr;
        delete prev;
        return head;
    }
};
#endif //INC_05_RECURSION_SOLUTION2_H
