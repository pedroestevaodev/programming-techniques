#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

int flip() {
    srand(time(0));
    return rand() % 2;
}

int main() {
    int iniciar;
    char escolhaT[10];
    int escolhaI;
    int result;
    int cara = 0;
    int coroa = 1;

    printf("\n");
    cout<<"Quer jogar a moeda? [s/n]\n";
    iniciar = getch();
    printf("\n");

    if (iniciar == 115) {
        cout<<"Quer cara ou coroa?\n";
        fgets(escolhaT, 10, stdin);
        printf("\n");
        
        escolhaI = strcmp(escolhaT, "cara");
        cout << escolhaI;
        printf("\n");

        if((escolhaI < 0) || (escolhaI > 1)) {
            cout<<"Sua escolha foi invalida. Rode o programa novamente! Bye.";
            cout<<endl;
            return 0;
        }
    } else {
        cout<<"Quem sabe na proxima. Tchau!";
        cout<<endl;
        return 0;
    }

    printf("Sua escolha foi: ");
    printf("\"%s\"", escolhaT);
    printf("\n");
    result = flip();

    if(result == escolhaI) {
        printf("O resultado foi: ");
        cout << result;
        printf("\n");
        printf("Voce tem muita sorte! Parabens!");
        cout<<endl;
    } else {
        printf("O resultado foi: ");
        cout << result;
        printf("\n");
        printf("Voce nao tem sorte. Tente novamente!");
        cout<<endl;
    }

    return 0;
}