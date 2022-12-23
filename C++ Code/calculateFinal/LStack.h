//
// Created by Zhenglin Li on 2020/11/5.
//

#ifndef CALCULATE_LSTACK_H
#define CALCULATE_LSTACK_H

#endif //CALCULATE_LSTACK_H

#include "iostream"

#define DEFAULT_SIZE 100

using namespace std;

//使用模板类，Node是栈中的节点
template<class E>
class Node {
public:
    E value;
    Node<E> *next;

    //构造函数，可以只传入value值
    Node(E value, Node<E> *next = NULL) : value(value), next(next) {}

    //构造函数，可以传入指向Node节点的指针
    Node(Node *nextNode = NULL) { next = nextNode; }
};

//使用模板类，LStack是栈
template<class E>
class LStack {
private:
    Node<E> *top;   //指向栈顶
    int size;   //栈中元素的个数
public:

    //构造函数，可以传入栈中元素的个数，也可以不传入而默认为DEFAULT_SIZE=100
    LStack(int size = DEFAULT_SIZE) {
        top = NULL;
        this->size = size;
    }

    //析构函数，调用clear来辅助删除栈
    ~LStack() {
        clear();
    }

    //自顶向下删除栈中的每个节点，然后置值为0
    void clear() {
        while (top != NULL) {
            Node<E> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    //往栈中压入一个元素，传入的是要压入元素的值
    void push(const E &character) {
        top = new Node<E>(character, top);
        size++;
    }

    //从栈中弹出一个元素，返回的是弹出元素的值
    E pop() {
        if (top == NULL) {
            cout << "error" << endl;
            return 0;
        }
        E out = top->value;
        Node<E> *ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return out;
    }

    //返回的栈顶元素的值
    const E &topValue() const {
        if (top == NULL) {
            cout << "error" << endl;
            return 0;
        }
        return top->value;
    }
};