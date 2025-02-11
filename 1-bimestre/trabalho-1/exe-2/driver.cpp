// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 3/B

// Definições gerais [não apresentadas em sala de aula, pelo menos até o momento de entrega do exercício]:
// 
// & - Referência a um endereço de memória (ponteiro) de uma variável. Isso significa que em vez de uma cópia da variável ser criada, um ponteiro para a variável original é criado, o que economiza memória e melhora o desempenho do programa, além de permitir que a variável original seja alterada. Documentação de referência: https://en.cppreference.com/w/cpp/language/reference
// * - Referência o valor de um endereço de memória (ponteiro) de uma variável. Isso significa que podemos acessar o valor da variável original através do ponteiro para a variável sem precisar copiar o valor da variável original para uma nova variável. Documentação de referência: https://en.cppreference.com/w/cpp/language/pointer
// new - Operador que aloca memória para um ponteiro. Isso significa que um ponteiro é criado e aponta para um endereço de memória que pode ser acessado através do operador *. O operador new também pode ser usado para criar um objeto, mas isso não é o foco desse exercício. Documentação de referência: https://en.cppreference.com/w/cpp/language/new
// tm - Struct que representa uma data e hora. Documentação de referência: https://en.cppreference.com/w/cpp/chrono/c/tm
// time_t - Tipo que representa um tempo em segundos desde 00:00:00 UTC, 1 de janeiro de 1970. É usado para representar datas e horas. Documentação de referência: https://en.cppreference.com/w/cpp/chrono/c/time_t
// localtime() - Função que converte um tempo em segundos desde 00:00:00 UTC, 1 de janeiro de 1970 para uma data e hora local. Ela recebe um ponteiro para um objeto do tipo time_t e retorna um ponteiro para um objeto do tipo tm. Documentação de referência: https://en.cppreference.com/w/cpp/chrono/c/localtime
// time() - Função que retorna o tempo em segundos desde 00:00:00 UTC, 1 de janeiro de 1970. Documentação de referência: https://en.cppreference.com/w/cpp/chrono/c/time
// put_time() - Função que formata uma data e hora para uma string. Ela recebe um ponteiro para um objeto do tipo tm e um formato de data e hora. O formato de data e hora é uma string que contém caracteres literais e especificadores de formato. Documentação de referência: https://en.cppreference.com/w/cpp/io/manip/put_time
// regex - Tipo que representa uma expressão regular. Documentação de referência: https://en.cppreference.com/w/cpp/regex
// regex_match() - Função que verifica se uma string corresponde a uma expressão regular. Ela recebe uma string e uma expressão regular. A expressão regular é uma string que contém caracteres literais e especificadores de expressão regular. Documentação de referência: https://en.cppreference.com/w/cpp/regex/match_results/regex_match
// isdigit() - Função que verifica se um caractere é um dígito numérico (0-9). Ela recebe um caractere e retorna um valor booleano. Documentação de referência: https://en.cppreference.com/w/cpp/string/byte/isdigit
// size() - Função que retorna o tamanho de uma string em valor inteiro. Documentação de referência: https://en.cppreference.com/w/cpp/string/basic_string/size
// begin() - Função que retorna um iterador para o primeiro elemento de uma string. Documentação de referência: https://en.cppreference.com/w/cpp/string/basic_string/begin
// end() - Função que retorna um iterador para o último elemento de uma string. Documentação de referência: https://en.cppreference.com/w/cpp/string/basic_string/end
// adjacent_find() - Função que verifica se há dois elementos consecutivos iguais em um intervalo de elementos. Ela recebe um iterador para o primeiro elemento do intervalo e um iterador para o último elemento do intervalo. Documentação de referência: https://en.cppreference.com/w/cpp/algorithm/adjacent_find
// not_equal_to() - Função que verifica se dois valores são diferentes e retorna um valor booleano. Documentação de referência: https://en.cppreference.com/w/cpp/utility/functional/not_equal_to
// to_string() - Função que converte um valor inteiro para uma string. Documentação de referência: https://en.cppreference.com/w/cpp/string/basic_string/to_string
// istringstream - Classe que permite a leitura de uma string como um fluxo de entrada. Documentação de referência: https://en.cppreference.com/w/cpp/io/basic_istringstream
// get_time() - Função que retorna uma string que representa a data e hora. Ela recebe um ponteiro para um objeto do tipo tm e um formato de data e hora. Documentação de referência: https://en.cppreference.com/w/cpp/io/manip/get_time
// fail() - Função que verifica se um fluxo de entrada está em um estado de falha. Documentação de referência: https://en.cppreference.com/w/cpp/io/basic_ios/fail
// bad() - Função que verifica se um fluxo de entrada está em um estado de erro. Documentação de referência: https://en.cppreference.com/w/cpp/io/basic_ios/bad
// eof() - Função que verifica se um fluxo de entrada está em um estado de fim de arquivo. Documentação de referência: https://en.cppreference.com/w/cpp/io/basic_ios/eof

#include <iostream> // Biblioteca responsável pela importação do cin e cout.
#include <string> // Biblioteca responsável pela importação do tipo string.
#include <regex> // Biblioteca responsável pela importação da função regex_match.
#include <chrono> // Biblioteca responsável pela importação do tipo time_t.
#include <iomanip> // Biblioteca responsável pela importação da função put_time.
using namespace std; 

// Declaração da struct Parcela
struct Parcela {
    // Declaração das variáveis valor do tipo double, paga do tipo booleano, dataPagamento e dataVencimento do tipo tm
    double valor;
    bool paga;
    tm dataPagamento;
    tm dataVencimento;
};

// Declaração da struct Cliente
struct Cliente {
    // Declaração das variáveis nome, cpf, endereco do tipo string, dataNascimento e dataEmprestimo do tipo tm, valorEmprestimo do tipo double, parcelas que referência a struct Parcela e numParcelas do tipo int
    string nome;
    string cpf;
    string endereco;
    tm dataNascimento;
    tm dataEmprestimo;
    double valorEmprestimo;
    struct Parcela *parcelas;
    int numParcelas;
};

// Type definition para facilitar a declaração de variáveis do tipo Cliente e Parcela
typedef struct Cliente Cliente;
typedef struct Parcela Parcela;

