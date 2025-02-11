#include <iostream>
#include <string>
using namespace std;

unsigned int iteFatorial(unsigned int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int n;
    cout << "Digite o valor de n: ";
    cin >> n;

    cout << "Fatorial de " << n << ": " << iteFatorial(n) << endl;
    
    return 0;
}