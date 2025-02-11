// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 3/B

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

// Declaração da struct Flor
struct Flor 
{
    // Declaração das variáveis altura e largura do tipo double, espécie do tipo string e grupo do tipo inteiro positivo
    double altura;
    double largura;
    string especie;
    unsigned int grupo;
};

// Type definition para facilitar a declaração da struct Flor
typedef struct Flor Flor;

// Função que calcula a distância euclidiana entre dois pontos, que recebe as variáveis flor e representante do tipo Flor
double calculaDistanciaEuclidiana(const Flor& flor, const Flor& representante) 
{
    // Declaração da variável distancia do tipo double
    double distancia = pow(flor.altura - representante.altura, 2) + pow(flor.largura - representante.largura, 2);
    // Retorna a raiz quadrada da variável distancia
    return sqrt(distancia);
}

// Função que lê o arquivo csv, que recebe as variáveis nomeArquivo do tipo string e flores do tipo Flor
void lerArquivo(const string& nomeArquivo, Flor* flores) 
{
    // Declaração da variável arquivo do tipo ifstream, que lê o arquivo de referência
    ifstream arquivo(nomeArquivo, ios::in);
    // Declaração da variável linha do tipo string
    string linha;
    // Declaração da variável indiceFlor do tipo inteiro positivo
    unsigned int indiceFlor = 0;

    // Ignorar a primeira linha do arquivo
    getline(arquivo, linha);

    // Enquanto o arquivo não chegar ao fim, faça
    while (arquivo>>linha) 
    {
        // Declaração da variável ss do tipo stringstream
        stringstream ss(linha);
        // Declaração das variáveis altura e largura do tipo double
        double altura, largura;
        // Declaração das variáveis especie e valor do tipo string
        string especie, valor;

        // Pega o valor da primeira coluna
        getline(ss, valor, ',');
        // Converte o valor para double e atribui à variável altura
        altura = stod(valor);

        // Pega o valor da segunda coluna
        getline(ss, valor, ',');
        // Converte o valor para double e atribui à variável largura
        largura = stod(valor);

        // Pega o valor da terceira coluna
        getline(ss, especie, ',');

        // Remove as aspas da string especie
        especie.erase(remove(especie.begin(), especie.end(), '\"'), especie.end());

        // Atribui os valores das variáveis altura, largura, especie e grupo à variável flores
        flores[indiceFlor] = Flor{altura, largura, especie, 0};
        // Incrementa a variável indiceFlor
        indiceFlor++;
    }

    // Fecha o arquivo
    arquivo.close();
}

// Função que seleciona os representantes, que recebe as variáveis flores do tipo Flor, numeroFlores e numeroGrupos do tipo inteiro positivo e representantes do tipo Flor
void selecionarRepresentantes(const Flor* flores, unsigned int numeroFlores, Flor* representantes, unsigned int numeroGrupos)
{
    // Declaração usada para inicializar a semente do gerador de números aleatórios
    srand(time(0));
    // Declaração da variável indicesEscolhidos do tipo ponteiro para inteiro positivo, que aloca dinamicamente um vetor de tamanho numeroFlores
    unsigned int* indicesEscolhidos = new unsigned int[numeroFlores];

    // Laço de repetição que percorre o total de grupos da variável numeroGrupos
    for (int i = 0; i < numeroGrupos; i++)
    {
        // Declaração da variável indice do tipo inteiro positivo
        unsigned int indice;

        // Laço de repetição que percorre o total de flores da variável numeroFlores
        do 
        {
            // Atribui um número aleatório entre 0 e numeroFlores à variável indice
            indice = rand() % numeroFlores;
            
            // Declaração da variável indiceJaEscolhido do tipo booleano, que verifica se o indice já foi escolhido
            bool indiceJaEscolhido = false;

            // Laço de repetição que percorre o total de flores da variável i
            for (int j = 0; j < i; j++)
            {
                // Se o indice escolhido for igual ao indice escolhido anteriormente, atribui true à variável indiceJaEscolhido e sai do laço
                if (indicesEscolhidos[j] == indice)
                {
                    indiceJaEscolhido = true;
                    break;
                }
            }
            
            // Se o indice não tiver sido escolhido, sai do laço
            if (!indiceJaEscolhido)
            {
                break;
            }

        } while (true);

        // Atribui o indice escolhido ao vetor indicesEscolhidos
        indicesEscolhidos[i] = indice;
        // Atribui a flor escolhida ao vetor representantes
        representantes[i] = flores[indice];
    }

    // Deleta o vetor indicesEscolhidos
    delete[] indicesEscolhidos;
}