// Função para verificar se um CPF é válido, que recebe a variável cpf do tipo string e retorna um valor booleano
bool validaCPF(const string& cpf) {
    // Declaração da expressão regular que verifica se a string contém um CPF no formato XXX.XXX.XXX-XX
    // onde X é um dígito numérico (0-9) e o ponto e o hífen são caracteres literais (não são considerados dígitos)
    regex cpfRegex(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");
    
    // Verifico se a string está no formato esperado
    if (!regex_match(cpf, cpfRegex)) {
        // Se não estiver, retorna falso
        return false;
    }
    
    // Declaração da variável cpfNumerico do tipo string que inicia vazia
    string cpfNumerico;
    // O laço de repetição percorre a string cpf
    // Nele eu declaro a variável c do tipo char que recebe cada caractere da string cpf e percorro a mesma
    for (char c : cpf) {
        // Verifica se o caractere c é um dígito numérico (0-9)
        if (isdigit(c)) {
            // Se for, adiciona o caractere c à string cpfNumerico
            cpfNumerico += c;
        }
    }

    // Verifico se o CPF tem 11 dígitos
    if (cpfNumerico.size() != 11) {
        // Se não tiver, retorna falso
        return false;
    }

    // Verifico se todos os dígitos são iguais
    //      adjacent_find(cpfNumerico.begin(), cpfNumerico.end(), not_equal_to<int>()) verifica se há dois dígitos consecutivos diferentes na string cpfNumerico
    //      cpfNumerico.begin() é um iterador para o primeiro dígito da string
    //      cpfNumerico.end() é um iterador para o último dígito da string
    //      not_equal_to<int>() verifica se dois valores inteiros são diferentes
    if (adjacent_find(cpfNumerico.begin(), cpfNumerico.end(), not_equal_to<int>()) == cpfNumerico.end()) {
        // Se forem, retorna falso
        return false;
    }

    // Se chegou aqui, o CPF é válido, então retorna verdadeiro
    return true;
}

// Função para converter uma data do tipo string no formato dd/mm/aaaa para o tipo tm
tm converteStringParaData(const string& dateString) {
    // Declaração da variável date do tipo tm que inicia vazia
    tm date = {};

    // Declaração da variável ss do tipo istringstream que recebe a string dateString
    istringstream ss(dateString);
    // string ss = dateString;

    // Atribuição da data da variável ss para a variável date
    //     get_time() converte uma string no formato dd/mm/aaaa para o tipo tm
    ss >> get_time(&date, "%d/%m/%Y");

    // Verifico se ocorreu algum erro durante a conversão
    if (ss.fail()) {
        // Se ocorreu, imprimo uma mensagem de erro e retorno a variável date vazia
        cerr << "Falha ao analisar string de data: " << dateString << endl;
    }

    // Retorno a variável date
    return date;
}

// Função que verifica se uma data é válida, que recebe a variável date do tipo string e retorna um valor booleano
bool validaData(string date) {
    // Declaração da variável ss do tipo istringstream que recebe a string date
    istringstream ss(date);

    // Declaração das variáveis day, month e year do tipo int e delimiter do tipo char
    int day, month, year;
    char delimiter;

    // Atribuo as variáveis day, month e year da variável ss
    //    >> é o operador de extração de dados
    ss >> day >> delimiter >> month >> delimiter >> year;

    // Verifico se ocorreu algum erro durante a leitura da data
    if (ss.fail() || ss.bad() || !ss.eof()) {
        // Se ocorreu, retorna falso
        return false;
    }

    // Verifico se o separador das partes da data é diferente da barra
    if (delimiter != '/') {
        // Se for, retorna falso
        return false;
    }

    // Verifico se o dia é menor que 1 ou maior que 31
    if (day < 1 || day > 31) {
        // Se for, retorna falso
        return false;
    }

    // Verifico se o mês é menor que 1 ou maior que 12
    if (month < 1 || month > 12) {
        // Se for, retorna falso
        return false;
    }

    // Verifico se o ano é menor que 0
    if (year < 0) {
        // Se for, retorna falso
        return false;
    }

    // Se chegou aqui, a data é válida, então retorna verdadeiro
    return true;
}

// Função para obter a data atual do sistema no formato tm
tm obterDataAtual() {
    // Declaração da variável tempoAtual do tipo time_t que recebe o tempo atual do sistema em segundos
    time_t tempoAtual = time(0);

    // Declaração da variável data do tipo tm que recebe a data atual do sistema
    //     localtime() converte o tempo atual do sistema da variável tempoAtual em segundos para o tipo tm
    struct tm data = *localtime(&tempoAtual);

    // Declaração da variável dataFormatada do tipo string que recebe a data atual do sistema no formato dd/mm/aaaa
    string dataFormatada = to_string(data.tm_mday) + "/" +
                           to_string(data.tm_mon + 1) + "/" +
                           to_string(data.tm_year + 1900);

    // Retorno a variável dataFormatada convertida para o tipo tm pela função converteStringParaData()
    return converteStringParaData(dataFormatada);
}

// Função que verifica se existe um cliente com o CPF informado, que recebe a variável cliente do tipo Cliente, a variável contador do tipo int e a variável cpf do tipo string e retorna um valor booleano
bool verificaExisteCPF(Cliente* cliente, int contador, string cpf) {
    // Laço de repetição que percorre todos os clientes cadastrados através da variável contador
    for (int i = 0; i < contador; i++) {
        // Verifico se o CPF do cliente no momento da repetição do laço é igual ao CPF informado
        if (cliente[i].cpf == cpf) {
            // Se for, retorna verdadeiro e sai do laço
            return true;
            break;
        }
    }

    // Se chegou aqui, o CPF não existe, então retorna falso
    return false;
}

// Função para cadastrar um cliente, que recebe a variável clientes do tipo Cliente e a variável contador do tipo int
void cadastrarCliente(Cliente* clientes, int& contador) {
    // Declaração da variável novoCliente do tipo Cliente
    Cliente novoCliente;

    // Declaração das variáveis ano, mes e dia do tipo int
    int ano, mes, dia;
    // Declaração da variável dataNascimento do tipo tm
    tm dataNascimento;
    // Declaração das variáveis opcao e opcaoParcela do tipo char
    char opcao;
    char opcaoParcela;

    cout << "==========================================" << endl;
    cout << "===          CADASTRAR CLIENTE         ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    // Atribuição da variável novoCliente.nome com o nome do cliente
    cout << "Digite o nome do cliente: " << endl;
    cout << "- ";
    getline(cin, novoCliente.nome);
    cout << endl;

    // Atribuição da variável novoCliente.cpf com o CPF do cliente
    cout << "Digite o CPF do cliente (xxx.xxx.xxx-xx): " << endl;
    cout << "- ";
    getline(cin, novoCliente.cpf);

    // Verifico se o CPF informado é válido
    while (!validaCPF(novoCliente.cpf)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
        cout << "- ";
        getline(cin, novoCliente.cpf);
    }
    cout << endl;
    
    // Verifico se o CPF informado já existe
    if(verificaExisteCPF(clientes, contador, novoCliente.cpf)) {
        // Se existir, imprimo uma mensagem de erro e retorno da função para o menu
        cout << "CPF ja cadastrado!" << endl;
        return;
    }

    // Atribuição da variável novoCliente.endereco com o endereço do cliente
    cout << "Digite o endereco do cliente: " << endl;
    cout << "- ";
    getline(cin, novoCliente.endereco);
    cout << endl;

    cout << "Digite a data de nascimento do cliente (DD/MM/AAAA): " << endl;
    cout << "- ";
    // Declaração da variável dataNascimentoStr do tipo string que recebe a data de nascimento do cliente
    string dataNascimentoStr;
    getline(cin, dataNascimentoStr);

    // Verifico se a data de nascimento informada é válida
    while (!validaData(dataNascimentoStr)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "Data invalida! Digite novamente (DD/MM/AAAA): " << endl;
        cout << "- ";
        getline(cin, dataNascimentoStr);
    }
    cout << endl;

    // Se for, atribuo à variável novoCliente.dataNascimento a data de nascimento do cliente convertida para o tipo tm
    novoCliente.dataNascimento = converteStringParaData(dataNascimentoStr);

    // Pergunto se o cliente deseja fazer um empréstimo e atribuo a resposta para a variável opcao 
    cout << "Deseja fazer um emprestimo? (S/N): " << endl;
    cout << "- ";
    cin >> opcao;
    cin.ignore();

    // Verifico se a opção informada é válida, sendo S, s, N, ou n
    do {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente até que seja válida
        if (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n') {
            cout << "Opcao invalida! Digite novamente (S/N): " << endl;
            cout << "- ";
            cin >> opcao;
            cin.ignore();
        }
    } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');
    cout << endl;

    // Verifico se a opção informada é S ou s
    if (opcao == 'S' || opcao == 's') {
        // Se for, inicio o cadastro do empréstimo

        cout << "Digite a data do emprestimo (DD/MM/AAAA): " << endl;
        cout << "- ";
        // Declaração da variável dataEmprestimoStr do tipo string que recebe a data do empréstimo
        string dataEmprestimoStr;
        getline(cin, dataEmprestimoStr);

        // Verifico se a data do empréstimo informada é válida
        while (!validaData(dataEmprestimoStr)) {
            // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
            cout << "Data invalida! Digite novamente (DD/MM/AAAA): " << endl;
            cout << "- ";
            getline(cin, dataEmprestimoStr);
        }
        cout << endl;

        // Se for, atribuo à variável novoCliente.dataEmprestimo a data do empréstimo convertida para o tipo tm
        novoCliente.dataEmprestimo = converteStringParaData(dataEmprestimoStr);

        // Atribuição da variável novoCliente.valorEmprestimo com o valor do empréstimo
        cout << "Digite o valor total do emprestimo: " << endl;
        cout << "- ";
        cin >> novoCliente.valorEmprestimo;
        cin.ignore();

        // Verifico se o valor do empréstimo é maior que zero
        while(novoCliente.valorEmprestimo < 1) {
            // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
            cout << "Valor invalido! Digite novamente: " << endl;
            cout << "- ";
            cin >> novoCliente.valorEmprestimo;
            cin.ignore();

            // Verifico se a opção escolhida é válida, do tipo double
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                
                cout << "Valor invalido! Digite novamente: " << endl;
                cout << "- ";
                cin >> novoCliente.valorEmprestimo;
                cin.ignore();
            }
        }

        // Verifico se a opção escolhida é válida, do tipo double
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            
            cout << "Valor invalido! Digite novamente: " << endl;
            cout << "- ";
            cin >> novoCliente.valorEmprestimo;
            cin.ignore();
        }
        cout << endl;
        
        // Pergunto se o cliente deseja parcelar o empréstimo e atribuo a resposta para a variável opcaoParcela
        cout << "Deseja parcelar o emprestimo? (S/N): " << endl;
        cout << "- ";
        cin >> opcaoParcela;
        cin.ignore();

        // Verifico se a opção informada é válida, sendo S, s, N, ou n
        do {
            // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente até que seja válida
            if (opcaoParcela != 'S' && opcaoParcela != 's' && opcaoParcela != 'N' && opcaoParcela != 'n') {
                cout << "Opcao invalida! Digite novamente (S/N): " << endl;
                cout << "- ";       
                cin >> opcaoParcela;
                cin.ignore();
            }
        } while (opcaoParcela != 'S' && opcaoParcela != 's' && opcaoParcela != 'N' && opcaoParcela != 'n');
        cout << endl;

        // Verifico se o usuário deseja parcelar o empréstimo
        if (opcaoParcela == 'S' || opcaoParcela == 's') {
            // Se for, inicio o cadastro das parcelas

            // Declaração da variável qtdParcelas do tipo inteiro
            int qtdParcelas;

            // Atribuição da variável qtdParcelas com a quantidade de parcelas
            cout << "Digite a quantidade de parcelas: " << endl;
            cout << "- ";
            cin >> qtdParcelas;
            cin.ignore();

            // Verifico se a quantidade de parcelas é maior que zero e menor ou igual a 12
            while(qtdParcelas <= 0 || qtdParcelas > 12) {
                // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                cout << "Quantidade de parcelas invalida! Digite novamente: " << endl;
                cout << "- ";
                cin >> qtdParcelas;
                cin.ignore();
            }
            cout << endl;
            
            // Alocação dinâmica do vetor de parcelas
            // Atribuição da variável novoCliente.parcelas com o endereço de memória do vetor de parcelas
            novoCliente.parcelas = new Parcela[qtdParcelas];

            // Atribuição da variável novoCliente.numParcelas com a quantidade de parcelas
            novoCliente.numParcelas = qtdParcelas;

            // Laço de repetição que percorre o vetor de novoCliente.parcelas até o índice qtdParcelas - 1
            for (int i = 0; i < qtdParcelas; i++) {
                // Atribuição da variável novoCliente.parcelas[i].valor com o valor do empréstimo dividido pela quantidade de parcelas
                novoCliente.parcelas[i].valor = novoCliente.valorEmprestimo / qtdParcelas;
                // Atribuição da variável novoCliente.parcelas[i].paga com o valor false
                novoCliente.parcelas[i].paga = false;

                // Verifico se o índice é igual a zero
                if(i == 0) {
                    // Se for, atribuo à variável novoCliente.parcelas[i].dataVencimento a data do empréstimo
                    novoCliente.parcelas[i].dataVencimento = novoCliente.dataEmprestimo;
                    // Atribuo à variável novoCliente.parcelas[i].dataVencimento o valor do mês + 1
                    novoCliente.parcelas[i].dataVencimento.tm_mon += 1;
                } else {
                    // Se não for, atribuo à variável novoCliente.parcelas[i].dataVencimento o valor da data de vencimento da parcela anterior
                    novoCliente.parcelas[i].dataVencimento = novoCliente.parcelas[i-1].dataVencimento;
                    // Atribuo à variável novoCliente.parcelas[i].dataVencimento o valor do mês + 1
                    novoCliente.parcelas[i].dataVencimento.tm_mon += 1;
                }
            }
        } else {
            // Se não for, atribuo a variável novoCliente.numParcelas o valor 1
            novoCliente.numParcelas = 1;
            // Alocação dinâmica do vetor de parcelas
            novoCliente.parcelas = new Parcela[novoCliente.numParcelas];
            // Atribuição da variável novoCliente.parcelas[0].valor com o valor do empréstimo
            novoCliente.parcelas[0].valor = novoCliente.valorEmprestimo;
            // Atribuição da variável novoCliente.parcelas[0].paga com o valor false
            novoCliente.parcelas[0].paga = false;
            // Atribuição da variável novoCliente.parcelas[0].dataVencimento a data do empréstimo
            novoCliente.parcelas[0].dataVencimento = novoCliente.dataEmprestimo;
            // Atribuo à variável novoCliente.parcelas[0].dataVencimento o valor do mês + 1
            novoCliente.parcelas[0].dataVencimento.tm_mon += 1;
        }

    } else {
        // Se não for, atribuo a variável novoCliente.emprestimo o valor 0
        novoCliente.valorEmprestimo = 0;
    }

    // Atribuição da variável clientes[contador] com o valor da variável novoCliente
    clientes[contador] = novoCliente;

    // Incremento a variável contador
    contador++;

    // Imprimo uma mensagem de sucesso
    cout << "Cliente cadastrado com sucesso!" << endl;
}

