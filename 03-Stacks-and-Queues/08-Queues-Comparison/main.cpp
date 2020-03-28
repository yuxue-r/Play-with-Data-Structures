#include <iostream>

#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
using namespace std;

void demo1();
void demo2();
void demo3();
void demo4();


int main()
{
    demo4();

    return 0;
}

template<typename T>
double testQueue(T queue, int opCount)
{
    clock_t startTime = clock();
    srand(100);
    for (int i = 0; i < opCount; ++i)
    {
        queue.enqueue(rand());
    }
    for (int j = 0; j < opCount; ++j)
    {
        queue.dequeue();
    }
    clock_t endTime = clock();
    return double (endTime - startTime) / CLOCKS_PER_SEC;
}

void demo4()
{
    int opCount=100000;
    ArrayQueue<int> arrayQueue =  ArrayQueue<int>();
    std::cout << "ArrayQueue time: " << testQueue(arrayQueue, opCount) << " s" << std::endl;
    LoopQueue<int> loopQueue = LoopQueue<int>();
    std::cout << "LoopQueue time: " << testQueue(loopQueue, opCount) << " s" << std::endl;
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

void demo3()
{
    LoopQueue<int> loopQueue = LoopQueue<int>();
    for ( int i = 0; i < 20; ++i )
    {
        loopQueue.enqueue(i);
        loopQueue.print();
        if(i%3==2)
        {
            loopQueue.dequeue();
            loopQueue.print();
        }
    }
}