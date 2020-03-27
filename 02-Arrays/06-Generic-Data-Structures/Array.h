//
// Created by yyz on 2020/3/26.
//

#ifndef INC_02_ARRAYS_ARRAY_H
#define INC_02_ARRAYS_ARRAY_H

#include "cassert"

template <typename T>
class Array
{

private:
    T *data;
    int size;
    int capacity;

public:
    // 构造函数，传入数组的容量capacity构造Array
    Array(int capacity)
    {
        data = new T [capacity];
        size=0;
        this->capacity=capacity;
    }

    // 无参数的构造函数，默认数组的容量capacity=10
    Array()
    {
        data = new T [10];
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
     void addLast(T e)
     {
        //assert(size<capacity);

        //data[size] = e;
        //size ++;
        add(size, e);
    }

    // 在所有元素前添加一个新元素
    void addFirst(T e)
    {
        add(0, e);
    }

    // 在index索引的位置插入一个新元素e
     void add(int index, T e)
     {

        assert(size<capacity);

        assert(index>=0 && index<=size);

        for(int i = size - 1; i >= index ; i --)
            data[i + 1] = data[i];

        data[index] = e;
        //记得更新size，之后
        size ++;
    }

    // 获取index索引位置的元素
     T get(int index)
     {
        //注意下标问题，因为index从零开始
        assert(index>=0 && index<size);
        return data[index];
    }

    // 修改index索引位置的元素为e
     void set(int index, T e)
     {
        assert(index>=0 && index<size);
        data[index] = e;
    }

    // 查找数组中是否有元素e
    bool contains(T e)
    {
        for(int i = 0 ; i < size ; i ++)
        {
            if(data[i] == e)
                return true;
        }
        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
     int find(T e)
     {
        for(int i = 0 ; i < size ; i ++){
            if(data[i] == e)
                return i;
        }
        return -1;
    }

    // 从数组中删除index位置的元素, 返回删除的元素
     T remove(int index)
     {
        assert( index >= 0 && index < size);

        T ret = data[index];
        for(int i = index + 1 ; i < size ; i ++)
            data[i - 1] = data[i];
        //注意维护size
        size --;
        return ret;
    }

    // 从数组中删除第一个元素, 返回删除的元素
     T removeFirst()
     {
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
     T removeLast()
     {
        return remove(size - 1);
    }

    // 从数组中删除元素e
    void removeElement(T e)
    {
        int index = find(e);
        if(index != -1)
            remove(index);
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
