#include <iostream>
#include <string>
using namespace std;

struct DadosAluno {
    string idade;
    double media;
};

int main() {
    DadosAluno aluno;

    cout << "Digite a idade do aluno: ";
    getline(cin, aluno.idade);

    cout << "Digite a media do aluno: ";
    cin >> aluno.media;

    cout << "Idade: " << aluno.idade << endl;
    cout << "Media: " << aluno.media << endl;

    return 0;
};