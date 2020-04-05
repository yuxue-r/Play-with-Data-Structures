#include <iostream>
#include "BST.h"

using namespace std;

void demo1();
void demo2();

int main()
{
    demo2();
    return 0;
}
void demo2()
{
    BST<int> bst = BST<int>();
    int nums[] = {5, 3, 6, 8, 4, 2};
    for (int num : nums)
    {
        bst.add(num);
    }
    bst.preOrder();
    std::cout<<std::endl;
    bst.print();
    std::cout<<std::endl;
    bst.preOrderNR();
    std::cout<<std::endl;
//    bst.inOrder();
//    std::cout<<std::endl;
//    bst.postOrder();
//    std::cout<<std::endl;

}

void demo1()
{
    BST<int> bst = BST<int>();
    bst.add(1);
    bst.add(5);
    bst.add(10);
    bst.add(6);


    cout<<bst.contain(1)<<endl;
    cout<<bst.contain(5)<<endl;
    cout<<bst.contain(10)<<endl;


    cout<<bst.getSize()<<endl;
}