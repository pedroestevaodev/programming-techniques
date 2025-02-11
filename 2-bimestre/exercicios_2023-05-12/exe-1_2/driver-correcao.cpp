#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    int nro;
    char nome[30], curso[30];
    double n1, n2;

    cout << "Informe os dados dos alunos: " << endl;
    cin >> nro >> nome >> curso >> n1 >> n2;

    int nro_r;
    char nome_r[30], curso_r[30];
    double n1_r, n2_r;
    int flag = 0;

    ifstream arq_r("alunos.dat", ios::in);

    while(arq_r>>nro_r>>nome_r>>curso_r>>n1_r>>n2_r)
    {
        if(nro_r == nro)
        {
            flag = 1;
            // break;
        }
    }

    arq_r.close();

    if(flag==1)
    {
        cout << "Aluno já cadastrado!" << endl;
    }
    else
    {
        ofstream arq_w("alunos.dat", ios::app);
        arq_w << nro << " " << nome << " " << curso << " " << n1 << " " << n2 << endl;
        arq_w.close();
    }

    return 0;
}