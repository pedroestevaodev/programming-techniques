#include <iostream>
using namespace std;

int calculaSoma(int *values, int size)
{
    if (size == 0)
        return 0;
    else
        return values[size - 1] + calculaSoma(values, size - 1);
}

int main()
{
    int values[5] = { 1, 2, 3, 4, 5 };

    cout << calculaSoma(values, 5) << endl;

    return 0;
}