#include <iostream>
using namespace std;

void gerarMatriz(int **matriz, int linha, int coluna) 
{   
    srand(time(0));

    for (int i = 0; i < linha; i++)
    {
        matriz[i] = new int[coluna];
    }

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
}

void listarMatriz(int **matriz, int linha, int coluna) 
{
    int valorSoma = 0;

    cout << "Matriz: " << endl;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            cout << matriz[i][j] << " ";
            valorSoma = valorSoma + matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;

    cout << "Valor da soma dos elementos: " << endl;
    cout << valorSoma << endl;
}

void limparMatriz(int **matriz, int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        delete[] matriz[i];
    }

    delete[] matriz;
}

int main() 
{
    int linha, coluna;

    cout << "Digite o numero de linhas: ";
    cin >> linha;

    cout << "Digite o numero de colunas: ";
    cin >> coluna;

    int **matriz = new int*[linha];

    gerarMatriz(matriz, linha, coluna);

    listarMatriz(matriz, linha, coluna);

    limparMatriz(matriz, linha, coluna);

    return 0;
}