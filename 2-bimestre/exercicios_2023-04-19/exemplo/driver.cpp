#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *p = &x;
    int **q = &p;

    cout << "&x: " << &x << endl;
    cout << "&p: " << &p << endl;
    cout << "&q: " << &q << endl;
    cout << endl;

    cout << "x: " << x << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << endl;

    cout << "*p: " << *p << endl;
    cout << "*q: " << *q << endl;
    cout << "**q: " << **q << endl;
    cout << endl;


    return 0;
}