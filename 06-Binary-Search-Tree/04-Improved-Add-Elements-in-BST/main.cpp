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

    cout<<bst.getSize()<<endl;
}