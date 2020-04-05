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
    // 向以node为根的二分搜索树中插入元素data，递归算法
    // 返回插入新节点后二分搜索树的根
    void add(T data)
    {
        root = add(root,data);
    }
    // 看二分搜索树中是否包含元素data
    bool contain(T data)
    {
        return contain(root,data);
    }
    // 前序遍历以node为根的二分搜索树, 递归算法
    void preOrder()
    {
        preOrder(root);
    }
    // 二分搜索树的中序遍历
    void inOrder()
    {
        inOrder(root);
    }
    // 二分搜索树的后序遍历
    void postOrder()
    {
        postOrder(root);
    }
    //二分搜索树的打印操作
    void print()
    {
        generateBSTString(root, 0);
    }


private:
    Node* add(Node *node, T data)
    {
        if(node == nullptr)
        {
            size++;
            return new Node(data);
        }
        if(data == node->data)
            return node;
        else if(data < node->data)
            node->left = add(node->left,data);
        else
            node->right = add(node->right,data);

        return node;
    }

    bool contain(Node* node,T data)
    {
        if(node == nullptr)
            return false;
        if(node->data == data)
            return true;
        else if(data < node->data)
            return contain(node->left,data);
        else
            return contain(node->right,data);
    }

    void preOrder(Node* node)
    {
        if(node == nullptr)
            return;
        std::cout<<node->data<<std::endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node)
    {
        if(node == nullptr)
            return;
        inOrder(node->left);
        std::cout<<node->data<<std::endl;
        inOrder(node->right);
    }

    void postOrder(Node* node)
    {
        if(node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout<<node->data<<std::endl;
    }

    void generateBSTString(Node* node,int depth)
    {

        for (int i = 0; i < depth; ++i)
        {
            std::cout << "--";
        }
        if(node == nullptr)
        {
            std::cout << "NULL"<<std::endl;
            return;
        }
        std::cout<<node->data<<std::endl;
        generateBSTString(node->left,depth+1);
        generateBSTString(node->right,depth+1);
    }
};


#endif //INC_06_BINARY_SEARCH_TREE_BST_H
