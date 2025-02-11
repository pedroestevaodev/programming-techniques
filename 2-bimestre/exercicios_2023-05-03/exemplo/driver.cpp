#include <iostream>
using namespace std;

int main() 
{
    int linha, coluna;

    cout << "Digite o numero de linhas: ";
    cin >> linha;

    cout << "Digite o numero de colunas: ";
    cin >> coluna;

    int **matriz = new int*[linha];

    for (int i = 0; i < linha; i++)
    {
        matriz[i] = new int[coluna];
    }

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            cout << "Digite o valor da posicao [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz: " << endl;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < linha; i++)
    {
        delete[] matriz[i];
    }

    delete[] matriz;

    return 0;
}