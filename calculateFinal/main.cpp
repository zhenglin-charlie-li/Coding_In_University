#include <iostream>
#include "LStack.h"
#include "getInput.h"
#include "optr.h"
#include <string>
#include <cmath>

using namespace std;

//表达式计算函数，把表达式传入，返回的是计算出来的值
double getResult(char[]);

//基本计算函数，传入两个数和操作符，返回计算出来的值
double whichOptr(double, double, char);

//打印菜单
void printMenu();

//判断是否为数字
bool isdigit(char);

//主函数
int main() {
    //打印菜单
    printMenu();
    //得到合法的表达式
    char *expression = getExpression();
    if (expression == nullptr) {
        cout << "expression is NULL" << endl;
    } else {
        //开始计算，并得到结果
        double result = getResult(expression);
        //输出结果
        cout << "Result: " << result << endl;
    }
    return 0;
}

//打印菜单
void printMenu() {
    cout << "*******************************Caculate1.0*******************************" << endl;
    cout << "使用说明：" << endl;
    cout << "表达式可包含：" << endl;
    cout << "1.加（+），减（-），乘（*），除（/），求模（%），开方（&），乘方（^）" << endl;
    cout << "2.括号" << endl;
    cout << endl;
    cout << "请输入表达式<以等号“=”结束>：" << endl;
    cout << "" << endl;
}

//判断是否为数字
bool isdigit(char ch) {
    //优雅的写法
    return ch >= '0' && ch <= '9';
}

//表达式计算函数，把表达式传入，返回的是计算出来的值
double getResult(char *in) {
    //新建两个栈
    auto *optr = new LStack<char>;
    auto *opnd = new LStack<double>;
    //把等于号push入操作符栈以判断是否计算完毕
    optr->push('=');
    //var用于判断是否是两位及以上的整数
    int var = 0;
    //用于判断左括号下一个操作符不是数字的情况
    int te = 0;
    //开始计算
    for (int i = 0; !((in[i] == '\0') && (optr->topValue() == '=')); i++) {
        // cout << "正在处理" << in[i] << endl;
        //计算两个数字
        while (in[i] == '\0' && optr->topValue() != '=') {
            double numberA = opnd->pop();
            double numberB = opnd->pop();
//            cout << "(numberA)" << (numberA) << "(numberB)" << numberB << endl;
            double temp = whichOptr(numberB, numberA, optr->pop());
            opnd->push(temp);
        }
        //如果是数字
        if (isdigit(in[i])) {
            //当te==1，说明前一个数是左括号，当这次循环的值为数字时，就清零，表示没有输入负数的情况1*（-3）
            if (te == 1) {
                te = 0;
            }
            double t = in[i] - '0';
            if (var != 0) {
                double numberC = opnd->pop();
                double numberD = t;
                double temp = whichOptr(10 * numberC, numberD, '+');
                opnd->push(temp);
            } else {
                var++;
                opnd->push(t);
            }
            //判断小数点
        } else if (in[i] == '.') {
            //如果是小数点，则依次往后移动一位并*0.1加到结果中
            int powNum = 1;
            double numberE = opnd->pop();
            double numberF = in[++i] - '0';
            double temp = numberE + numberF * pow(0.1, powNum++);
            opnd->push(temp);
            //如果是小数点后面数字还是数字的话，则依次往后顺移动一位并*0.1加到结果中
            while (isdigit(in[i + 1])) {
                numberE = opnd->pop();
                numberF = in[++i] - '0';
                temp = numberE + numberF * pow(0.1, powNum++);
                opnd->push(temp);
            }
        } else if (in[i] != '\0') { //由于下一次不再数字，将var置于初始零
            var = 0;
            //标识遇到左括号的情况
            if (in[i] == '(') {
                te = 1;
            }
            if (optr_level_in(optr->topValue()) < optr_level_out(in[i])) {  //如果栈内优先级小于栈外优先级
                optr->push(in[i]);
                //遇到负数就push 0
                //
                if (in[i] == '-' && te == 1 ){
                    opnd->push(0);
                }

            } else if (optr_level_in(optr->topValue()) > optr_level_out(in[i])) {
                double numberA = opnd->pop();
                double numberB = opnd->pop();
//                cout << "(numberA)" << (numberA) << "(numberB)" << numberB << endl;
//
                double temp = whichOptr(numberB, numberA, optr->pop());
                opnd->push(temp);
                i--;
            } else {
                optr->pop();
            }
        }
    }
    //返回结果
    return opnd->topValue();
}

//基本计算函数，传入两个数和操作符，返回计算出来的值
double whichOptr(double a, double b, char optr) {
    if (optr == '+') {
//        cout << a << optr << b << endl;
        return a + b;
    }
    if (optr == '-') {
//        cout << a << optr << b << endl;
        return a - b;
    }
    if (optr == '*') {
//        cout << a << optr << b << endl;
        return a * b;
    }
    if (optr == '/') {
        //除数不能为0
        if (b == 0) {
            cout << "error" << endl;//判断除数为零
        }
//        cout << a << optr << b << endl;
        else {
            return a / b;
        }
    }
    if (optr == '%') {
//        cout << a << optr << b << endl;
        return (int) a % (int) b;//
    }
    if (optr == '^') {
//        cout << a << optr << b << endl;
        return pow(a, b);
    }
    if (optr == '&') {
        //开方函数的计算方法
        return pow(a, 1.0 / b);
    }
    return 0.0;
}