// Função que realiza a busca de um cliente pelo CPF e imprime seus dados, que recebe como parâmetro um ponteiro para a estrutura Cliente e um inteiro contador
void visualizarCliente(Cliente* cliente, int contador) {
    // Declaração da variável cpfBusca do tipo string
    string cpfBusca;

    cout << "==========================================" << endl;
    cout << "===         VISUALIZAR CLIENTE         ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;
    
    // Solicito que o usuário digite o CPF do cliente
    cout << "Digite o CPF do cliente (xxx.xxx.xxx-xx): " << endl;
    cout << "- ";
    getline(cin, cpfBusca);

    // Verifico se o CPF informado é válido
    while (!validaCPF(cpfBusca)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
        cout << "- ";
        getline(cin, cpfBusca);
    }
    cout << endl;

    // Laço de repetição que percorre o vetor de clientes até o índice contador - 1
    for (int i = 0; i < contador; i++) {
        // Verifico se o CPF do cliente na posição i é igual ao CPF informado
        if (cliente[i].cpf == cpfBusca) {
            // Se for, imprimo os dados do cliente
            cout << "Nome do Cliente: " << endl;
            cout << "- " << cliente[i].nome << endl;
            cout << endl;

            cout << "CPF do Cliente: " << endl;
            cout << "- " << cliente[i].cpf << endl;
            cout << endl;

            cout << "Endereco do Cliente: " << endl;
            cout << "- " << cliente[i].endereco << endl;
            cout << endl;

            cout << "Data de nascimento do Cliente: " << endl;
            cout << "- " << put_time(&cliente[i].dataNascimento, "%d/%m/%Y") << endl;
            cout << endl;

            cout << "====================" << endl;
            cout << "==== EMPRESTIMO ====" << endl;
            cout << endl;
            
            // Verifico se o cliente possui empréstimo
            if(cliente[i].valorEmprestimo > 0) {
                // Se tiver, imprimo os dados do empréstimo
                cout << "Data do emprestimo: " << endl;
                cout << "- " << put_time(&cliente[i].dataEmprestimo, "%d/%m/%Y") << endl;
                cout << endl;

                cout << "Valor total do emprestimo: " << endl;
                cout << "- " << cliente[i].valorEmprestimo << endl;
                cout << endl;

                // Verifico se o cliente possui mais de uma parcela
                if (cliente[i].numParcelas > 0) {
                    // Se tiver, imprimo as parcelas
                    cout << "====================" << endl;
                    cout << "===== PARCELAS =====" << endl;
                    cout << endl;

                    // Laço de repetição que percorre o vetor de parcelas até o índice numParcelas - 1
                    for (int j = 0; j < cliente[i].numParcelas; j++) {
                        // Imprimo os dados da parcela
                        cout << "Parcela " << j+1 << endl;
                        cout << "- Valor: R$ " << cliente[i].parcelas[j].valor << endl;

                        // Verifico se a parcela está paga
                        if (cliente[i].parcelas[j].paga) {
                            // Se estiver, imprimo os dados da parcela com a data de pagamento
                            cout << "- Paga: " << "Sim" << endl;
                            cout << "- Data do pagamento: " << put_time(&cliente[i].parcelas[j].dataPagamento, "%d/%m/%Y") << endl;
                            cout << "- Data de vencimento: " << put_time(&cliente[i].parcelas[j].dataVencimento, "%d/%m/%Y") << endl;
                        } else {
                            // Se não estiver, imprimo os dados da parcela sem a data de pagamento
                            cout << "- Paga: " << "Nao" << endl;
                            cout << "- Data de vencimento: " << put_time(&cliente[i].parcelas[j].dataVencimento, "%d/%m/%Y") << endl;
                        }

                        if(j < cliente[i].numParcelas - 1) {
                            cout << endl;
                        }
                    }
                } else {
                    // Se não tiver, imprimo uma mensagem de erro
                    cout << "Nenhuma parcela cadastrada." << endl;
                }
            } else {
                // Se não tiver, imprimo uma mensagem de erro
                cout << "Nao ha emprestimo cadastrado." << endl;
            }

            // Retorno para o menu
            return;
        }
    }

    // Se o CPF não for encontrado, imprimo uma mensagem de erro
    cout << endl;
    cout << "Cliente nao encontrado!" << endl;
}

