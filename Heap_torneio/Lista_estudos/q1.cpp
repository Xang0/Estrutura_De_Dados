/*
Implemente uma classe MinHeap que tem um construtor que recebe um vetor de elementos. Durante a criação do MinHeap, alguns elementos deverão ser
reposicionados para que passem a ter as propriedades de um min heap. O construtor (ou método usado no construtor) deverá escrever passo a passo como
fica o armazenamento após a correção descendo de cada posição.

Note que não é para escrever os valores do heap após cada troca, os valores do heap devem ser escritos após todas as trocas (zero ou mais) realizadas
para a correção de uma posição.

Implemente a função principal que cria um heap a partir do vetor.

Entradas:

    A quantidade de elementos a serem lidos.
    Os elementos (números inteiros) a serem armazenados no heap.

Saídas:

Para cada posição a ser corrigida:

    A posição, seguida de dois pontos;
    Todos os elementos armazenados após a reorganização iniciada na posição em questão.

Note a ausência de espaço antes do dois pontos e a presença do espaço depois, como em qualquer sinal de pontuação.

Exemplo de Entrada:

6
9 8 7 5 -1 -3

Exemplo de Saída:

2: 9 8 -3 5 -1 7 
1: 9 -1 -3 5 8 7 
0: -3 -1 7 5 8 9
*/

#include <iostream>
using namespace std;

class MinHeap
{
    private:
        int* vetor;
        int capacidade;
        int esquerdo(int i);
        int direito(int i);
        void arruma();
        void corrigeDescendo(int i);
        void imprimir();
    public:
        MinHeap(int cap, int vetor[]);
};

MinHeap::MinHeap(int cap, int vet[])
{
    capacidade = cap;
    vetor = new int[capacidade];
    vetor = vet;
    arruma();
}

int MinHeap::esquerdo(int i)
{
    return 2*i + 1;
}

int MinHeap::direito(int i)
{
    return 2*i + 2;
}

void MinHeap::imprimir()
{
    for (int i = 0; i < capacidade; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void MinHeap::corrigeDescendo(int i)
{
    int esq = esquerdo(i);
    int dir = direito(i);
    int menor = i;

    if ((esq < capacidade) && (vetor[menor] > vetor[esq]))
    {
        menor = esq;
    }
    if ((dir < capacidade) && (vetor[menor] > vetor[dir]))
    {
        menor = dir;
    }
    if (menor != i)
    {
        swap(vetor[i], vetor[menor]);
        corrigeDescendo(menor);
    }
}

void MinHeap::arruma()
{
    for (int i = (capacidade/2) - 1; i >= 0; i--)
    {
        corrigeDescendo(i);
        cout << i << ": ";
        imprimir();
    }
}

int main()
{
    int tamanho;
    cin >> tamanho;
    int vetor[tamanho];

    int num = 0;
    for (int i=0; i<tamanho; i++)
    {
        cin >> num;
        vetor[i] = num;
    }

    MinHeap heap(tamanho, vetor);

    return 0;
}