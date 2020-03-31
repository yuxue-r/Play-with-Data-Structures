#include <iostream>
#include "LinkList.h"
#include "LinkedListStack.h"
#include "ArrayStack.h"
using  namespace std;


void demo1();
void demo2();
void demo3();
int main()
{
    demo2();
    demo3();

    return 0;
}

template<typename T>
double testStack(T stack, int opCount)
{
    clock_t startTime = clock();
    srand(1000);
    for (int i = 0; i < opCount; ++i)
    {
        stack.push(rand());
    }
    for (int j = 0; j < opCount; ++j)
    {
        stack.pop();
    }
    clock_t endTime = clock();
    return double (endTime - startTime) / CLOCKS_PER_SEC;
}
void demo3()
{
    int opCount=1000000;
    ArrayStack<int> arrayStack =  ArrayStack<int>();
    std::cout << "ArrayStack time: " << testQueue(arrayStack, opCount) << " s" << std::endl;
    LinkedListStack<int> linkedListStack = LinkedListStack<int>();
    std::cout << "LinkedListStack time: " << testQueue(linkedListStack, opCount) << " s" << std::endl;
}


void demo2()
{
    LinkedListStack<int> linkedListStack =  LinkedListStack<int>();
    for(int i = 0; i < 5; ++i)
    {
        linkedListStack.push(i);
        linkedListStack.print();
    }
    cout << linkedListStack.pop() << endl;
    linkedListStack.print();
}

void demo1()
{
    LinkList<int> linkList =  LinkList<int>();
    for ( int i = 0; i < 5; ++i )
    {
        linkList.addFirst(i);
        linkList.print();
    }
    linkList.add(2,666);
    linkList.addLast(999);
    linkList.print();
//    cout<<linkList.get(2)<<endl;
//    cout<<linkList.contains(999)<<endl;
    linkList.remove(2);
    linkList.print();
    linkList.removeFirst();
    linkList.print();
    linkList.removeLast();
    linkList.print();

    linkList.removeElements(0);
    linkList.print();
}