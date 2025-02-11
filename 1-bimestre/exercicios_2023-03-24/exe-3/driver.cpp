#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    string nome;
    cout << "Digite seu nome: ";
    getline(cin, nome);

    string login;
    size_t pos = nome.find(" ");

    if(pos != string::npos) {
        login += tolower(nome[0]);
        size_t sobrenomes = count(nome.begin() + pos + 1, nome.end(), ' ') + 1;

        if(sobrenomes == 1) {
            login += tolower(nome[pos + 1]);
            login += nome.substr(pos + 2);

        } else if(sobrenomes >= 2) {
            while(pos != string::npos) {
                login += tolower(nome[pos + 1]);
                pos = nome.find(" ", pos + 1);
            }

            login += nome.substr(nome.find_last_of(" " + 2));
        }
    } else {
        login = tolower(nome[0]);
        login += nome.substr(1);
    }

    cout << "Nome completo: " << nome << endl;
    cout << "Login: " << login << endl;

    return 0;
}