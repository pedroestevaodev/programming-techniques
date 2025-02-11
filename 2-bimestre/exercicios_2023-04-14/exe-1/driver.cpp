#include <iostream>
using namespace std;

void multiplicaVetor(int *vet, int t_vetor, int v_multi) {
    for (int i = 0; i < 5; i++)
    {
        cout << "Valor antes: " << *(vet+i) << " | Valor multiplicado por 8: " << (*(vet+i) * 8) << endl;
    }
}

int main()
{
    int t_vetor = 5;
    int vet[5] = {1, 2, 3, 4, 5};
    int v_multi = 8;

    multiplicaVetor(vet, t_vetor, v_multi);

    return 0;
}