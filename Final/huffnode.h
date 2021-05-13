//
// Created by Zhenglin Li on 2020/12/5.
//

#ifndef FINAL_HUFFUNODE_H
#define FINAL_HUFFUNODE_H

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Huffman tree node abstract base class
template<typename E>
class HuffNode {
public:
    ~HuffNode() {}                // Base destructor
    virtual bool isLeaf() = 0;            // Determine type
    virtual E val() {
        return '0';
    }

    virtual HuffNode<E> *left() {
        return nullptr;
    }

    virtual HuffNode<E> *right() {
        return nullptr;
    }

};//5.27
template<typename E>   // Internal node subclass
class IntlNode : public HuffNode<E> {
private:
    HuffNode<E> *lc;   // Left child
    HuffNode<E> *rc;   // Right child
    E it;            // Value
public:
    IntlNode(HuffNode<E> *l, HuffNode<E> *r) {
        lc = l;
        rc = r;
    }

    bool isLeaf() { return false; }

    HuffNode<E> *left()  { return lc; }

    void setLeft(HuffNode<E> *b) { lc = (HuffNode<E> *) b; }

    HuffNode<E> *right()  { return rc; }

    void setRight(HuffNode<E> *b) { rc = (HuffNode<E> *) b; }

    E val() { return it; }
};

template<typename E>   // Leaf node subclass
class LeafNode : public HuffNode<E> {
private:
    E it;            // Value
public:
    LeafNode(const E &val)   // Constructor
    { it = val; }

    E val() { return it; }

    bool isLeaf() { return true; }
};


#endif //FINAL_HUFFUNODE_H
