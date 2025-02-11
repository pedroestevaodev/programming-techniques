#include <iostream>
using namespace std;

int main() 
{
    int a, *b;
    b = &a;
    a = 10;

    cout << "&a=" << &a << " a=" << a << " &b=" << &b << " b=" << b << " *b=" << *b << endl;

    (*b)++;
    // *b = 11;
    // *b = b + 1;

    cout << "&a=" << &a << " a=" << a << " &b=" << &b << " b=" << b << " *b=" << *b << endl;

    return 0;
}