// Função que realiza a busca de um cliente pelo CPF e edita seus dados, que recebe como parâmetro um ponteiro para a estrutura Cliente e um inteiro contador
void editarCliente(Cliente* cliente, int contador) {
    // Declaração da variável cpfBusca do tipo string
    string cpfBusca;
    
    // Solicito que o usuário digite o CPF do cliente
    cout << "Digite o CPF do cliente que deseja editar (xxx.xxx.xxx-xx): " << endl;
    cout << "- ";
    getline(cin, cpfBusca);

    // Verifico se o CPF informado é válido
    while (!validaCPF(cpfBusca)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
        cout << "- ";
        getline(cin, cpfBusca);
    }

    // Laço de repetição que percorre o vetor de clientes até o índice contador - 1
    for (int i = 0; i < contador; i++) {
        // Verifico se o CPF do cliente na posição i é igual ao CPF informado
        if (cliente[i].cpf == cpfBusca) {
            // Se for, solicito que o usuário escolha o dado que deseja editar

            // Declaração da variável opcaoEditarCliente do tipo inteiro
            int opcaoEditarCliente;
            // Declaração da variável newDataNascimentoStr do tipo string
            string newDataNascimentoStr;

            // Laço de repetição que solicita que o usuário escolha o dado que deseja editar
            do {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "===           EDITAR CLIENTE           ===" << endl;
                cout << "==========================================" << endl;

                cout << "Escolha a opcao que deseja editar:" << endl;
                cout << "1 - Nome do cliente" << endl;
                cout << "2 - CPF do cliente" << endl;
                cout << "3 - Endereco do cliente" << endl;
                cout << "4 - Data de nascimento do cliente" << endl;
                cout << "5 - Voltar para o menu" << endl;
                cout << "==========================================" << endl;
                cout << endl;
                
                // Solicito que o usuário digite a opção
                cout << "Digite uma opcao: " << endl;
                cout << "- ";
                cin >> opcaoEditarCliente;
                cin.ignore();

                // Verifico se a opção é válida (1, 2, 3, 4 ou 5)
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    
                    cout << "Opcao invalida! Digite novamente: " << endl;
                    cout << "- ";
                    cin >> opcaoEditarCliente;
                    cin.ignore();
                }
                
                // Verifico qual opção foi escolhida
                switch (opcaoEditarCliente) {
                    // Caso a opção seja 1, solicito que o usuário digite o novo nome do cliente
                    case 1:
                        cout << endl;

                        // Atribuo o novo nome do cliente à variável cliente[i].nome
                        cout << "Digite o novo nome do cliente: " << endl;
                        cout << "- ";
                        getline(cin, cliente[i].nome);

                        // Imprimo uma mensagem de sucesso
                        cout << endl;
                        cout << "Cliente editado com sucesso!" << endl;

                        break;

                    // Caso a opção seja 2, solicito que o usuário digite o novo CPF do cliente
                    case 2:
                        cout << endl;
                        
                        // Atribuo o novo CPF do cliente à variável cliente[i].cpf
                        cout << "Digite o novo CPF do cliente (xxx.xxx.xxx-xx): " << endl;
                        cout << "- ";
                        getline(cin, cliente[i].cpf);

                        // Verifico se o CPF informado é válido
                        while (!validaCPF(cliente[i].cpf)) {
                            // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                            cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
                            cout << "- ";
                            getline(cin, cliente[i].cpf);
                        }

                        // Imprimo uma mensagem de sucesso
                        cout << endl;
                        cout << "Cliente editado com sucesso!" << endl;
                        
                        break;

                    // Caso a opção seja 3, solicito que o usuário digite o novo endereço do cliente
                    case 3:
                        cout << endl;
                        
                        // Atribuo o novo endereço do cliente à variável cliente[i].endereco
                        cout << "Digite o novo endereco do cliente: " << endl;
                        cout << "- ";
                        getline(cin, cliente[i].endereco);

                        // Imprimo uma mensagem de sucesso
                        cout << endl;
                        cout << "Cliente editado com sucesso!" << endl;
                        
                        break;
                    
                    // Caso a opção seja 4, solicito que o usuário digite a nova data de nascimento do cliente
                    case 4:
                        cout << endl;
                        
                        // Atribuo a nova data de nascimento do cliente à variável cliente[i].dataNascimento
                        cout << "Digite a nova data de nascimento do cliente (DD/MM/AAAA): " << endl;
                        cout << "- ";
                        getline(cin, newDataNascimentoStr);

                        // Verifico se a data informada é válida
                        while (!validaData(newDataNascimentoStr)) {
                            // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                            cout << "Data invalida! Digite novamente (DD/MM/AAAA): " << endl;
                            cout << "- ";
                            getline(cin, newDataNascimentoStr); 
                        }

                        // Converto a string newDataNascimentoStr para um tipo tm e atribuo à variável cliente[i].dataNascimento
                        cliente[i].dataNascimento = converteStringParaData(newDataNascimentoStr);
                        
                        // Imprimo uma mensagem de sucesso
                        cout << endl;
                        cout << "Cliente editado com sucesso!" << endl;
                        
                        break;
                    
                    // Caso a opção seja 5, retorno para o menu
                    case 5:
                        break;;

                    // Caso a opção seja inválida, imprimo uma mensagem de erro
                    default:
                        cout << "Opcao invalida! Tente novamente!" << endl;
                }
            } while (opcaoEditarCliente != 5); // Repito o laço enquanto a opção for diferente de 7
            
            // Retorno para o menu
            return;
        }
    }

    // Se o CPF não for encontrado, imprimo uma mensagem de erro
    cout << endl;
    cout << "Cliente nao encontrado!" << endl;
}

