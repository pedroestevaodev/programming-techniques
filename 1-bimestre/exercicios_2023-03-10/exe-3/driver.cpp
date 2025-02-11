#include <iostream>
using namespace std;

int encontraRepeticao(int value, int digito)
{
    if (value == 0)
        return 0;
    else
    {
        if (value % 10 == digito)
            return 1 + encontraRepeticao(value / 10, digito);
        else
            return encontraRepeticao(value / 10, digito);
    }
}

int main()
{
    int number = 858486;
    int digito = 8;

    cout << "O digito " << digito<< " aparece " << encontraRepeticao(number, digito) << " vezes no numero: " << number  << endl;

    return 0;
}