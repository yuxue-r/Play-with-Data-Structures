//
// Created by yyz on 2020/4/4.
//

#ifndef INC_05_RECURSION_SUM_H
#define INC_05_RECURSION_SUM_H

template <typename T>
class Sum
{
public:
    static T sum(T arr[], int n)
    {
        return sum(arr, 0, n);
    }

    static T sum(T arr[], int l, int n)
    {
        if (l == n)
        {
            return 0;
        }
        return arr[l] + sum(arr, l + 1, n);
    }
};

#endif //INC_05_RECURSION_SUM_H
