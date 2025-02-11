#include <iostream>
using namespace std;

struct Ponto {
    int x, y;
};

typedef struct Ponto Ponto;

void gerarPontos(Ponto *pontos, int t_vetor) {
    srand(time(0));

    for(int i = 0; i < t_vetor; i++) {
        // pontos[i].x = rand() % 100;
        (pontos + i)->x = rand() % 100;
        // pontos[i].y = rand() % 100;
        (pontos + i)->y = rand() % 100;
    }
}

void mostrarPontos(Ponto *pontos, int t_vetor) {
    for(int i = 0; i < t_vetor; i++) {
        cout << "Valor gerado para o ponto " << i+1 << ": (x: " << (pontos + i)->x << ", y: " << (pontos + i)->y << ")" << endl;
        // cout << "Valor gerado para o ponto " << i+1 << ": (x: " << pontos[i].x << ", y: " << pontos[i].y << ")" << endl;
    }
}

int main()
{
    int t_vetor = 10;
    Ponto pontos[t_vetor];

    gerarPontos(pontos, t_vetor);
    mostrarPontos(pontos, t_vetor);

    return 0;
}