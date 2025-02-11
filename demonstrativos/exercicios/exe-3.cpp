#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    int m[5][5];

    cout << "Matriz gerada:\n" << endl;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == j) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }

            if((i == 0) && (j == 0)) {
                cout << "[ ";
            } else if((i != 0) && (j == 0)) {
                cout << "]\n[ ";
            }

            cout << m[i][j] << " ";

            if((i + j) == 8) {
                cout << "]\n\n";
            }
        }
    }

    return 0;
}