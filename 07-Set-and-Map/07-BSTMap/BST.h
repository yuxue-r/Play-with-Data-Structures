//
// Created by yyz on 2020/4/5.
//

#ifndef INC_06_BINARY_SEARCH_TREE_BST_H
#define INC_06_BINARY_SEARCH_TREE_BST_H

#include "stack"
#include "queue"

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
    // 二分搜索树的非递归前序遍历
    void preOrderNR()
    {
        std::stack<Node *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            Node* cur = stack.top();
            std::cout << cur->data << " ";
            stack.pop();
            if (cur->right != nullptr)
            {
                stack.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                stack.push(cur->left);
            }
        }
        std::cout << std::endl;
    }
    // 二分搜索树的层序遍历
    void levelOrder()
    {
        std::queue<Node *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            Node* cur = queue.front();
            std::cout << cur->data << " ";
            queue.pop();
            if(cur->left != nullptr)
            {
                queue.push(cur->left);
            }
            if(cur->right != nullptr)
            {
                queue.push(cur->right);
            }
        }
        std::cout << std::endl;
    }
    // 寻找二分搜索树的最小元素
    T minimum()
    {
        Node* minNode = minimum(root);
        return minNode->data;
    }
    // 寻找二分搜索树的最大元素
    T maximum()
    {
        Node* maxNode = maximum(root);
        return maxNode->data;
    }
    // 从二分搜索树中删除最小值所在节点, 返回最小值
    T removeMinimum()
    {
        T ret = minimum();
        root = removeMinimum(root);
        return ret;
    }
    // 从二分搜索树中删除最大值所在节点, 返回最小值
    T removeMaximum()
    {
        T ret = maximum();
        root = removeMaximum(root);
        return ret;
    }
    // 从二分搜索树中删除元素为e的节点
    void remove(T data)
    {
        root = remove(root,data);
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
    // 返回以node为根的二分搜索树的最小值所在的节点
    Node* minimum(Node* node)
    {
        if(node->left == nullptr)
            return node;
        return minimum(node->left);
    }
    Node* maximum(Node* node)
    {
        if(node->right == nullptr)
            return node;
        return maximum(node->right);
    }
    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMinimum(Node* node)
    {
        if(node->left == nullptr)
        {
            Node* rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }
        node->left = removeMinimum(node->left);
        return node;
    }
    // 删除掉以node为根的二分搜索树中的最大节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMaximum(Node* node)
    {
        if(node->right == nullptr)
        {
            Node* leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }
        node->right = removeMaximum(node->right);
        return node;
    }
    Node* remove(Node* node,T data)
    {
        if(node == nullptr)
            return nullptr;
        if(data < node->data)
        {
            node->left = remove(node->left,data);
            return node;
        }
        else if(data > node->data)
        {
            node->right = remove(node->right,data);
            return node;
        }
        else
        {
            if(node->left == nullptr)
            {
                Node* rightNode = node->right;
                delete node;
                size--;
                return rightNode;
            }
            if(node->right == nullptr)
            {
                Node* leftNode = node->left;
                delete node;
                size--;
                return leftNode;
            }
            // 待删除节点左右子树均不为空的情况
            // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
            // 用这个节点顶替待删除节点的位置
//            Node* successor = minimum(node->right);
//            successor->right = removeMinimum(node->right);
//            successor->left = node->left;
//            node->left = node->right = nullptr;
//            node = nullptr;
//            delete node;
//            return successor;
            Node* predecessor = maximum(node->left);
            predecessor->left = removeMaximum(node->left);
            predecessor->right = node->right;
            node->left = node->right = nullptr;
            node = nullptr;
            delete node;
            return predecessor;
        }
    }
};


#endif //INC_06_BINARY_SEARCH_TREE_BST_H
