//2020-3-26
//yyz

#include <iostream>
using namespace std;

int main() {
    int arr[10];
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


    return 0;
}