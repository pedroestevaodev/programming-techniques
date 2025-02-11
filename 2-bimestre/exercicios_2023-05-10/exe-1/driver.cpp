#include <iostream>
#include <fstream>
using namespace std;

int main()
{ 
    ofstream alunos("Alunos_CC", ios::out);

    cout << "Informe o nome, matricula e email do aluno, respectivamente: " << endl << "\n?";
    
    char nome[ 30 ];
    int matricula;
    char email[ 30 ];

    while (cin >> nome >> matricula >> email)
    {
        alunos << nome << " " << matricula << " " << email << endl;
        cout << "? ";
    }

    return 0;
}