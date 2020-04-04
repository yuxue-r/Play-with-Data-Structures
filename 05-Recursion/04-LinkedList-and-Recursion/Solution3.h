//
// Created by yyz on 2020/4/3.
//

#ifndef INC_05_RECURSION_SOLUTION3_H
#define INC_05_RECURSION_SOLUTION3_H
template <typename T>
class Solution3 {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val)
    {
        ListNode<T>* dummyHead = new ListNode<T>(-1);
        dummyHead->next = head;
        ListNode<T>* preNode = dummyHead;
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
