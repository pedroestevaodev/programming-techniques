#include <iostream>
using namespace std;

int main() 
{
    int vetA[3] = {2, 3, 4};
    int vetB[3] = {4, 5, 6};
    int vetC[3];

    for(int i = 0; i < 3; i++)
    {
        *(vetC+i) = (*(vetA+i) + *(vetB+i)) / 2;
        cout << *(vetC+i) << endl;
    }

    return 0;
};