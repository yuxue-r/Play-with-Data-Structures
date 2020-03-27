//
// Created by yyz on 2020/3/26.
//

#ifndef INC_02_ARRAYS_ARRAY_H
#define INC_02_ARRAYS_ARRAY_H

class Array
{

private:
    int *data;
    int size;
    int capacity;

public:
    // 构造函数，传入数组的容量capacity构造Array
    Array(int capacity)
    {
        data = new int [capacity];
        size=0;
        this->capacity=capacity;
    }

    // 无参数的构造函数，默认数组的容量capacity=10
    Array()
    {
        data = new int [10];
        size=0;
        this->capacity=10;
    }

    // 获取数组的容量
    int getCapacity()
    {
        return this->capacity;
    }

    // 获取数组中的元素个数
    int getSize()
    {
        return this->size;
    }

    // 返回数组是否为空
    bool isEmpty()
    {
        return this->size==0;
    }

};

#endif //INC_02_ARRAYS_ARRAY_H
