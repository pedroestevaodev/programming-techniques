#include <iostream>
#include <fstream>
using namespace std;

void cadastrarAluno() {
    int nro;
    char nome[30], curso[30];
    double n1, n2;

    cout << "Informe os dados do aluno: " << endl;
    cout << "Numero: ";
    cin >> nro;
    cin.ignore();

    cout << "Nome: ";
    cin.getline(nome, 30);

    cout << "Curso: ";
    cin.getline(curso, 30);

    cout << "Nota 1: ";
    cin >> n1;

    cout << "Nota 2: ";
    cin >> n2;

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
}

void consultarAluno()
{
    int nro;
    cout << "Informe o numero do aluno: ";
    cin >> nro;

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
            break;
        }
    }

    arq_r.close();

    if(flag==1)
    {
        cout << "Aluno encontrado!" << endl;
        cout << "Numero: " << nro_r << endl;
        cout << "Nome: " << nome_r << endl;
        cout << "Curso: " << curso_r << endl;
        cout << "Nota 1: " << n1_r << endl;
        cout << "Nota 2: " << n2_r << endl;
    }
    else
    {
        cout << "Aluno não encontrado!" << endl;
    }
}

void exibirAlunos()
{
    int nro_r;
    char nome_r[30], curso_r[30];
    double n1_r, n2_r;

    ifstream arq_r("alunos.dat", ios::in);

    while(arq_r>>nro_r>>nome_r>>curso_r>>n1_r>>n2_r)
    {
        cout << "Numero: " << nro_r << endl;
        cout << "Nome: " << nome_r << endl;
        cout << "Curso: " << curso_r << endl;
        cout << "Nota 1: " << n1_r << endl;
        cout << "Nota 2: " << n2_r << endl;
        cout << endl;
    }

    arq_r.close();
}

void exibirAprovados()
{
    int nro_r;
    char nome_r[30], curso_r[30];
    double n1_r, n2_r, media_r;

    ifstream arq_r("alunos.dat", ios::in);

    while(arq_r>>nro_r>>nome_r>>curso_r>>n1_r>>n2_r)
    {
        media_r = (n1_r+n2_r)/2;
        if(media_r >= 7)
        {
            cout << "Numero: " << nro_r << endl;
            cout << "Nome: " << nome_r << endl;
            cout << "Curso: " << curso_r << endl;
            cout << "Nota 1: " << n1_r << endl;
            cout << "Nota 2: " << n2_r << endl;
            cout << endl;
        }
    }

    arq_r.close();
}

void exibirRecuperacao()
{
    int nro_r;
    char nome_r[30], curso_r[30];
    double n1_r, n2_r, media_r;

    ifstream arq_r("alunos.dat", ios::in);

    while(arq_r>>nro_r>>nome_r>>curso_r>>n1_r>>n2_r)
    {
        media_r = (n1_r+n2_r)/2;
        if(media_r >= 3 && media_r < 7)
        {
            cout << "Numero: " << nro_r << endl;
            cout << "Nome: " << nome_r << endl;
            cout << "Curso: " << curso_r << endl;
            cout << "Nota 1: " << n1_r << endl;
            cout << "Nota 2: " << n2_r << endl;
            cout << endl;
        }
    }

    arq_r.close();
}

void exibirReprovados()
{
    int nro_r;
    char nome_r[30], curso_r[30];
    double n1_r, n2_r, media_r;

    ifstream arq_r("alunos.dat", ios::in);

    while(arq_r>>nro_r>>nome_r>>curso_r>>n1_r>>n2_r)
    {
        media_r = (n1_r+n2_r)/2;
        if(media_r < 3)
        {
            cout << "Numero: " << nro_r << endl;
            cout << "Nome: " << nome_r << endl;
            cout << "Curso: " << curso_r << endl;
            cout << "Nota 1: " << n1_r << endl;
            cout << "Nota 2: " << n2_r << endl;
            cout << endl;
        }
    }

    arq_r.close();
}

int main() 
{
    int nro, opcao;
    char nome[30], curso[30];
    double n1, n2;

    do {
        cout << endl;
        cout << "==========================================" << endl;
        cout << "===                MENU                ===" << endl;
        cout << "==========================================" << endl;
        cout << "1 - Cadastrar aluno" << endl;
        cout << "2 - Consultar aluno" << endl;
        cout << "3 - Exibir alunos" << endl;
        cout << "4 - Exibir alunos aprovados" << endl;
        cout << "5 - Exibir alunos em recuperacao" << endl;
        cout << "6 - Exibir alunos reprovados" << endl;
        cout << "7 - Sair" << endl;
        cout << "==========================================" << endl;
        cout << endl;

        cout << "Informe a opcao desejada: ";
        cout << "- ";
        cin >> opcao;
        cin.ignore();

        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            
            cout << "Opcao invalida! Digite novamente: " << endl;
            cout << "- ";
            cin >> opcao;
            cin.ignore();
        }
        cout << endl;

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                consultarAluno();
                break;
            case 3:
                exibirAlunos();
                break;
            case 4:
                exibirAprovados();
                break;
            case 5:
                exibirRecuperacao();
                break;
            case 6:
                exibirReprovados();
                break;
            case 7:
                cout << "==========================================" << endl;
                cout << endl;
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente!" << endl;
                break;
        };
    } while (opcao != 7);

    return 0;
}