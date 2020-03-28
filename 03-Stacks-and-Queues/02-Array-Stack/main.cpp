#include <iostream>

#include "ArrayStack.h"
using namespace std;

int main()
{
    ArrayStack<int> arrayStack =  ArrayStack<int>();
    for(int i = 0; i < 5; ++i)
    {
        arrayStack.push(i);
        arrayStack.print();
    }
    cout << arrayStack.pop() << endl;
    arrayStack.print();

//    如果用指针，避免野指针
//    arrayStack = nullptr;
//    delete arrayStack;
    return 0;
}
