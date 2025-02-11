#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string frase = "Muitos usam o TECLADO para jogar. Mas realmente precisam do TECLADO?";
    // int posicao;

    cout << endl;
    // cout << "Digite uma frase: " << endl;
    // cout << "- ";
    // getline(cin, frase);
    // cout << endl;

    cout << "A frase digitada foi: " << endl;
    cout << "- " << frase << endl;
    cout << endl;

    size_t pos = 0;
    while ((pos = frase.find("TECLADO", pos)) != string::npos) {
        frase.insert(pos + 7, " OU MOUSE");
        pos += 14;
    }

    cout << "A frase convertida e: " << endl;
    cout << "- " << frase << endl;
    cout << endl;

    return 0;
}