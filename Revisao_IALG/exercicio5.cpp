/*
5. Implemente um programa que contém uma função que recebe um vetor e devolve um novo vetor, só que com os elementos em ordem inversa.
Ex. de entrada:    1 4 5 9 12 3 0 99
Ex. de saída:      99 0 3 12 9 5 4 1
*/

#include <iostream>
#include <cstring>
using namespace std;

void alocacao(int vetor[], int capacidade)
{
    int *auxVetor = new int[capacidade + 4];
    copy(vetor, vetor + 4, auxVetor);
    delete[] vetor;
    vetor = auxVetor;
}

int main()
{
    int *vetor;
    int tamanho = 0;
    int capacidade = 1;
    vetor = new int[capacidade];
    int numero = 0;
    cin >> numero;
    while (numero != -1)
    {
        if (tamanho == 0)
        {
            vetor[0] = numero;
            cout << vetor[0] << " ";
            tamanho ++;
        }
        else
        {
            if (tamanho == capacidade)
            {
                alocacao(vetor, capacidade);
                capacidade += 4;
            }
            vetor[tamanho] = numero;
            tamanho++;
        }
        cin >> numero;
    }

    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << " ";
    }

    return 0;
}
