#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

// int gerar() {
//     return rand() % 16;
// }

int main() {
    int m[4][4] = {
        {1, 14, 15, 4},
        {12, 6, 7, 9},
        {8, 10, 11, 5},
        {13, 2, 3, 16}
    };
    // int valores[] = {
    //     1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    // };
    int linha, coluna, diagonalP, diagonalS;
    // srand(time(NULL));

    cout << "\nMatriz Gerada:\n" << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if((i == 0) && (j == 0)) {
                cout << "[ ";
            } else if((i != 0) && (j == 0)) {
                cout << "]\n[ ";
            }

            if(m[i][j] < 10) {
                cout << "0";
                cout << m[i][j] << " ";
            } else {
                cout << m[i][j] << " ";
            }

            if((i + j) == 6) {
                cout << "]\n";
            }
        }
    }

    return 0;
}