#include <iostream>
using namespace std;

void converteBinario(int n)
{
    int sobra, divisao;

    if (n == 0) {
        n = 0;
    } 
    else
    {
        sobra = n % 2;
        divisao = n / 2;
        converteBinario(divisao);
        cout << sobra;
    }
}

int main()
{
    int n;

    cout << "Informe um numero para converter: " << endl;
    cin >> n;

    cout << "O numero " << n << " em binario e: " << endl;
    converteBinario(n);

    return 0;
}