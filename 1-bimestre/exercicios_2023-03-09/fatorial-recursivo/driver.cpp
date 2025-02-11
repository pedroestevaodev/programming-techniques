#include <iostream>
#include <string>
using namespace std;

int recFatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * recFatorial(n - 1);
    }
}

int main() {
    int n;

    cout << "Digite o valor de n: ";
    cin >> n;

    cout << "Fatorial de " << n << ": " << recFatorial(n) << endl;
    
    return 0;
}