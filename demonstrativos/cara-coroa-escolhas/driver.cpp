#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int flip() {
    return rand() % 2;
}

int main() {
    int escolha;
    int cara = 0, coroa = 0;

    srand(time(NULL));

    printf("\n==================================");
    printf("\n====== Jogo de cara e coroa ======\n");

    do {
        printf("\nTu quer jogar a moeda?\n");
        printf("1 - Quero jogar\n");
        printf("0 - Quero sair\n");
        printf("R: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
            {
                int resultado = flip();

                printf("\nO resultado foi: ");

                if (resultado == 0) {
                    coroa++;
                    printf("Coroa.\n");
                } else {
                    cara++;
                    printf("Cara.\n");
                }
                break;
            }
            case 0:
            {
                printf("\nJogo encerrado.\n\n");
                break;
            }
            default:
            {
                printf("\nOpcao invalida.\n");
                break;
            }
        }

    } while (escolha != 0);

    if((escolha == 0) && (cara != 0 || coroa != 0)) {
        printf("\n==================================");
        printf("\n=========== RESULTADOS ===========\n");
        printf("= Cara: %d", cara);
        printf("\n==================================\n");
        printf("= Coroa: %d", coroa);
        printf("\n==================================\n");
    }

    return 0;
}