/*
Faça um programa para ler vários números de um arquivo texto. A primeira linha do arquivo contém a quantidade de dados a serem lidos.
Aloque, dinamicamente, a quantidade necessária, não sendo permitido o uso de alocação na pilha, ou seja, devem ser utilizados ponteiros para esta alocação.
Cada dois números consecutivos no arquivo devem ser transformados num único número pela média dos dois. Se houver quantidade ímpar de números, o último deve
permanecer inalterado.

Depois do processamento, os valores devem ser escritos na saída padrão em ordem inversa.

O processamento e as operações de entrada/saída devem ser separados pela criação de ao menos um subprograma. Um bom planejamento dos subprogramas e das passagens
de parâmetros é parte da avaliação.

Entradas:

    O nome do arquivo com números (não terá mais que 80 caracteres, não terá espaços).
    Número inteiro representando o total de valores a serem lidos.
    Números reais contidos no arquivo.

Saídas:

    Os números reduzidos, na ordem inversa do cálculo.

Exemplo de Entrada (entrada padrão):

numeros.txt

Exemplo de Entrada (arquivo numeros.txt):

5
2.3
8.1
5.2
-1.1
3.14

Exemplo de Saída:

3.14 2.05 5.2
*/

#include <iostream>
#include <fstream>
using namespace std;

void lerArquivo(string nome, int quantidade)
{
    ifstream arquivo(nome);
    arquivo >> quantidade;

    float *resultados;

    if (quantidade % 2 == 0)
    {
        resultados = new float[quantidade/2];
        int pos = (quantidade/2) - 1;
        for (int i = 0; i < quantidade; i += 2)
        {
            float valor1, valor2;
            arquivo >> valor1 >> valor2;
            resultados[pos] = (valor1 + valor2) / 2;
            pos--;
        }
    }
    else
    {
        resultados = new float[(quantidade + 1)/2];
        int pos = ((quantidade + 1)/2) - 1;
        for (int i = 0; i < quantidade - 1; i += 2)
        {
            float valor1, valor2;
            arquivo >> valor1 >> valor2;
            resultados[pos] = (valor1 + valor2) / 2;
            pos--;
        }
        arquivo >> resultados[pos];
    }

    for (int i = 0; i < (quantidade + 1)/2; i++)
    {
        cout << resultados[i] << " ";
    }
}

int main()
{
    string nomeArquivo;
    cin >> nomeArquivo;

    int nDeValores = 0;
    lerArquivo(nomeArquivo, nDeValores);

    return 0;
}