// Função que atribui a flor ao grupo, que recebe as variáveis flor do tipo Flor, representantes do tipo Flor, numeroRepresentantes e numeroGrupos do tipo inteiro positivo
void atribuirFlorAoGrupo(Flor& flor, const Flor* representantes, unsigned int numeroRepresentantes)
{
    // Declaração da variável menorDistancia do tipo double que recebe a distância euclidiana do primeiro representante e da flor
    double menorDistancia = calculaDistanciaEuclidiana(flor, representantes[0]);
    // Declaração da variável indiceMenorDistancia do tipo inteiro positivo que inicia em 0
    unsigned int indiceMenorDistancia = 0;

    // Laço de repetição que percorre o total de representantes da variável numeroRepresentantes
    for (int i = 1; i < numeroRepresentantes; i++)
    {
        // Declaração da variável distancia do tipo double que recebe a distância euclidiana da flor e do representante
        double distancia = calculaDistanciaEuclidiana(flor, representantes[i]);

        // Se a distância euclidiana for menor que a distância euclidiana do representante menor distância
        if (distancia < menorDistancia)
        {
            // Atribui a distância euclidiana à variável menorDistancia
            menorDistancia = distancia;
            // Atribui o indice do representante à variável indiceMenorDistancia
            indiceMenorDistancia = i;
        }
    }

    // Atribui o grupo ao representante de menor distância
    flor.grupo = indiceMenorDistancia + 1;
}

// Função que atualiza os representantes dos grupos, que recebe as variáveis flores e representantes do tipo Flor, numeroFlores, numeroGrupos e grupos do tipo inteiro positivo e representantes do tipo Flor
void atualizarRepresentantes(const Flor* flores, unsigned int numeroFlores, Flor* representantes, unsigned int numeroGrupos, const unsigned int* grupos)
{
    // Declaração das variáveis contadorFlores, alturasFlores e largurasFlores do tipo ponteiro para inteiro positivo e double, que aloca dinamicamente um vetor de tamanho numeroGrupos
    unsigned int* contadorFlores = new unsigned int[numeroGrupos]();
    double* alturasFlores = new double[numeroGrupos]();
    double* largurasFlores = new double[numeroGrupos]();

    // Laço de repetição que percorre o total de flores da variável numeroFlores
    for (int i = 0; i < numeroFlores; i++)
    {
        // Declaração da variável grupo do tipo inteiro positivo que recebe o grupo do representante (subtraindo 1 para ajustar o índice)
        unsigned int grupo = grupos[i] - 1;

        // Incrementa o contador de flores do grupo
        contadorFlores[grupo]++;

        // Adiciona a altura da flor atual ao acumulador de alturas do grupo
        alturasFlores[grupo] += flores[i].altura;

        // Adiciona a largura da flor atual ao acumulador de larguras do grupo
        largurasFlores[grupo] += flores[i].largura;
    }

    // Laço de repetição que percorre o total de grupos da variável numeroGrupos
    for (int i = 0; i < numeroGrupos; i++)
    {
        // Se o contador de flores do grupo for maior que 0
        if (contadorFlores[i] > 0)
        {
            // Atribui a altura e a largura média do grupo ao representante
            representantes[i].altura = alturasFlores[i] / contadorFlores[i];
            representantes[i].largura = largurasFlores[i] / contadorFlores[i];
        }
    }

    // Deleta os vetores contadorFlores, alturasFlores e largurasFlores
    delete[] contadorFlores;
    delete[] alturasFlores;
    delete[] largurasFlores;
}

// Função que inicia o processo, que recebe as variáveis flores e representantes do tipo Flor, numeroFlores, numeroGrupos e numeroRepeticao do tipo inteiro positivo
void iniciarProcesso(Flor* flores, int numeroFlores, Flor* representantes, int numeroGrupos, int numeroRepeticao)
{
    // Declaração da variável grupos do tipo inteiro positivo que aloca dinamicamente um vetor de tamanho numeroFlores
    unsigned int grupos[numeroFlores];

    // Laço de repetição que percorre o total de repetições da variável numeroRepeticao
    for (int i = 0; i < numeroRepeticao; i++)
    {
        // Laço de repetição que percorre o total de flores da variável numeroFlores
        for (int j = 0; j < numeroFlores; j++)
        {
            // Declaração da variável flor do tipo Flor que recebe a flor atual
            Flor& flor = flores[j];
            
            // Atribui o grupo à flor
            atribuirFlorAoGrupo(flor, representantes, numeroGrupos);

            // Atribui o grupo ao vetor grupos
            grupos[j] = flor.grupo;
        }

        // Atualiza os representantes dos grupos
        atualizarRepresentantes(flores, numeroFlores, representantes, numeroGrupos, grupos);
    }
}

