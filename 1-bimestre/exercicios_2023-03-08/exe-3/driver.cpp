#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Livro {
    string titulo;
    int ano_edicao;
    int numero_paginas;
    double preco;
};

int main() {
    Livro livro;
    vector<Livro> livros[5];
    float soma = 0;

    for(int i = 0; i < 5; i++) {
        cout << "Digite o titulo do livro: ";
        getline(cin, livro.titulo);

        cout << "Digite o ano de edicao do livro: ";
        cin >> livro.ano_edicao;
        cin.ignore();

        cout << "Digite o numero de paginas do livro: ";
        cin >> livro.numero_paginas;
        cin.ignore();

        cout << "Digite o preco do livro: ";
        cin >> livro.preco;
        cin.ignore();

        livros[i].push_back(livro);
        soma += livro.numero_paginas;

        cout << endl;
    }

    cout << "A media do numero de paginas dos livros e:" << endl;
    cout << (soma / 5) << endl;

    return 0;
};