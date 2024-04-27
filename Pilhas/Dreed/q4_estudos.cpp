/*
Implemente um estrutura de dados do tipo pilha com as operações de empilhar e desempilhar. Adicione um método que, utilizando uma pilha auxiliar,
faça a ordenação crescente da pilha original, com o menor elemento no topo da pilha. Nenhuma outra estrutura pode ser utilizada além da pilha auxiliar.

Entradas:

    Quantidade de elementos a serem armazenados na pilha
    Elementos da pilha

Saídas:

    Elementos da pilha ordenados

Exemplo de Entrada:

10
3 8 5 10 2 0 4 11 21 7

Exemplo de Saída:

0 2 3 4 5 7 8 10 11 21

Exemplo de Entrada:

15
3 8 5 10 -2 0 14 11 21 75 6 34 -1 9 -5

Exemplo de Saída:

-5 -2 -1 0 3 5 6 8 9 10 11 14 21 34 75
*/

#include <iostream>
using namespace std;

class Noh
{
    friend class Pilha;
    private:
        int dado;
        Noh* proximo;
    public:
        Noh();
        Noh(int d);
};

Noh::Noh()
{
    dado = 0;
    proximo = NULL;
}

Noh::Noh(int d)
{
    dado = d;
    proximo = NULL;
}

class Pilha
{
    private:
        Noh* topo;
        int tamanho;
    public:
        Pilha(int tam);
        ~Pilha();
        void empilhar(int d);
        int desempilhar();
        bool vazio();
        void ordenar();
};

Pilha::Pilha(int tam)
{
    topo = NULL;
    tamanho = tam;
}

Pilha::~Pilha()
{
    while (!vazio())
    {
        desempilhar();
    }
}

bool Pilha::vazio()
{
    return topo == NULL;
}

void Pilha::empilhar(int d)
{
    Noh* novo = new Noh(d);
    novo->proximo = topo;
    topo = novo;
}

int Pilha::desempilhar()
{
    Noh* temp = topo;
    topo = topo->proximo;
    int retorno = temp->dado;
    delete temp;
    return retorno;
}

void Pilha::ordenar()
{
    Pilha pilhaAux(tamanho);
    int aux1, aux2, tam = tamanho;
    while (tam > 0)
    {
        aux1 = desempilhar();
        while (!vazio())
        {
            aux2 = desempilhar();
            if (aux1 < aux2)
            {
                pilhaAux.empilhar(aux1);
                aux1 = aux2;
            }
            else if (aux1 > aux2)
            {
                pilhaAux.empilhar(aux2);
                
            }
        }
        pilhaAux.empilhar(aux1);
        while (!pilhaAux.vazio())
        {
            empilhar(pilhaAux.desempilhar());
        }
        tam--;
    }
}

int main()
{
    int tamanho, num;
    cin >> tamanho;

    Pilha pilha(tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        cin >> num;
        pilha.empilhar(num);
    }

    pilha.ordenar();

    while (!pilha.vazio())
    {
        cout << pilha.desempilhar() << " ";
    }

    return 0;
}