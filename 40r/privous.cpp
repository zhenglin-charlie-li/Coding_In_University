#include <iostream>

using namespace std;

class A {
private:
    int value;
public:
    A(int n) { value = n; }

    A(A const &other) { value = other.value; }

    void print() { cout << value << endl; }
};

int main1() {
    A a = 10;
    A b = a;
    b.print();
    return 0;
}