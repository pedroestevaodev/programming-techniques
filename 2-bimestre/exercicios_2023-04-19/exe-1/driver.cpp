#include <iostream>
using namespace std;

struct No {
    int valor;
    No *no;
};

typedef struct No No;

int main() {
    No *x;
    No n1,n2,n3;

    n1.valor = 1;
    n2.valor = 2;
    n3.valor = 3;

    x = &n1;
    n1.no = &n2;
    n2.no = &n3;
    n3.no = &n1;

    // A) Imprima o endereço do nó, o valor inteiro e o endereço guardado no nó.
    cout << "Endereço do nó:" << endl;
    cout << "- " << x << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no << endl;
    cout << endl;

    // B) Imprima as informações solicitadas em "a" para todos os nós da estrutura.
    // for(int i = 0; i < 3; i++) {
    //     cout << "Endereço do nó:" << endl;
    //     cout << "- " << x->no << endl;
    //     cout << "Valor inteiro:" << endl;
    //     cout << "- " << (no + i)->valor << endl;
    //     cout << "Endereço guardado no nó:" << endl;
    //     cout << "- " << (no + i)->no << endl;
    //     cout << endl;
    // }

    cout << "Endereço do nó:" << endl;
    cout << "- " << &n1 << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << n1.valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << n1.no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << &n2 << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << n2.valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << n2.no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << &n3 << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << n3.valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << n3.no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << &x << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no << endl;
    cout << endl;

    // C)
    // No n4;
    // n4.valor = 4;
    // n4.no = &n1;
    // n3.no = &n4;

    // cout << "Endereço do nó:" << endl;
    // cout << "- " << &n4 << endl;
    // cout << "Valor inteiro:" << endl;
    // cout << "- " << n4.valor << endl;
    // cout << "Endereço guardado no nó:" << endl;
    // cout << "- " << n4.no << endl;
    // cout << endl;

    // // D)
    // x = &n2;
    // n4.no = &n2;

    return 0;
}