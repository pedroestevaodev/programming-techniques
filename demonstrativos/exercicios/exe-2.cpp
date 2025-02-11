#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    int m[3][3];
    int diagonalL = 0, diagonalR = 0;
    srand(time(NULL));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m[i][j] = (rand() % 100);
            if(i == j) {
                diagonalL = diagonalL + m[i][j];
            }
            if((i + j) == 2) {
                diagonalR = diagonalR + m[i][j];
            }
            cout << "m[" << i << "][" << j << "] = " << m[i][j] << endl;
        }
    }

    cout << "\nA soma dos valores da diagonal esquerda sao: " << diagonalL << endl;
    cout << "A soma dos valores da diagonal direita sao: " << diagonalR << "\n" << endl;

    return 0;
}