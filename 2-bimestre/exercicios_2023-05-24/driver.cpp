#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Vendedor
{
    unsigned int codigo_vendedor;
    string nome_vendedor;
    double valor_venda;
    unsigned int mes;
};

typedef Vendedor Vendedor;

void cadastrarVendedor(Vendedor* vendedores, unsigned int& contador)
{
    cout << "==========================================" << endl;
    cout << "===         CADASTRAR VENDEDOR         ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "Codigo do vendedor [" << contador+1 << "] " << endl;
    vendedores[contador].codigo_vendedor = contador+1;
    cout << endl;

    cout << "Digite o nome do vendedor: " << endl;
    cout << "- ";
    getline(cin, vendedores[contador].nome_vendedor);
    cout << endl;

    cout << "Digite o valor da venda: " << endl;
    cout << "- ";
    cin >> vendedores[contador].valor_venda;
    cin.ignore();
    cout << endl;

    cout << "Digite o mes da venda: " << endl;
    cout << "- ";
    cin >> vendedores[contador].mes;
    cin.ignore();
    cout << endl;

    ofstream arquivo("VENDAS.DAT", ios::binary);
    arquivo.write((char *) &vendedores[contador], sizeof(Vendedor));
    arquivo.close();

    contador++;

    cout << "Vendedor cadastrado com sucesso!" << endl;
}

void consultarVendedor(Vendedor* vendedor)
{
    int codigo;

    cout << "==========================================" << endl;
    cout << "===         CONSULTAR VENDEDOR         ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "Digite o codigo do vendedor: " << endl;
    cout << "- ";
    cin >> codigo;
    cin.ignore();
    cout << endl;

    cout << "==========================================" << endl;
    cout << endl;

    unsigned int codigoIndex = codigo-1;

    ifstream arquivo("VENDAS.DAT", ios::binary);
    arquivo.read((char *) &vendedor[codigoIndex], sizeof(Vendedor));
    arquivo.close();

    cout << "Codigo do vendedor: " << endl;
    cout << "- " << vendedor[codigoIndex].codigo_vendedor << endl;
    cout << endl;

    cout << "Nome do vendedor: " << endl;
    cout << "- " << vendedor[codigoIndex].nome_vendedor << endl;
    cout << endl;

    cout << "Valor da venda: " << endl;
    cout << "- " << vendedor[codigoIndex].valor_venda << endl;
    cout << endl;

    cout << "Mes da venda: " << endl;
    cout << "- " << vendedor[codigoIndex].mes << endl;
    cout << endl;

    cout << "Vendedor consultado com sucesso!" << endl;

    return;
}

void editarVendaVendedor(Vendedor* vendedor)
{
    int codigo;
    double novoValor;

    cout << "==========================================" << endl;
    cout << "===         EDITAR VENDA VENDEDOR      ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "Digite o codigo do vendedor: " << endl;
    cout << "- ";
    cin >> codigo;
    cin.ignore();
    cout << endl;

    cout << "==========================================" << endl;
    cout << endl;

    unsigned int codigoIndex = codigo-1;

    cout << "Digite o novo valor da venda: " << endl;
    cout << "- ";
    cin >> novoValor;
    cin.ignore();
    cout << endl;

    vendedor[codigo-1].valor_venda = novoValor;

    ofstream arquivo("VENDAS.DAT", ios::binary);
    arquivo.write((char *) &vendedor[codigo-1], sizeof(Vendedor));
    arquivo.close();

    cout << "Venda editada com sucesso!" << endl;
}

int main()
{
    unsigned int capacidade = 10;
    unsigned int contador = 0;
    unsigned int opcao;

    Vendedor *vendedores = new Vendedor[capacidade];

    do
    {
        cout << endl;
        cout << "==========================================" << endl;
        cout << "===                MENU                ===" << endl;
        cout << "==========================================" << endl;
        cout << "1 - Cadastrar vendedor" << endl;
        cout << "2 - Consultar vendedor" << endl;
        cout << "3 - Editar vendedor" << endl;
        cout << "4 - Excluir vendedor" << endl;
        cout << "5 - Consultar vendas do vendedor" << endl;
        cout << "6 - Sair" << endl;
        cout << "==========================================" << endl;
        cout << endl;

        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        cin.ignore();
        cout << endl;

        switch (opcao)
        {
            case 1:
                if (contador == capacidade)
                {
                    Vendedor* novoVendedor = new Vendedor[capacidade * 2];

                    for (int i = 0; i < capacidade; i++)
                    {
                        novoVendedor[i] = vendedores[i];
                    }

                    delete[] vendedores;

                    vendedores = novoVendedor;

                    capacidade *= 2;
                }

                cadastrarVendedor(vendedores, contador);

                break;
            case 2:
                consultarVendedor(vendedores);
                break;
            case 3:
                editarVendaVendedor(vendedores);
                break;
            case 4:
                cout << "Excluir vendedor" << endl;
                break;
            case 5:
                cout << "Consultar vendas do vendedor" << endl;
                break;
            case 6:
                cout << "==========================================" << endl;
                cout << endl;
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente!" << endl;
                break;
        }

    } while (opcao != 6);

    return 0;
}