// Aluno - Pedro Estevão Paulista
// Código - 2173562
// Turma - 3/B

#include <iostream> // Biblioteca responsável pela importação do cin e cout.
#include <cmath> // Biblioteca responsável pela importação das funções cos() e sin().
using namespace std;

// Função para comverter graus para radiano, que recebe a variável graus do tipo double
double grausToRad(double graus) {
    // Retorna o grau multiplicado por PI e dividido por 180
    return graus * M_PI / 180;
}

// Função iterativa para calcular a potência de um número base elevado a um expoente, que recebe a variável base do tipo double e expoente do tipo int
double calculaPotencia(double base, int expoente) {
    // Declaração da variável resultado do tipo double que inicia com 1
    double resultado = 1.0;

    // O laço de repetição inicia em 1 e continua até que o index seja menor ou igual ao expoente
    for (int i = 1; i <= expoente; i++) {

        // Para cada repetição do laço, o resultado é multiplicado pela base
        resultado *= base;
    }

    // Retorna o resultado final
    return resultado;
}

// Função iterativa para calcular o fatorial de um número, que recebe a variável n(Número) do tipo int
double calculaFatorial(int n) {
    // Declaração da variável resultado do tipo double que inicia com 1
    double resultado = 1.0;

    // O laço de repetição inicia em 1 e continua até que o index seja menor ou igual ao número
    for (int i = 1; i <= n; i++) {
        // Para cada repetição do laço, o resultado é multiplicado pelo index
        resultado *= i;
    }

    // Retorna o resultado final
    return resultado;
}

// Função para calcular as séries de cosseno que recebe a variável expoente do tipo int e o angulo do tipo double
double seriesCosseno(int expoente, double angulo) {
    // Declaração da variável resultado do tipo double que inicia com 0
    double resultado = 0.0;

    // O laço de repetição inicia em 0 e continua até que o index seja menor ou igual ao expoente
    for (int i = 0; i <= expoente; i++) {
        // Para cada repetição do laço, o resultado é somado com o resultado da função calculaPotencia(base, expoente) multiplicado pela função calculaPotencia(base, expoente) dividido pela função calculaFatorial(número)
        resultado += calculaPotencia(-1, i) * calculaPotencia(angulo, 2 * i) / calculaFatorial(2 * i);
    }

    // Retorna o resultado final
    return resultado;
}

// Função para calcular as séries de seno que recebe a variável expoente do tipo int e o angulo do tipo double
double seriesSeno(int expoente, double angulo) {
    // Declaração da variável resultado do tipo double que inicia com 0
    double resultado = 0.0;

    // O laço de repetição inicia em 0 e continua até que o index seja menor ou igual ao expoente
    for (int i = 0; i <= expoente; i++) {
        // Para cada repetição do laço, o resultado é somado com o resultado da função calculaPotencia(base, expoente) multiplicado pela função calculaPotencia(base, expoente) dividido pela função calculaFatorial(número)
        resultado += calculaPotencia(-1, i) * calculaPotencia(angulo, 2 * i + 1) / calculaFatorial(2 * i + 1);
    }

    // Retorna o resultado final
    return resultado;
}

// Função para calcular o valor absoluto de um número, que recebe a variável valor do tipo double
double calculaAbsoluto(double valor) {
    if(valor >= 0) {
        // Caso o valor seja maior ou igual a zero, ele retorna o valor
        return valor;
    } else {
        // Senão multiplica o valor por (-1) para torna-lo positivo
        return -valor;
    }
}

