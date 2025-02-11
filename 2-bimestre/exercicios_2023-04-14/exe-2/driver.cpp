#include <iostream>
using namespace std;

void somaVetor(int *vetA, int *vetB, int t_vetor) {
    for (int i = 0; i < t_vetor; i++)
    {
        cout << "Valor vetorA: " << *(vetA+i) << " | Valor vetorB: " << *(vetB+i) << " | Valor da soma no vetorA: " << (*(vetA+i)=*(vetA+i)+*(vetB+i)) << endl;
    }
}

int main()
{
    int t_vetor = 5;
    int vetA[t_vetor] = {1, 2, 3, 4, 5};
    int vetB[t_vetor] = {5, 4, 3, 2, 1};

    somaVetor(vetA,vetB,t_vetor);

    return 0;
}