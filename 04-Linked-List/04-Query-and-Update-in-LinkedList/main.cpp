#include <iostream>
#include "LinkList.h"
using  namespace std;


void demo1();
int main()
{
    demo1();

    return 0;
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
    cout<<linkList.get(2)<<endl;
    cout<<linkList.contains(999)<<endl;
}