// Função principal
int main() {
    // Declaração da variável angulo do tipo double que inicia vazia
    double angulo;

    // Solicita o valor do angulo em graus
    cout << endl;
    cout << "Digite o valor do angulo em graus: ";
    cin >> angulo;
    cout << endl;

    // Declaração da variável anguloRad do tipo double que recebe o valor do angulo convertido para radiano através da função grausToRad(graus)
    double anguloRad = grausToRad(angulo);

    cout << "====================================================" << endl;
    cout << endl;

    // Imprimo o valor de PI
    cout << "Valor de PI utilizado [M_PI]:" << endl;
    cout << "- " << M_PI << endl;
    cout << endl;

    // Imprimo o valor do angulo em graus digitado pelo usuário
    cout << "Angulo:" << endl;
    cout << "- " << angulo << endl;
    cout << endl;

    // Imprimo o valor do angulo em radiano
    cout << "Angulo em Radiano:" << endl;
    cout << "- " << anguloRad << endl;
    cout << endl;

    // Imprimo o valor das séries de cosseno para 3 termos
    cout << "Series de Cosseno para 3 termos:" << endl;
    cout << "- " << seriesCosseno(0, anguloRad) << endl;
    cout << endl;

    // Imprimo o valor das séries de seno para 3 termos
    cout << "Series de Seno para 3 termos:" << endl;
    cout << "- " << seriesSeno(0, anguloRad) << endl;
    cout << endl;

    // Imprimo o valor das séries de cosseno para 40 termos
    cout << "Series de Cosseno para 40 termos:" << endl;
    cout << "- " << seriesCosseno(39, anguloRad) << endl;
    cout << endl;

    // Imprimo o valor das séries de seno para 40 termos
    cout << "Series de Seno para 40 termos:" << endl;
    cout << "- " << seriesSeno(39, anguloRad) << endl;
    cout << endl;

    // Imprimo o valor de cosseno utilizando a função cmath::cos(angulo em radiano)
    cout << "Valor de Cosseno [cmath::cos()]:" << endl;
    cout << "- " << cos(anguloRad) << endl;
    cout << endl;

    // Imprimo o valor de seno utilizando a função cmath::sin(angulo em radiano)
    cout << "Valor de Seno [cmath::sen()]:" << endl;
    cout << "- " << sin(anguloRad) << endl;
    cout << endl;

    // Declaração das variáveis erroCosseno3, erroSeno3, erroCosseno40 e erroSeno40 do tipo double que recebem o valor absoluto da diferença entre o valor das séries e o valor das funções cmath::cos(angulo em radiano) e cmath::sin(angulo em radiano) através da função calculaAbsoluto(valor)
    double erroCosseno3 = calculaAbsoluto(cos(anguloRad) - seriesCosseno(2, anguloRad));
    double erroSeno3 = calculaAbsoluto(sin(anguloRad) - seriesSeno(2, anguloRad));
    double erroCosseno40 = calculaAbsoluto(cos(anguloRad) - seriesCosseno(39, anguloRad));
    double erroSeno40 = calculaAbsoluto(sin(anguloRad) - seriesSeno(39, anguloRad));

    // Imprimo o valor do erro das séries de cosseno para 3 termos
    cout << "Erro Cosseno (3 termos): " << endl;
    cout << "- " << erroCosseno3 << " - " << erroCosseno3 / cos(anguloRad) * 100 << "%" << endl;
    cout << endl;

    // Imprimo o valor do erro das séries de seno para 3 termos
    cout << "Erro Seno (3 termos): " << endl;
    cout << "- " << erroSeno3 << " - " << erroSeno3 / sin(anguloRad) * 100 << "%" << endl;
    cout << endl;

    // Imprimo o valor do erro das séries de cosseno 40 termos
    cout << "Erro Cosseno (40 termos): " << endl;
    cout << "- " << erroCosseno40 << " - " << erroCosseno40 / cos(anguloRad) * 100 << "%" << endl;
    cout << endl;

    // Imprimo o valor do erro das séries de seno 40 termos
    cout << "Erro Seno (40 termos): " << endl;
    cout << "- " << erroSeno40 << " - " << erroSeno40 / sin(anguloRad) * 100 << "%" << endl;
    cout << endl;

    cout << "====================================================" << endl;
    cout << endl;

    return 0;
}