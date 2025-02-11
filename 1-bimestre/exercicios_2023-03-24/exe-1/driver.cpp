#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string frase;

    cout << endl;
    cout << "Digite uma frase: " << endl;
    cout << "- ";
    getline(cin, frase);
    cout << endl;

    cout << "A frase digitada foi: " << endl;
    cout << "- " << frase << endl;
    cout << endl;

    string fraseConvertida = frase.replace(frase.find("ALUNO"), 5, "ESTUDANTE").replace(frase.find("ESCOLA"), 6, "UNIVERSIDADE");

    cout << "A frase convertida e: " << endl;
    cout << "- " << fraseConvertida << endl;
    cout << endl;

    return 0;
}