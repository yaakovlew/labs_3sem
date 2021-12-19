#pragma once
#include <iostream>
#include <stdexcept>
#include "Branch.h"

template<typename T>
T max(T &&a, T &&b) {
    return a > b ? a : b;
}

template<typename T, typename V>
class AVLTree {
private:


    struct Node {
    public:
        Node(T key, V value) : pair(key, value), height(1), right(nullptr), left(nullptr) {};

        explicit Node(Branch<T, V> pair) : pair(&pair), height(1), right(nullptr), left(nullptr) {};

        explicit Node(Node *node);

        Branch<T, V> pair;
        unsigned int height = 0;
        Node *left, *right;

        ~Node();
    };


    Node *root;
    int size;

    int _height(Node *) const;

    void _updateHeight(Node *);

    int _balanceFactor(Node *node) const;

    Node *_rotateRight(Node *node);

    Node *_rotateLeft(Node *node);

    Node *_balance(Node *node);

    Node *_insert(Node *node, Branch<T, V> pair);

    Node *_get(Node *node, T key);

    Node *_findMax(Node *node) const;

    Node *_find(Node *node, T key) const;

    Node *_removeMin(Node *);

    Node *_findMin(Node *) const;

    Node *_remove(Node *, T);

    template<typename func>
    void _traversal(Node *node, Node *parent, func foo);

    Branch<T, V> *_get_pairs(Node *node, Node *parent);

public:
    AVLTree() : root(nullptr), size(0) {};

    AVLTree(const AVLTree<T, V> &Tree) : root(Tree.root ? new Node(Tree.root) : nullptr), size(Tree.size) {}

    void insert(Branch<T, V> pair);

    Branch<T, V> &get(T key);

    Branch<T, V> findMax();

    bool find(T key);

    template<typename func>
    void traversal(func foo) { _traversal(root, nullptr, foo); }

    Branch<T, V> *get_pairs() { return _get_pairs(root, nullptr); }

    ~AVLTree();
};

template<typename T, typename V>
int AVLTree<T, V>::_height(Node *node) const {
    return node ? node->height : 0;
}

template<typename T, typename V>
void AVLTree<T, V>::_updateHeight(Node *node) {
    node->height = max(_height(node->left), _height(node->right)) + 1;
}

template<typename T, typename V>
int AVLTree<T, V>::_balanceFactor(Node *node) const {
    return _height(node->right) - _height(node->left);
}


template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_rotateRight(Node *node) {
    Node *buff = node->left;
    node->left = buff->right;
    buff->right = node;
    _updateHeight(node);
    _updateHeight(buff);

    return buff;

}


template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_rotateLeft(Node *node) {
    Node *buff = node->right;
    node->right = buff->left;
    buff->left = node;
    _updateHeight(node);
    _updateHeight(buff);

    return buff;

}


template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_balance(Node *node) {
    _updateHeight(node);

    if (_balanceFactor(node) == 2) {
        if (_balanceFactor(node->right) < 0)
            node->right = _rotateRight(node->right);
        node = _rotateLeft(node);
    }
    if (_balanceFactor(node) == -2) {
        if (_balanceFactor(node->left) > 0)
            node->left = _rotateLeft(node->left);
        node = _rotateRight(node);
    }

    return node;
}


template<typename T, typename V>
AVLTree<T, V>::~AVLTree() {
    delete this->root;
    this->size = 0;
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_insert(AVLTree::Node *node, Branch<T, V> pair) {
    if (node == nullptr) {
        return new Node(pair);
    }
    if (pair.getKey().getValue() < node->pair.getKey().getValue())
        node->left = _insert(node->left, pair);
    else
        node->right = _insert(node->right, pair);

    _updateHeight(node);
    size++;
    return _balance(node);
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_get(AVLTree::Node *node, T key) {
    if (node == nullptr)
        throw std::out_of_range("AVL_Tree out of range!");

    if (key == node->pair.getKey().getValue())
        return node;

    if (key < node->pair.getKey().getValue())
        return _get(node->left, key);
    else
        return _get(node->right, key);
}

template<typename T, typename V>
void AVLTree<T, V>::insert(Branch<T, V> pair) {
    if (this->root == nullptr) {
        this->root = new Node(pair);
    } else {
        this->root = _insert(this->root, pair);
    }
}

template<typename T, typename V>
Branch<T, V> &AVLTree<T, V>::get(T key) {
    return _get(root, key)->pair;
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_findMax(AVLTree::Node *node) const {
    return node->right ? _findMax(node->right) : node;
}

template<typename T, typename V>
Branch<T, V> AVLTree<T, V>::findMax() {
    Node *max_node = _findMax(root);
    return max_node->pair;
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_find(AVLTree::Node *node, T key) const {
    if (node == nullptr)
        return nullptr;
    if (key == node->pair.getKey().getValue())
        return node;
    if (key < node->pair.getKey().getValue())
        return _find(node->left, key);
    if (key > node->pair.getKey().getValue())
        return _find(node->right, key);
}

template<typename T, typename V>
bool AVLTree<T, V>::find(T key) {
    return _find(root, key) != nullptr;
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_remove(AVLTree::Node *node, T key) {
    if (node == nullptr)
        throw std::out_of_range("AVLTree out of range!");
    if (key < node->pair.getKey().getValue())
        node->left = _remove(node->left, key);
    else if (key > node->pair.getKey().getValue())
        node->right = _remove(node->right, key);
    else {
        Node *left = node->left;
        Node *right = node->right;

        node->left = nullptr;
        node->right = nullptr;
        delete node;

        if (right == nullptr)
            return left;

        Node *min = _findMin(right);
        min->right = _removeMin(right);
        min->left = left;
        return _balance(min);
    }
    return _balance(node);
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_removeMin(AVLTree::Node *node) {
    if (node->left == nullptr)
        return node->right;
    node->left = _removeMin(node->left);
    return _balance(node);
}

template<typename T, typename V>
typename AVLTree<T, V>::Node *AVLTree<T, V>::_findMin(Node *node) const {
    return node->left ? _findMin(node->left) : node;
}


template<typename T, typename V>
template<typename func>
void AVLTree<T, V>::_traversal(AVLTree::Node *node, AVLTree::Node *parent, func foo) {
    if (node == nullptr)
        return;

    if (node == parent) {
        foo(node->pair);
    } else {
        void *n1 = node->left, *n2 = node, *n3 = node->right;

        _traversal((Node *) n1, node, foo);
        _traversal((Node *) n2, node, foo);
        _traversal((Node *) n3, node, foo);
    }
}

template<typename T, typename V>
Branch<T, V> *AVLTree<T, V>::_get_pairs(AVLTree::Node *node, AVLTree::Node *parent) {
    auto result = new Branch<T, V>[size];
    int i = 0;
    if (node == nullptr)
        return nullptr;

    if (node == parent) {
        i++;
        result[i] = node->pair;
    } else {
        void *n1 = node->left, *n2 = node, *n3 = node->right;
        //type(n1, n2, n3);

        _get_pairs((Node *) n1, node);
        _get_pairs((Node *) n2, node);
        _get_pairs((Node *) n3, node);
    }
    return result;
}

template<typename T, typename V>
AVLTree<T, V>::Node::~Node() {
    delete left;
    delete right;
}

template<typename T, typename V>
AVLTree<T, V>::Node::Node(AVLTree::Node *node) {
    pair(node->pair);
    height(node->pair);
    if (node->left != nullptr) {
        left = new Node(node->left);
    } else {
        left = nullptr;
    }

    if (node->right != nullptr) {
        right = new Node(node->right);
    } else {
        right = nullptr;
    }
};
