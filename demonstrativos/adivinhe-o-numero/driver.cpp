#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int sortear() {
    srand(time(NULL));
    return rand() % 1000 + 1;
}

int main() {
    int escolha;
    int escolhaNumero;
    int cara = 0, coroa = 0;

    printf("\n=====================================");
    printf("\n======= Jogo da Adivinhação =======\n");

    do {
        printf("\nVoce quer jogar?\n");
        printf("1 - Quero jogar\n");
        printf("0 - Quero sair\n");
        printf("R: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
            {
                int numero = sortear();

                do {
                    printf("\nEscolha um numero entre 1 e 1000: ");
                    scanf("%d", &escolhaNumero);

                    if (escolhaNumero == numero) {
                        printf("\nParabens, voce acertou!\n");
                        break;
                    } else if (escolhaNumero > numero) {
                        printf("\nO numero e menor que %d\n", escolhaNumero);
                    } else {
                        printf("\nO numero e maior que %d\n", escolhaNumero);
                    }
                } while (escolhaNumero != numero);
                break;
            }
            case 0:
            {
                printf("\nJogo encerrado.\n");
                break;
            }
            default:
            {
                printf("\nOpcao invalida.\n");
                break;
            }
        }

        

    } while (escolha != 0);


    printf("\n===================================\n");

    return 0;
}