// Função que salva as flores, que recebe as variáveis nomeArquivo do tipo string, flores do tipo Flor, numeroFlores e numeroGrupos do tipo inteiro positivo
void salvarFlores(const string& nomeArquivo, const Flor* flores, unsigned int numeroFlores, unsigned int numeroGrupos)
{
    // Declaração da variável arquivo do tipo ofstream que recebe o nome do arquivo e abre o arquivo para escrita
    ofstream arquivo(nomeArquivo, ios::out);
    
    // Escreve no arquivo o cabeçalho
    arquivo << "petal.lenght,petal.width,variety,grupo" << endl;

    // Laço de repetição que percorre o total de grupos da variável numeroGrupos
    for (int i = 0; i < numeroGrupos; i++)
    {   
        // Laço de repetição que percorre o total de flores da variável numeroFlores
        for (int j = 0; j < numeroFlores; j++)
        {
            // Se o grupo da flor atual for igual ao grupo atual
            if ((i+1) == flores[j].grupo)
            {
                // Escreve no arquivo a altura, a largura, a espécie e o grupo da flor atual
                arquivo << flores[j].altura << "," << flores[j].largura << "," << flores[j].especie << "," << flores[j].grupo << endl;
            }
        }
    }

    // Fecha o arquivo
    arquivo.close();

    // Exibe a mensagem de sucesso
    cout << "Os grupos foram gerados e salvos com sucesso no arquivo: `" << nomeArquivo << "`" << endl;
}

// Função principal
int main()
{
    // Declaração das variáveis arquivoEntrada e arquivoSaida do tipo string, que recebem os nomes dos arquivos de entrada e saída, respectivamente
    string arquivoEntrada = "iris_petalas.csv";
    string arquivoSaida = "iris_petalas_saida.csv";
    // Declaração da variável numeroFlores do tipo inteiro positivo
    const unsigned int numeroFlores = 150;
    // Declaração da variável flores do tipo Flor que aloca dinamicamente um vetor de tamanho numeroFlores
    Flor flores[numeroFlores];
    // Declaração das variáveis numeroGrupos e numeroRepeticao do tipo inteiro positivo
    unsigned int numeroGrupos, numeroRepeticao;

    // Exibe a mensagem perguntando o número de grupos
    cout << "Informe o numero de grupos: " << endl;
    cout << "- ";
    // Lê o número de grupos
    cin >> numeroGrupos;
    // Enquanto o número de grupos for menor que 2
    while (numeroGrupos < 2)
    {
        // Exibe a mensagem de erro
        cout << "O numero de grupos deve ser maior que 1. Informe novamente: " << endl;
        cout << "- ";
        // Lê o número de grupos
        cin >> numeroGrupos;
    };
    // Enquanto o número de grupos for maior que 150
    while (numeroGrupos > 150)
    {
        // Exibe a mensagem de erro
        cout << "O numero de grupos deve ser menor que 151. Informe novamente: " << endl;
        cout << "- ";
        // Lê o número de grupos
        cin >> numeroGrupos;
    };
    cout << endl;

    // Exibe a mensagem perguntando o número de repetições
    cout << "Informe a quantidade de vezes que deseja repetir o processo: " << endl;
    cout << "- ";
    // Lê o número de repetições
    cin >> numeroRepeticao;
    // Enquanto o número de repetições for menor que 1
    while (numeroRepeticao < 1)
    {
        // Exibe a mensagem de erro
        cout << "O numero de repeticoes deve ser maior que 0. Informe novamente: " << endl;
        cout << "- ";
        // Lê o número de repetições
        cin >> numeroRepeticao;
    }
    cout << endl;

    // Declaração da variável representantes do tipo Flor que aloca dinamicamente um vetor de tamanho numeroGrupos
    Flor representantes[numeroGrupos];

    // Chama a função que realiza a leitura do arquivo de referência
    lerArquivo(arquivoEntrada, flores);

    // Chama a função que seleciona os representantes
    selecionarRepresentantes(flores, numeroFlores, representantes, numeroGrupos);

    // Chama a função que inicia o processo
    iniciarProcesso(flores, numeroFlores, representantes, numeroGrupos, numeroRepeticao);

    // Chama a função que salva as flores
    salvarFlores(arquivoSaida, flores, numeroFlores, numeroGrupos);
    
    return 0;
}