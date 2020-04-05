#include <iostream>
#include "BST.h"

using namespace std;

void demo1();

int main()
{
    demo1();
    return 0;
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