/*
Dadas duas filas F1 e F2, implemente o método que remove os elementos de F2, presentes em F1. F1 deve estar disponível após a remoção dos elementos de F2
para outras operações. As propriedades de fila devem ser estritamente respeitadas, ou seja: não é permitido o acesso aleatório aos elementos da fila.A fila
deve ser implementada utilizando encadeamento.

Entradas:

    Número de elementos a serem inseridos em F1.
    Elementos de F1 em ordem de inserção (inserção no fim da fila).
    Número de elementos a serem inseridos em F2.
    Elementos de F2 em ordem de inserção (inserção no fim da fila).

Saídas:

    Elementos restantes em F1 após a remoção.

Exemplo de Entrada:

11

4 6 9 10 1 9 2 13 7 3 5

4

9 2 7 3

Exemplo de Saída:

4 6 10 1 13 5
*/

#include <iostream>
using namespace std;

class Noh
{
    friend class Fila;
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

class Fila
{
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;
    public:
        Fila();
        void inserir(int d);
        int desenfileirar();
        int espiar();
        void comparacao(Fila& fila2, int comeco);
        Noh* getFim();
        int getTamanho();
};

Fila::Fila()
{
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

void Fila::inserir(int d)
{
    Noh* novo = new Noh(d);
    if (tamanho == 0)
    {
        inicio = novo;
    }
    else
    {
        fim->proximo = novo;
    }
    fim = novo;
    tamanho++;
}

int Fila::desenfileirar()
{
    int dado = inicio->dado;
    Noh* temp = inicio;
    inicio = inicio->proximo;
    delete temp;
    tamanho--;
    if (tamanho == 0)
    {
        fim = NULL;
    }
    return dado;
}

int Fila::espiar()
{
    return inicio->dado;
}

int Fila::getTamanho()
{
    return tamanho;
}

Noh* Fila::getFim()
{
    return fim;
}

void Fila::comparacao(Fila& fila2, int comeco)
{
    if (fila2.getFim() != NULL)
    {
        int tam = getTamanho();
        for (int i=0; i<tam; i++)
        {
            int retirado = desenfileirar();
            if (retirado != fila2.espiar())
            {
                inserir(retirado);
            }
        }
        fila2.desenfileirar();
        comparacao(fila2, comeco);
    }
}

int main()
{
    Fila fila1;
    int tam1;
    cin >> tam1;
    int num;
    for (int i=0; i<tam1; i++)
    {
        cin >> num;
        fila1.inserir(num);
    }

    Fila fila2;
    int tam2;
    cin >> tam2;
    for (int i=0; i<tam2; i++)
    {
        cin >> num;
        fila2.inserir(num);
    }

    int comeco =  0;
    fila1.comparacao(fila2, comeco);

    const int tam = fila1.getTamanho();
    for (int i=0; i<tam; i++)
    {
        cout << fila1.desenfileirar() << " ";
    }
    
    return 0;
}