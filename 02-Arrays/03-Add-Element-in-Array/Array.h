//
// Created by yyz on 2020/3/26.
//

#ifndef INC_02_ARRAYS_ARRAY_H
#define INC_02_ARRAYS_ARRAY_H

#include "cassert"

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
    // 析构函数，释放空间
    ~Array()
    {
        delete [] data ;
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
        return this->size == 0;
    }

    // 向所有元素后添加一个新元素
     void addLast(int e)
     {
        //assert(size<capacity);

        //data[size] = e;
        //size ++;
        add(size, e);
    }

    // 在所有元素前添加一个新元素
    void addFirst(int e)
    {
        add(0, e);
    }

    // 在index索引的位置插入一个新元素e
     void add(int index, int e)
     {

        assert(size<capacity);

        assert(index>=0 && index<=size);

        for(int i = size - 1; i >= index ; i --)
            data[i + 1] = data[i];

        data[index] = e;
        //记得更新size，之后
        size ++;
    }
    void print()
    {
        assert(size > 0);
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i)
        {
            std::cout << data[i];
            if (i != size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        std::cout << std::endl;
    }

};

#endif //INC_02_ARRAYS_ARRAY_H
