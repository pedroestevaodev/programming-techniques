#include <iostream>
#include <fstream>
using namespace std;

int main()
{ 
    ofstream alunos_criar("ALUNOS.DAT", ios::out);

    cout << "Informe o numero, nome, curso, nota1 e nota2, respectivamente: " << endl;

    int numero, numero_r;
    char nome[ 30 ], nome_r[ 30 ];
    char curso[ 30 ], curso_r[ 30 ];
    int nota1, nota2, nota1_r, nota2_r;

    cout << "- ";

    while(cin >> numero >> nome >> curso >> nota1 >> nota2) {
        ifstream alunos_ler("ALUNOS.DAT", ios::in);

        while (alunos_ler >> numero_r >> nome_r >> curso_r >> nota1_r >> nota2_r)
        {
            if (numero_r == numero) {
                cout << endl;
                cout << "Aluno ja cadastrado!" << endl;
                return 0;
            }
        }

        cout << "- ";
        alunos_criar << numero << " " << nome << " " << curso << " " << nota1 << " " << nota2 << endl;
    };

    return 0;
}