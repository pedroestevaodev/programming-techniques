#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct DadosAluno {
    string idade;
    double media;
};

void cadastrarAlunos(vector<DadosAluno> &alunos) {
    DadosAluno aluno;

    for(int i = 0; i < 10; i++) {
        aluno.idade = to_string(rand() % 18 + 7);
        aluno.media = (rand() % 100) / 10;

        alunos.push_back(aluno);
    }
    cout << endl;
}

void visualizarAlunos(vector<DadosAluno> &alunos) {
    for (int i = 0; i < alunos.size(); i++) {
        cout << "-- Aluno " << (i+1) << " --" << endl;
        cout << "Idade: " << alunos[i].idade << endl;
        cout << "Media: " << alunos[i].media << endl;
        cout << endl;
    }
    cout << endl;
}

int main() {
    DadosAluno aluno;
    vector<DadosAluno> alunos;
    int opcao;

    do {
        cout << "MENU" << endl;
        cout << "1 - Iniciar cadastro de alunos" << endl;
        cout << "2 - Visualizar alunos" << endl;
        cout << "3 - Sair" << endl;

        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        cin.ignore();
        cout << endl;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Opcao invalida. Digite novamente: ";
            cin >> opcao;
            cin.ignore();
        }

        switch (opcao)
        {
            case 1:
                cout << "Entao vamos la. Foram cadastrados 10 alunos." << endl;

                cadastrarAlunos(alunos);
                break;
            case 2:
                visualizarAlunos(alunos);
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente!" << endl;
        }
    } while(opcao != 3);

    return 0;
};