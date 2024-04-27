/*
Utilizando como base uma implementação de MaxHeap, implemente o heapsort. O algoritmo heapsort é um algoritmo de ordenação generalista baseado em uma
árvore heap, ou seja, ele constrói um heap a partir de um vetor desordenado para ordenar seus elementos.

O programa deve ler 15 elementos e criar um heap com eles. Depois, deve inserir mais 5 elementos no heap. Em seguida, deve escrever os elementos em ordem 
decrescente.

Entradas:

    Quinze elementos a serem inseridos no vetor.
    Cinco elementos adicionais a serem inseridos no heap construído com o vetor lido anteriormente

Saídas:

    MaxHeap construído a partir do vetor inicial, usando o método arruma()/heapify(). Essa impressão é realizada diretamente a partir do vetor de dados do heap.
    MaxHeap anterior, acrescido dos cinco elementos adicionais. Essa impressão é realizada diretamente a partir do vetor de dados do heap.
    Elementos ordenados, em ordem decrescente, por heapsort.

Exemplo de Entrada:

6 1 3 48 97 0 55 74 31 1 2 3 4 5 6
35 69 82 10 20

Exemplo de Saída:

97 74 55 48 2 4 6 6 31 1 1 3 0 5 3
97 82 55 74 20 4 6 48 69 2 1 3 0 5 3 6 35 31 10 1
97 82 74 69 55 48 35 31 20 10 6 6 5 4 3 3 2 1 1 0
*/

#include <iostream>
#include <cstring>
using namespace std;

class MaxHeap
{
    private:
        int* vetor;
        int capacidade;
        int tamanho;
        int pai(int i);
        int esquerda(int i);
        int direita(int i);
        void arruma();
        void arrumaDescendo(int i);
        void arrumaSubindo(int i);
    public:
        MaxHeap();
        ~MaxHeap();
        void insere(int vetor[]);
        void insere(int valor);
        void retira();
        void imprime(int i);
};

MaxHeap::MaxHeap()
{
    capacidade = 20;
    vetor = new int[capacidade];
    tamanho = 0;
}

MaxHeap::~MaxHeap()
{
    delete[] vetor;
}

int MaxHeap::pai(int i)
{
    return (i - 1) / 2;
}

int MaxHeap::esquerda(int i)
{
    return 2*i + 1;
}

int MaxHeap::direita(int i)
{
    return 2*i + 2;
}
void MaxHeap::arruma()
{
    for (int i = (tamanho/2)-1; i >= 0; i--)
    {
        arrumaDescendo(i);
    }
}

void MaxHeap::arrumaDescendo(int i)
{
    int esq = esquerda(i);
    int dir = direita(i);
    int maior = i;

    if ((esq < tamanho) && (vetor[esq] > vetor[maior]))
    {
        maior = esq;
    }
    if ((dir < tamanho) && (vetor[dir] > vetor[maior]))
    {
        maior = dir;
    }
    if (maior != i)
    {
        swap(vetor[i], vetor[maior]);
        arrumaDescendo(maior);
    }
}

void MaxHeap::arrumaSubindo(int i)
{
    int p = pai(i);
    if ((i > 0) && (vetor[i] > vetor[p]))
    {
        swap(vetor[i], vetor[p]);
        arrumaSubindo(p);
    }
}

void MaxHeap::insere(int vetor[])
{
    memcpy(this->vetor, vetor, sizeof(int)*15);
    tamanho = 15;
    this->arruma();
}

void MaxHeap::insere(int valor)
{
    if (tamanho < capacidade)
    {
        vetor[tamanho] = valor;
        arrumaSubindo(tamanho);
        tamanho++;
    }
}

void MaxHeap::retira()
{
    if (tamanho > 0)
    {
        int valor = vetor[0];
        swap(vetor[0], vetor[tamanho-1]);
        tamanho--;
        arrumaDescendo(0);
        cout << valor << " ";
    }
}

void MaxHeap::imprime(int i)
{
    cout << vetor[i] << " "; 
}

void heapSort(int vetor[])
{
    MaxHeap heap;
    heap.insere(vetor);
    for (int i = 0; i < 15; i++)
    {
        heap.imprime(i);
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        int valor;
        cin >> valor;
        heap.insere(valor);
    }
    for (int i = 0; i < 20; i++)
    {
        heap.imprime(i);
    }
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        heap.retira();
    }
    cout << endl;
}

int main()
{
    int array[15];
    for (int i=0; i< 15; i++)
    {
        cin >> array[i];
    }

    heapSort(array);

    return 0;
}