// Função que realiza o cadastro de um pagamento de parcela, que recebe como parâmetro um ponteiro para a estrutura Cliente e um inteiro contador
void cadastrarPagamentoParcela(Cliente* cliente, int contador) {
    // Declaração da variável cpfBusca do tipo string
    string cpfBusca;

    // Solicito que o usuário digite o CPF do cliente
    cout << "Digite o CPF do cliente (xxx.xxx.xxx-xx): " << endl;
    cout << "- ";
    getline(cin, cpfBusca);

    // Verifico se o CPF informado é válido
    while (!validaCPF(cpfBusca)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
        cout << "- ";
        getline(cin, cpfBusca);
    }

    // Laço de repetição que percorre o vetor de clientes até o índice contador - 1
    for (int i = 0; i < contador; i++) {
        // Verifico se o CPF do cliente na posição i é igual ao CPF informado, e se ele possui um empréstimo
        if (cliente[i].cpf == cpfBusca) {
            // Se for, solicito que o usuário digite o número da parcela que deseja pagar

            // Verifico se o cliente possui um empréstimo
            if(cliente[i].valorEmprestimo < 1) {
                // Se não tiver, imprimo uma mensagem de erro
                cout << endl;
                cout << "Cliente nao possui emprestimo!" << endl;

                // Retorno para o menu
                return;
            }

            // Declaração da variável opcaoPagarParcela do tipo inteiro
            int opcaoPagarParcela;

            // Laço de repetição que solicita que o usuário escolha uma opção
            do {
                // Imprimo as opções
                cout << endl;
                cout << "==========================================" << endl;
                cout << "===           PAGAR PARCELA            ===" << endl;
                cout << "==========================================" << endl;

                cout << "Escolha uma opcao:" << endl;
                cout << "1 - Pagar parcela" << endl;
                cout << "2 - Visualizar parcelas" << endl;
                cout << "3 - Voltar para o menu" << endl;
                cout << "==========================================" << endl;
                cout << endl;

                // Solicito que o usuário digite a opção
                cout << "Digite uma opcao: " << endl;
                cout << "- ";
                cin >> opcaoPagarParcela;
                cin.ignore();

                // Verifico se a opção digitada é válida, do tipo int
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    
                    cout << "Opcao invalida! Digite novamente: " << endl;
                    cout << "- ";
                    cin >> opcaoPagarParcela;
                    cin.ignore();
                }

                // Verifico qual opção foi escolhida
                switch (opcaoPagarParcela) {
                    // Caso a opção seja 1, solicito que o usuário digite o número da parcela que deseja pagar
                    case 1:
                        cout << endl;

                        // Declaração da variável numeroParcela do tipo inteiro
                        int numeroParcela;

                        // Solicito que o usuário digite o número da parcela que deseja pagar
                        cout << "Informe o numero da parcela que deseja pagar: " << endl;
                        cout << "- ";
                        cin >> numeroParcela;
                        cin.ignore();
                        cout << endl;

                        // Verifico se o número da parcela informado é válido (se é menor ou igual a zero ou maior que 12)
                        while(numeroParcela < 1 || numeroParcela > 12) {
                            // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                            cout << "Numero de parcela invalido!" << endl;
                            cout << "Informe o numero da parcela que deseja pagar: " << endl;
                            cout << "- ";
                            cin >> numeroParcela;
                            cin.ignore();
                            cout << endl;

                            // Verifico se a opção escolhida é válida, do tipo int
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore();
                                
                                cout << "Opcao invalida! Digite novamente: " << endl;
                                cout << "- ";
                                cin >> numeroParcela;
                                cin.ignore();
                                cout << endl;
                            }
                        }

                        // Verifico se a opção escolhida é válida, do tipo int
                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore();
                            
                            cout << "Opcao invalida! Digite novamente: " << endl;
                            cout << "- ";
                            cin >> numeroParcela;
                            cin.ignore();
                            cout << endl;
                        }

                        // Verifico se a parcela já foi paga
                        if(cliente[i].parcelas[numeroParcela - 1].paga) {
                            // Se já foi paga, imprimo uma mensagem de erro
                            cout << "Esta parcela ja foi paga!" << endl;
                            cout << endl;

                            // Retorno para o menu
                            break;
                        }

                        // Se a parcela não foi paga, atribuo true à variável cliente[i].parcelas[numeroParcela - 1].paga
                        cliente[i].parcelas[numeroParcela - 1].paga = true;
                        // Atribuo a data atual à variável cliente[i].parcelas[numeroParcela - 1].dataPagamento através da função obterDataAtual()
                        cliente[i].parcelas[numeroParcela - 1].dataPagamento = obterDataAtual();

                        // Imprimo uma mensagem de sucesso
                        cout << "Pagamento da parcela realizado com sucesso!" << endl;

                        break;

                    // Caso a opção seja 2, imprimo as parcelas do cliente
                    case 2:
                        cout << endl;
                        cout << "==========================================" << endl;
                        cout << endl;

                        // Laço de repetição que percorre o vetor de parcelas do cliente até o índice cliente[i].numParcelas - 1
                        for (int j = 0; j < cliente[i].numParcelas; j++) {
                            // Imprimo as informações da parcela
                            cout << "Parcela " << j+1 << endl;
                            cout << "- Valor: R$ " << cliente[i].parcelas[j].valor << endl;

                            // Verifico se a parcela já foi paga
                            if (cliente[i].parcelas[j].paga) {
                                // Se já foi paga, imprimo a informação de pagamento
                                cout << "- Paga: " << "Sim" << endl;
                                cout << "- Data do pagamento: " << put_time(&cliente[i].parcelas[j].dataPagamento, "%d/%m/%Y") << endl;
                                cout << "- Data de vencimento: " << put_time(&cliente[i].parcelas[j].dataVencimento, "%d/%m/%Y") << endl;
                            } else {
                                // Se não foi paga, não imprimo a informação de pagamento
                                cout << "- Paga: " << "Nao" << endl;
                                cout << "- Data de vencimento: " << put_time(&cliente[i].parcelas[j].dataVencimento, "%d/%m/%Y") << endl;
                            }
                            
                            if(j < cliente[i].numParcelas - 1) {
                                cout << endl;
                            }
                        }

                        cout << endl;
                        cout << "==========================================" << endl;

                        break;

                    // Caso a opção seja 3, retorno para o menu
                    case 3:
                        break;

                    // Caso a opção seja diferente de 1, 2 ou 3, imprimo uma mensagem de erro
                    default:
                        cout << "Opcao invalida! Tente novamente!" << endl;
                }
            } while (opcaoPagarParcela != 3); // Enquanto a opção escolhida for diferente de 3, o laço de repetição continua

            // Retorno para o menu
            return;
        }
    }

    // Se o CPF não for encontrado, imprimo uma mensagem de erro
    cout << endl;
    cout << "Cliente nao encontrado!" << endl;
}

