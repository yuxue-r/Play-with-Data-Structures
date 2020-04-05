//
// Created by yyz on 2020/4/5.
//

#ifndef INC_06_BINARY_SEARCH_TREE_BST_H
#define INC_06_BINARY_SEARCH_TREE_BST_H

template <typename T>
class BST
{
private:
    // 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node(T data)
        {
            this->data = data;
            this->left = this->right = nullptr;
        }
    };

    Node *root; // 根节点
    int size;  // 节点个数

public:
    // 构造函数, 默认构造一棵空二分搜索树
    BST()
    {
        root = nullptr;
        size = 0;
    }
    ~BST()
    {
        // TODO: ~BST()
    }

    // 返回二分搜索树的节点个数
    int getSize()
    {
        return size;
    }

    // 返回二分搜索树是否为空
    bool isEmpty()
    {
        return size == 0;
    }
};


#endif //INC_06_BINARY_SEARCH_TREE_BST_H
