//
// Created by Zhenglin Li on 2020/11/6.
//

#ifndef CALCULATE_OPTR_H
#define CALCULATE_OPTR_H

#endif //CALCULATE_OPTR_H

int optr_level_in(char ch) {
    if (ch != '=' && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '(' && ch != ')' &&
        ch != '^' && ch != '&' && ch != '0') {
        return -1;
    }
    switch (ch) {
        case '=':
            return 0;
        case '+':
        case '-':
            return 3;
        case '*':
        case '/':
        case '%':
            return 5;
        case '(':
            return 1;
        case ')':
            return 8;
        case '^':
        case '&':
            return 7;
        case '0':
            return 0;
    }
}

int optr_level_out(char ch) {
    if (ch != '=' && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '(' && ch != ')' &&
        ch != '^' && ch != '&' && ch != '0') {
        return -1;
    }
    switch (ch) {
        case '=':
            return 0;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 4;
        case '(':
            return 8;
        case ')':
            return 1;
        case '^':
        case '&':
            return 6;
        case '0':
            return 0;
    }
}
