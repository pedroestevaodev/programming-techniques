#include <iostream>
using namespace std;

int inverteValores(const int *values, int size)
{
    if (size == 0)
        return 0;
    else
        return cout << values[size - 1], inverteValores(values, size - 1);
}

int main()
{
    int values[5] = { 1, 2, 3, 4, 5 };

    inverteValores(values, 5);

    return 0;
}