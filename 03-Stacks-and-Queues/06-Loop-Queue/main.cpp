#include <iostream>

#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
using namespace std;

void demo1();
void demo2();

int main()
{
    demo2();

    return 0;
}

void demo1()
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
}

void demo2()
{
    ArrayQueue<int> arrayQueue = ArrayQueue<int>();
    for ( int i = 0; i < 10; ++i )
    {
        arrayQueue.enqueue(i);
        arrayQueue.print();
        if(i%3==2)
        {
            arrayQueue.dequeue();
            arrayQueue.print();
        }
    }
}