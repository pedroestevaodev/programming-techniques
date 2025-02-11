#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    float m[5][5];
    float maior = m[0][0];
    int posicaoX = 0, posicaoY = 0;
    srand(time(NULL));

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            m[i][j] = (rand() % 100);
            if(m[i][j] > maior) {
                maior = m[i][j];
                posicaoX = i;
                posicaoY = j;
            }
            cout << "m[" << i << "][" << j << "] = " << m[i][j] << endl;
        }
    }
    
    cout << "Maior valor encontrado foi: " << maior << " na localizacao: m[" << posicaoX << "][" << posicaoY << "]" << endl;

    return 0;
}