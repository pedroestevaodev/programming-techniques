#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    float notaJuiz[3][4];

    cout << "Digite a primeira nota do 1º Bimetre:" << endl;
    cin >> notaJuiz[0][0];

    cout << "Digite a segunda nota do 1º Bimetre:" << endl;
    cin >> notaJuiz[0][1];

    cout << "Digite a terceira nota do 1º Bimetre:" << endl;
    cin >> notaJuiz[0][2];

    cout << "Digite a quarta nota do 1º Bimetre:" << endl;
    cin >> notaJuiz[0][3];

    cout << "Digite a primeira nota do 2º Bimetre:" << endl;
    cin >> notaJuiz[1][0];

    cout << "Digite a segunda nota do 2º Bimetre:" << endl;
    cin >> notaJuiz[1][1];

    cout << "Digite a terceira nota do 2º Bimetre:" << endl;
    cin >> notaJuiz[1][2];

    cout << "Digite a quarta nota do 2º Bimetre:" << endl;
    cin >> notaJuiz[1][3];

    cout << "Digite a primeira nota do 3º Bimetre:" << endl;
    cin >> notaJuiz[2][0];

    cout << "Digite a segunda nota do 3º Bimetre:" << endl;
    cin >> notaJuiz[2][1];

    cout << "Digite a terceira nota do 3º Bimetre:" << endl;
    cin >> notaJuiz[2][2];

    cout << "Digite a quarta nota do 3º Bimetre:" << endl;
    cin >> notaJuiz[2][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Nota "<<j+1<<" do "<<i+1<<" bimestre: "<<notaJuiz[i][j]<<endl;
        }
    }

    return 0;
}