#include <iostream>
using namespace std;

void calculaMDC(int n1, int n2)
{
    int sobra, divisao;

    if (n == 0) {
        n = 0;
    } 
    else
    {
        sobra = n % 2;
        divisao = n / 2;
        calculaMDC(divisao);
        cout << sobra;
    }
}

int main()
{
    int n1, n2;

    cout << "Digite o primeiro inteiro: " << endl;
    cin >> n1;

    cout << "Digite o segundo inteiro: " << endl;
    cin >> n2;

    cout << "O MDC de " << n1 << " e " << n2 << " é: " << endl;
    calculaMDC(n1, n2);

    return 0;
}