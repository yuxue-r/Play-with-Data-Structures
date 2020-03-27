//2020-3-26
//yyz

#include <iostream>
#include "Array.h"
using namespace std;

int main()
{

    Array arr1 = Array(30);
    /*int a = arr1.getSize();
    int b = arr1.getCapacity();
    cout<< a << " "<< b <<endl;*/

    for (int i = 0; i < 10; ++i)
    {
        arr1.addLast(i);
    }
    arr1.print();

    arr1.addFirst(-1);
    arr1.addLast(100);
    arr1.add(3,0);
/*    a = arr1.getSize();
    b = arr1.getCapacity();
    cout<< a << " "<< b <<endl;*/

    arr1.print();

/*    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i]=i;
    }

    for (int j = 0; j < 10; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;

    int scores[] = {100, 99, 66};
    for (int k = 0; k < sizeof(scores) / sizeof(scores[0]); ++k) {
        cout << scores[k] << " ";
    }
    cout << endl;

    //在socre中遍历，类似java以及Python中遍历方法
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;


    scores[0] = 98;
    for (int l = 0; l < sizeof(scores) / sizeof(scores[0]); ++l) {
        cout << scores[l] << " ";
    }
    cout << endl;
*/


    return 0;
}