// Função que realiza o cadastro de um empréstimo, recebendo como parâmetro o vetor de clientes e o contador de clientes
void cadastrarEmprestimo(Cliente* cliente, int contador) {
    // Declaração da variável cpfBusca do tipo string
    string cpfBusca;

    // Solicito que o usuário digite o CPF do cliente
    cout << "Digite o CPF do cliente (xxx.xxx.xxx-xx): " << endl;
    cout << "- ";
    getline(cin, cpfBusca);

    // Verifico se o CPF é válido
    while (!validaCPF(cpfBusca)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
        cout << "- ";
        getline(cin, cpfBusca);
    }
    cout << endl;

    // Laço de repetição que percorre o vetor de clientes até o índice contador - 1
    for (int i = 0; i < contador; i++) {
        // Verifico se o CPF digitado é igual ao CPF do cliente no índice i
        if (cliente[i].cpf == cpfBusca) {
            // Se for, verifico se o cliente já possui um empréstimo em vigência

            // Declaração da variável opcaoParcela do tipo char
            char opcaoParcela;

            // Verifico se o cliente já possui um empréstimo em vigência
            if(cliente[i].valorEmprestimo > 0) {
                // Se já possui, imprimo uma mensagem de erro e apresento o menu de opções

                // Declaração da variável opcaoVerEmprestimo do tipo int
                int opcaoVerEmprestimo;
                
                cout << "Ja existe um emprestimo em vigencia para este cliente." << endl;

                // Laço de repetição que apresenta o menu de opções
                do {
                    cout << endl;
                    cout << "==========================================" << endl;
                    cout << "===        GERENCIAR EMPRESTIMO        ===" << endl;
                    cout << "==========================================" << endl;
                    cout << "Escolha uma opcao: " << endl;
                    cout << "1 - Ver emprestimo" << endl;
                    cout << "2 - Voltar para o menu" << endl;
                    cout << "==========================================" << endl;
                    cout << endl;

                    // Solicito que o usuário digite a opção desejada
                    cout << "Digite uma opcao: " << endl;
                    cout << "- ";
                    cin >> opcaoVerEmprestimo;
                    cin.ignore();

                    // Verifico se a opção digitada é válida, do tipo int
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        
                        cout << "Opcao invalida! Digite novamente: " << endl;
                        cout << "- ";
                        cin >> opcaoVerEmprestimo;
                        cin.ignore();
                    }

                    // Verifico qual opção foi escolhida
                    switch (opcaoVerEmprestimo)
                    {   
                        // Caso a opção seja 1, imprimo as informações do empréstimo
                        case 1:
                            cout << endl;
                            cout << "==========================================" << endl;
                            cout << endl;
                            cout << "Valor do emprestimo: R$ " << cliente[i].valorEmprestimo << endl;
                            cout << "Data do emprestimo: " << put_time(&cliente[i].dataEmprestimo, "%d/%m/%Y") << endl;
                            cout << "Total de parcelas: " << cliente[i].numParcelas << endl;
                            cout << endl;

                            // Laço de repetição que percorre o vetor de parcelas do cliente até o índice cliente[i].numParcelas - 1
                            for (int j = 0; j < cliente[i].numParcelas; j++) {
                                // Imprimo as informações da parcela
                                cout << "Parcela " << j+1 << ":" << endl;
                                cout << "- Valor: " << cliente[i].parcelas[j].valor << endl;

                                // Verifico se a parcela já foi paga
                                if (cliente[i].parcelas[j].paga) {
                                    // Se já foi paga, imprimo a informação de pagamento
                                    cout << "- Paga: " << "Sim" << endl;
                                    cout << "- Data do pagamento: " << put_time(&cliente[i].parcelas[j].dataPagamento, "%d/%m/%Y") << endl;
                                    cout << "- Data de vencimento: " << put_time(&cliente[i].parcelas[j].dataVencimento, "%d/%m/%Y") << endl;
                                } else {
                                    // Se não foi paga, não imprimo a informação de pagamento
                                    cout << "- Paga: " << "Nao" << endl;
                                    cout << "- Data de vencimento: " << put_time(&cliente[i].parcelas[j].dataVencimento, "%d/%m/%Y") << endl;
                                }

                                // if(j < cliente[i].numParcelas - 1) {
                                    cout << endl;
                                // }
                            }

                            // cout << endl;
                            cout << "==========================================" << endl;

                            // Retorno para o menu
                            return;

                        // Caso a opção seja 2, retorno para o menu
                        case 2:
                            break;

                        // Caso a opção seja diferente de 1 ou 2, imprimo uma mensagem de erro
                        default:
                            cout << "Opcao invalida! Tente novamente!" << endl;
                    }
                } while(opcaoVerEmprestimo != 2); // Enquanto a opção escolhida for diferente de 2, o laço de repetição continua

                // Retorno para o menu
                return;
            }
            
            cout << "Digite a data do emprestimo (DD/MM/AAAA): " << endl;
            cout << "- ";
            // Declaração da variável dataEmprestimoStr do tipo string
            string dataEmprestimoStr;
            // Solicito que o usuário digite a data do empréstimo
            getline(cin, dataEmprestimoStr);

            // Verifico se a data é válida
            while (!validaData(dataEmprestimoStr)) {
                // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                cout << "Data invalida! Digite novamente (DD/MM/AAAA): " << endl;
                cout << "- ";
                getline(cin, dataEmprestimoStr);
            }
            cout << endl;

            // Atribuo a data do empréstimo ao cliente[i].dataEmprestimo convertendo a string para data com a função converteStringParaData(data)
            cliente[i].dataEmprestimo = converteStringParaData(dataEmprestimoStr);

            // Atribuo o valor do empréstimo ao cliente[i].valorEmprestimo
            cout << "Digite o valor total do emprestimo: " << endl;
            cout << "- ";
            cin >> cliente[i].valorEmprestimo;
            cin.ignore();

            // Verifico se o valor do empréstimo é maior que zero
            while(cliente[i].valorEmprestimo < 1) {
                // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                cout << "Valor invalido! Digite novamente: " << endl;
                cout << "- ";
                cin >> cliente[i].valorEmprestimo;
                cin.ignore();

                // Verifico se a opção escolhida é válida, do tipo double
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    
                    cout << "Valor invalido! Digite novamente: " << endl;
                    cout << "- ";
                    cin >> cliente[i].valorEmprestimo;
                    cin.ignore();
                }
            }

            // Verifico se a opção escolhida é válida, do tipo double
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                
                cout << "Valor invalido! Digite novamente: " << endl;
                cout << "- ";
                cin >> cliente[i].valorEmprestimo;
                cin.ignore();
            }
            cout << endl;
            
            // Pergunto se o cliente deseja parcelar o empréstimo e atribuo a resposta para a variável opcaoParcela
            cout << "Deseja parcelar o emprestimo? (S/N): " << endl;
            cout << "- ";
            cin >> opcaoParcela;
            cin.ignore();

            // Verifico se a opção é válida, sendo S, s, N ou n
            do {
                // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                if (opcaoParcela != 'S' && opcaoParcela != 's' && opcaoParcela != 'N' && opcaoParcela != 'n') {
                    cout << "Opcao invalida! Digite novamente (S/N): ";
                    cin >> opcaoParcela;
                    cin.ignore();
                }
            } while (opcaoParcela != 'S' && opcaoParcela != 's' && opcaoParcela != 'N' && opcaoParcela != 'n');
            cout << endl;

            // Verifico se o usuário deseja parcelar o empréstimo
            if (opcaoParcela == 'S' || opcaoParcela == 's') {
                // Se for, inicio o cadastro das parcelas

                // Declaração da variável qtdParcelas do tipo int
                int qtdParcelas;

                // Solicito que o usuário digite a quantidade de parcelas
                cout << "Digite a quantidade de parcelas: " << endl;
                cout << "- ";
                cin >> qtdParcelas;
                cin.ignore();

                // Verifico se a quantidade de parcelas é válida
                while(qtdParcelas <= 0 || qtdParcelas > 12) {
                    // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
                    cout << "Quantidade de parcelas invalida! Digite novamente: " << endl;
                    cout << "- ";
                    cin >> qtdParcelas;
                    cin.ignore();
                }
                cout << endl;
                
                // Aloco o vetor de parcelas do cliente[i] com a quantidade de parcelas
                cliente[i].parcelas = new Parcela[qtdParcelas];
                // Atribuo a quantidade de parcelas ao cliente[i].numParcelas
                cliente[i].numParcelas = qtdParcelas;

                // Laço de repetição para preencher as informações das parcelas do cliente[i] com a quantidade de parcelas
                for (int j = 0; j < qtdParcelas; j++) {
                    // Atribuo o valor da parcela ao cliente[i].parcelas[j].valor dividindo o valor do empréstimo pelo número de parcelas
                    cliente[i].parcelas[j].valor = cliente[i].valorEmprestimo / qtdParcelas;
                    // Atribuo o valor de paga ao cliente[i].parcelas[j].paga como false
                    cliente[i].parcelas[j].paga = false;

                    // Verifico se é a primeira parcela
                    if(j == 0) {
                        // Se for, atribuo a data do empréstimo ao cliente[i].parcelas[j].dataVencimento
                        cliente[i].parcelas[j].dataVencimento = cliente[i].dataEmprestimo;
                        // Atribuo +1 ao mês da data de vencimento da parcela
                        cliente[i].parcelas[j].dataVencimento.tm_mon += 1;
                    } else {
                        // Se não for, atribuo a data de vencimento da parcela anterior ao cliente[i].parcelas[j].dataVencimento
                        cliente[i].parcelas[j].dataVencimento = cliente[i].parcelas[j-1].dataVencimento;
                        // Atribuo +1 ao mês da data de vencimento da parcela
                        cliente[i].parcelas[j].dataVencimento.tm_mon += 1;
                    }
                }
            } else {
                // Se o usuário não deseja parcelar o empréstimo, atribuo 1 ao cliente[i].numParcelas
                cliente[i].numParcelas = 1;
                // Aloco o vetor de parcelas do cliente[i] com a quantidade de parcelas
                cliente[i].parcelas = new Parcela[cliente[i].numParcelas];
                // Atribuo o valor do empréstimo ao cliente[i].parcelas[0].valor
                cliente[i].parcelas[0].valor = cliente[i].valorEmprestimo;
                // Atribuo o valor de paga ao cliente[i].parcelas[0].paga como false
                cliente[i].parcelas[0].paga = false;
                // Atribuo a data do empréstimo ao cliente[i].parcelas[0].dataVencimento
                cliente[i].parcelas[0].dataVencimento = cliente[i].dataEmprestimo;
                // Atribuo +1 ao mês da data de vencimento da parcela
                cliente[i].parcelas[0].dataVencimento.tm_mon += 1;
            }

            // Imprimo uma mensagem de sucesso
            cout << "Emprestimo cadastrado com sucesso." << endl;

            // Retorno para o menu
            return;
        }
    }

    // Se o CPF não for encontrado, imprimo uma mensagem de erro
    cout << "Cliente nao encontrado!" << endl;
}

