#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    int p[3][3], s[3][3], n[3][3];
    srand(time(NULL));

    cout << "\nPrimeira matriz:\n" << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            p[i][j] = (rand() % 100);

            if((i == 0) && (j == 0)) {
                cout << "[ ";
            } else if((i != 0) && (j == 0)) {
                cout << "]\n[ ";
            }

            if(p[i][j] < 10) {
                cout << "0";
                cout << p[i][j] << " ";
            } else {
                cout << p[i][j] << " ";
            }

            if((i + j) == 4) {
                cout << "]\n";
            }
        }
    }

    cout << "\nSegunda matriz:\n" << endl;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            s[i][j] = (rand() % 100);

            if((i == 0) && (j == 0)) {
                cout << "[ ";
            } else if((i != 0) && (j == 0)) {
                cout << "]\n[ ";
            }
            
            if(s[i][j] < 10) {
                cout << "0";
                cout << s[i][j] << " ";
            } else {
                cout << s[i][j] << " ";
            }
            
            if((i + j) == 4) {
                cout << "]\n";
            }
        }
    }

    cout << "\nNova matriz:\n" << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(p[i][j] > s[i][j]) {
                n[i][j] = p[i][j];
            } else {
                n[i][j] = s[i][j];
            }

            if((i == 0) && (j == 0)) {
                cout << "[ ";
            } else if((i != 0) && (j == 0)) {
                cout << "]\n[ ";
            }

            if(n[i][j] < 10) {
                cout << "0";
                cout << n[i][j] << " ";
            } else {
                cout << n[i][j] << " ";
            }

            if((i + j) == 4) {
                cout << "]\n" << endl;
            }
        }
    }
    

    return 0;
}