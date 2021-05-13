//
// Created by Zhenglin Li on 2020/11/5.
//

#ifndef CALCULATE_GETINPUT_H
#define CALCULATE_GETINPUT_H

#endif //CALCULATE_GETINPUT_H

#include <iostream>
#include <string>
#define MAX_SIZE 100
using namespace std;

//本函数用来判断用户输入的表达式是否合法，合法则返回该表达式，不合法返回空
char *getExpression() {
    string str;
    cin >> str;//从输入流中读取字符串

    //把字符串转为字符数组以便处理
    char stringArray[MAX_SIZE] = {0};
    for (int i = 0; i < str.length(); i++) {
        stringArray[i] = str[i];
    }

    int i = 0;
    bool hasEqual = false;  //是否含有=号
    int count = 0;  //括号的数量，'(' 则++; ')'--
    for (; i < str.length(); i++) {
        //判断是否含有'='号
        if (stringArray[i] == '=') {
            hasEqual = true;
            break;
        }
        //是否含有非法字符
        if (!(stringArray[i] <= '9' && stringArray[i] >= '0') && stringArray[i] != '+' && stringArray[i] != '-' &&
            stringArray[i] != '*' && stringArray[i] != '/' && stringArray[i] != '(' && stringArray[i] != ')' &&
            stringArray[i] != '%' && stringArray[i] != '&' && stringArray[i] != '^' && stringArray[i] != '.') {
            cout << "ERROR, Input Invalid!" << endl;
            return NULL;
        }
        //左右括号的判断
        if (stringArray[i] == '(') count++;
        if (stringArray[i] == ')') count--;
    }
    //左右括号的判断
    if (count != 0) {
        cout << "ERROR, Input Invalid!" << endl;
        return NULL;
    }
    //等于符号的判断，以及等于符号后是否还有字符
    if (!hasEqual) {
        cout << "There are no = " << endl;
        return nullptr;
        //判断有无=，=后面有没有其他字符
    } else if (i < str.length() - 1) {
        cout << "There are characters behind = " << endl;
        return nullptr;
        //表达式合法
    } else {
        //到此，输入的字符串以及为合法的表达式了，new static一个新数组并返回
        cout << "Your Input Is Valid" << endl;
        const int length = i;
        static char result[50];
        for (i = 0; i < length; i++) {
            result[i] = stringArray[i];
        }
        result[i] = '\0';
        cout << "expression to be calculated is: " << result << endl;
        return result;
    }
}