// Função para excluir um cliente, que recebe um vetor de clientes e o contador do tipo inteiro
void excluirCliente(Cliente* clientes, int& contador) {
    // Declaração da variável cpfBusca do tipo string
    string cpfBusca;

    cout << "==========================================" << endl;
    cout << "===          EXCLUIR CLIENTE           ===" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    // Solicito que o usuário digite o CPF do cliente a ser excluído
    cout << "Digite o CPF do cliente a ser deletado (xxx.xxx.xxx-xx): " << endl;
    cout << "- ";
    getline(cin, cpfBusca);

    // Verifico se o CPF é válido
    while (!validaCPF(cpfBusca)) {
        // Se não for, imprimo uma mensagem de erro e solicito que o usuário digite novamente
        cout << "CPF invalido! Digite novamente (xxx.xxx.xxx-xx): " << endl;
        cout << "- ";
        getline(cin, cpfBusca);
    }
    cout << endl;

    // Laço de repetição para percorrer o vetor de clientes
    for (int i = 0; i < contador; i++) {
        // Verifico se o CPF do cliente é igual ao CPF digitado pelo usuário
        if (clientes[i].cpf == cpfBusca) {
            // Se for, excluo o cliente[i] do vetor de clientes
            for(int j = i; j < contador - 1; j++) {
                clientes[j] = clientes[j + 1];
            }

            // Decremento o contador
            contador--;

            // Imprimo uma mensagem de sucesso
            cout << "Cliente excluido com sucesso!" << endl;
            
            // Retorno para o menu
            return;
        }
    }

    // Se o CPF não for encontrado, imprimo uma mensagem de erro
    cout << "Cliente nao encontrado!" << endl;
}

