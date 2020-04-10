//
// Created by yyz on 2020/4/10.
//

#ifndef INC_07_SET_AND_MAP_BSTMAP_H
#define INC_07_SET_AND_MAP_BSTMAP_H

#include "Map.h"
#include "cassert"

template <typename K,typename V>
class BSTMap : public Map<K,V>
{
private:
    // 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node
    {
        K key;
        V value;
        Node *left;
        Node *right;
        Node(K key,V value)
        {
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }
    };

    Node *root; // 根节点
    int size;  // 节点个数
    // 返回以node为根节点的二分搜索树中，key所在的节点
    Node* getNode(Node* node,K key)
    {
        if(node == nullptr)
            return node;
        if(node->key == key)
            return node;
        else if(key < node->key)
            return getNode(node->left,key);
        else
            return getNode(node->right,key);
    }

public:
    // 构造函数, 默认构造一棵空二分搜索树
    BSTMap()
    {
        root = nullptr;
        size = 0;
    }
    // 返回二分搜索树的节点个数
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool contains(K key)
    {
        Node* retNode = getNode(root,key);
        return retNode !=nullptr;
    }
    V get(K key)
    {
        Node* retNode = getNode(root,key);
        return retNode->value;
    }
    // 向二分搜索树中添加新的元素(key, value)
    void add(K key,V value)
    {
        root = add(root,key,value);
    }

    void set(K key,V value)
    {
        Node* retNode = getNode(root,key);
        assert(retNode != nullptr);
        retNode->value = value;
    }
    // 从二分搜索树中删除键为key的节点
    // 从二分搜索树中删除元素为e的节点
    V remove(K key)
    {
        Node* retNode = getNode(root,key);
        if(retNode != nullptr)
        {
            root = remove(root,key);
            return retNode->value;
        }
        return retNode->value;
    }

private:
    Node* add(Node* node,K key,V value)
    {
        if(node == nullptr)
        {
            size++;
            return new Node(key,value);
        }
        if(key == node->key)
        {
            node->value = value;
            return node;
        }
        else if(key < node->key)
            node->left = add(node->left,key,value);
        else
            node->right = add(node->right,key,value);
        return node;
    }
    Node* remove(Node* node,K key)
    {
        if(node == nullptr)
            return nullptr;
        if(key < node->key)
        {
            node->left = remove(node->left,key);
            return node;
        }
        else if(key > node->key)
        {
            node->right = remove(node->right,key);
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
};

#endif //INC_07_SET_AND_MAP_BSTSET_H
