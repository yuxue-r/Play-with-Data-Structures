#include <iostream>
#include "ListNode.h"
#include "Solution.h"
#include "Solution2.h"
#include "Solution3.h"
#include "Solution4.h"
#include "Sum.h"

void demo1();
void demo2();
void demo3();

int main()
{
    demo3();
    return 0;

}

void demo1()
{
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> head = ListNode<int>(nums,6);
    head.print();
    ListNode<int> *res1 = Solution<int>().removeElements(&head,6);
    res1->print();
    ListNode<int> head2 = ListNode<int>(nums, 6);
    head2.print();
    ListNode<int> *res2 = Solution2<int>().removeElements(&head2, 6);
    res2->print();
    ListNode<int> *head3 = new ListNode<int>(nums, 6);
    head3->print();
    ListNode<int> *res3 = Solution3<int>().removeElements(head3, 6);
    res3->print();
}
void demo2()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    std::cout<<Sum<int>().sum(arr,9)<<std::endl;
}
void demo3()
{
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> head = ListNode<int>(nums,6);
    head.print();
    ListNode<int> *res1 = Solution4<int>().removeElements(&head,6);
    res1->print();
    res1 = nullptr;
}