// Função principal
int main() {
    // Declaração das variáveis capacidade, contador e opcao do tipo inteiro
    int capacidade = 10;
    int contador = 0;
    int opcao;

    // Aloco o vetor de clientes com a capacidade inicial
    struct Cliente* clientes = new Cliente[capacidade];
    
    // Laço de repetição para exibir o menu
    do {
        cout << endl;
        cout << "==========================================" << endl;
        cout << "===                MENU                ===" << endl;
        cout << "==========================================" << endl;
        cout << "1 - Cadastrar cliente" << endl;
        cout << "2 - Visualizar informacoes de um cliente" << endl;
        cout << "3 - Editar informacoes de um cliente" << endl;
        cout << "4 - Cadastrar pagamento de parcela" << endl;
        cout << "5 - Cadastrar emprestimo" << endl;
        cout << "6 - Excluir cliente" << endl;
        cout << "7 - Sair" << endl;
        cout << "==========================================" << endl;
        cout << endl;

        // Solicito que o usuário digite uma opção
        cout << "Digite uma opcao: " << endl;
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

        // Verifico qual opção foi digitada
        switch (opcao) {
            // Se a opção for 1, chamo a função cadastrarCliente
            case 1:
                // Verifico se o vetor de clientes está cheio
                if (contador == capacidade) {
                    // Aloco um novo vetor com a capacidade dobrada
                    Cliente* novoVetor = new Cliente[capacidade * 2];

                    // Copio os clientes do vetor antigo para o novo vetor
                    for (int i = 0; i < capacidade; i++) {
                        // Atribuo o cliente[i] ao novoVetor[i]
                        novoVetor[i] = clientes[i];
                    }

                    // Libero a memória do vetor antigo
                    delete[] clientes;

                    // Atribuo o novo vetor ao vetor de clientes
                    clientes = novoVetor;

                    // Dobro o valor da variavel capacidade
                    capacidade *= 2;
                }

                // Chamo a função cadastrarCliente
                cadastrarCliente(clientes, contador);
                break;

            // Se a opção for 2, chamo a função visualizarCliente
            case 2:
                visualizarCliente(clientes, contador);
                break;

            // Se a opção for 3, chamo a função editarCliente
            case 3:
                editarCliente(clientes, contador);
                break;

            // Se a opção for 4, chamo a função cadastrarPagamentoParcela
            case 4:
                cadastrarPagamentoParcela(clientes, contador);
                break;

            // Se a opção for 5, chamo a função cadastrarEmprestimo
            case 5:
                cadastrarEmprestimo(clientes, contador);
                break;

            // Se a opção for 6, chamo a função excluirCliente
            case 6:
                excluirCliente(clientes, contador);
                break;

            // Se a opção for 7, imprimo uma mensagem de saída e saio do laço de repetição
            case 7:
            
                cout << "==========================================" << endl;
                cout << endl;
                cout << "Saindo..." << endl;
                break;

            // Se a opção for diferente de 1, 2, 3, 4, 5, 6 ou 7, imprimo uma mensagem de erro
            default:
                cout << "Opcao invalida. Tente novamente!" << endl;
                break;
        }
    } while (opcao != 7); // Enquanto a opção for diferente de 7, o laço de repetição continua
    
    // Finalizo o programa
    return 0;
}