#include <iostream>
using namespace std;

unsigned int iteFibonacci(unsigned int n) {
    int resultado, ultimo, penultimo = 0;

    if (n <= 0) {
        resultado = 0;
    } else if (n == 1) {
        resultado = n;
    } else {
        ultimo = 1;
        penultimo = 0;
        for (int i = 2; i <= n; i++) {
            resultado = ultimo + penultimo;
            penultimo = ultimo;
            ultimo = resultado;
        }
    }

    return resultado;
}

int main() {
    int n;

    cout << "Digite um número: " << endl;
    cin >> n;

    cout << "O valor de " << n << " é: " << iteFibonacci(n) << endl;

    return 0;
}