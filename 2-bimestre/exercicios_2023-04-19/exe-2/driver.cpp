#include <iostream>
using namespace std;

struct No {
    int valor;
    No *no;
};

typedef struct No No;

int main() 
{
    No *x = NULL;
    x = new No;

    x->valor = 1;
    x->no = new No;
    x->no->valor = 2;
    x->no->no = new No;
    x->no->no->valor = 3;
    x->no->no->no = x;

    // A) Imprima o endereço do nó, o valor inteiro e o endereço guardado no nó.
    cout << "Endereço do nó:" << endl;
    cout << "- " << x << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no << endl;
    cout << endl;

    // B) Imprima as informações solicitadas em "a" para todos os nós da estrutura.
    // for(int i = 1; i < 4; i++) {
    //     cout << "Endereço do nó:" << endl;
    //     cout << "- " << x->no << endl;
    //     cout << "Valor inteiro:" << endl;
    //     cout << "- " << (x + i)->valor << endl;
    //     cout << "Endereço guardado no nó:" << endl;
    //     cout << "- " << (x + i)->no << endl;
    //     cout << endl;
    // }
    cout << "Endereço do nó:" << endl;
    cout << "- " << x << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << x->no << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->no->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no->no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << x->no->no << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->no->no->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no->no->no << endl;
    cout << endl;

    // C) Insira um quarto nó após o último elemento da estrutura - Imprima o resultado na tela após realizar o procedimento.
    x->no->no->no->no = new No;
    x->no->no->no->valor = 4;

    cout << "Endereço do nó:" << endl;
    cout << "- " << x->no->no->no << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->no->no->no->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no->no->no->no << endl;
    cout << endl;

    // D) Remova o primeiro elemento da estrutura e imprima o resultado na tela após o procedimento.
    x = x->no;
    delete x->no->no->no;
    x->no->no->no = x;

    cout << "Endereço do nó:" << endl;
    cout << "- " << x << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << x->no << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->no->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no->no << endl;
    cout << endl;

    cout << "Endereço do nó:" << endl;
    cout << "- " << x->no->no << endl;
    cout << "Valor inteiro:" << endl;
    cout << "- " << x->no->no->valor << endl;
    cout << "Endereço guardado no nó:" << endl;
    cout << "- " << x->no->no->no << endl;
    cout << endl;

    return 0;
}