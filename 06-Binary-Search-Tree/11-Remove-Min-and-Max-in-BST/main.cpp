#include <iostream>
#include "BST.h"
#include "random"

using namespace std;

void demo1();
void demo2();
void demo3();

int main()
{
    demo3();
    return 0;
}
void demo3()
{
    srand ( (unsigned) time (NULL) );
    int n = 100;
    BST<int> bst = BST<int>();
    for ( int i = 0; i < n; ++i )
    {
        bst.add(rand() % 1000);
    }
    while(!bst.isEmpty())
        cout<<bst.removeMinimum()<<" ";
    for ( int i = 0; i < n; ++i )
    {
        bst.add(rand() % 1000);
    }
    cout<<endl;
    while(!bst.isEmpty())
        cout<<bst.removeMaximum()<<" ";
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
    bst.levelOrder();

    std::cout<<bst.minimum()<<std::endl;
    std::cout<<bst.maximum()<<std::endl;
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