#include <iostream>
#include "ListNode.h"
#include "Solution.h"
#include "Solution2.h"
#include "Solution3.h"

int main() {
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> *head1 = new ListNode<int>(nums, 6);
    head1->print();
    ListNode<int> *res1 = Solution<int>().removeElements(head1,6);
    res1->print();
    ListNode<int> *head2 = new ListNode<int>(nums, 6);
    head2->print();
    ListNode<int> *res2 = Solution2<int>().removeElements(head2, 6);
    res2->print();
    ListNode<int> *head3 = new ListNode<int>(nums, 6);
    head3->print();
    ListNode<int> *res3 = Solution3<int>().removeElements(head3, 6);
    res3->print();
    head1 = head2 = head3 = nullptr;
    res1 = res2 = res3 = nullptr;

    return 0;
}