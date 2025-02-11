#include <iostream>
#include <fstream>
using namespace std;

int main()
{ 
    ofstream alunos("ALUNOS.DAT", ios::out);

    cout << "Informe o numero, nome, curso, nota1 e nota2, respectivamente: " << endl << "\n?";
    
    int numero;
    char nome[ 30 ];
    char curso[ 30 ];
    int nota1, nota2;

    while (cin >> numero >> nome >> curso >> nota1 >> nota2)
    {
        alunos << numero << " " << nome << " " << curso << " " << nota1 << " " << nota2 << endl;
        cout << "? ";
    }

    return 0;
}