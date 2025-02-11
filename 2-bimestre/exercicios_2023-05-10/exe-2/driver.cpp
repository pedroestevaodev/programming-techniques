#include <iostream>
#include <fstream>
using namespace std;

void outputLine(const string nome, int matricula, const string email)
{
    cout << left << nome << matricula << right << email << endl;
}

int main()
{ 
    ifstream alunos("Alunos_CC", ios::in);

    char nome[ 30 ];
    int matricula;
    char email[ 30 ];

    cout << left << "Aluno" << "Matricula" << "Email" << endl << fixed << showpoint;

    while (alunos >> nome >> matricula >> email)
    {
        outputLine(nome, matricula, email);
    }

    return 0;
}