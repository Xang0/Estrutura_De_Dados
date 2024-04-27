/*
Utilizando listas encadeadas, faça um programa que representa o processo de soma de dígitos. Por exemplo, quando você soma 347 com 594, o 4 soma com o 7,
dando 11. Fica 1 na última posição, indo 1 para somar com 9 e 4, dando 14. Fica 4 na segunda posição, e vai 1 para somar com 3 e 5, totalizando 8. E então,
você tem como resultado 841.
Computacionalmente, esse processo é realizado de uma maneira mais fácil se você usar uma lista e considerar que os números estão invertidos. Assim, crie um
programa que dada duas listas em que cada nó possui um único dígito, crie uma terceira que seja a soma das duas. As listas são dinâmicas e simplesmente encadeadas.
As listas de entrada possuem pelo menos um elemento.

Entradas:

    elementos da lista 1 (-1 indica término da lista)
    elementos da lista 2 (-1 indica término da lista)

Saídas:

    Lista 3

Exemplo de Entrada:

1 2 3 4 5 -1
6 7 8 9 -1

Exemplo de Saída:

7 9 1 4 6
*/

#include <iostream>
using namespace std;

class Noh
{
    friend class Lista;
    private:
        int dado;
        Noh* proximo;
    public:
        Noh(int dado = 0);
};

Noh::Noh(int dado)
{
    proximo = NULL;
    this->dado = dado;
}

class Lista
{
    private:
        Noh* primeiro;
        Noh* ultimo;
        int tamanho;
    public:
        Lista();
        ~Lista();
        Lista& operator=(const Lista& umaLista);
        void insere(int umDado);
        bool vazia() {return tamanho == 0;};
        void imprime();
        void remove();
        Lista& soma(Lista& umaLista);
};

Lista::Lista()
{
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

Lista::~Lista()
{
    while (tamanho > 0)
    {
        remove();
    }
}

Lista& Lista::operator=(const Lista& umaLista)
{
    Noh* aux = umaLista.primeiro;
    while(aux != NULL)
    {
        insere(aux->dado);
        aux = aux->proximo;
    }

    return *this;
}

void Lista::insere(int umDado)
{
    Noh* novo = new Noh(umDado);

    if (vazia())
    {
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

void Lista::remove()
{
    Noh* removido = primeiro;
    primeiro = primeiro->proximo;
    delete removido;
    tamanho--;
}

void Lista::imprime()
{
    Noh* aux = primeiro;
    while(aux != NULL)
    {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

Lista& Lista::soma(Lista& umaLista)
{
    Lista* resultado =  new Lista();
    Noh* aux1 = primeiro;
    Noh* aux2 = umaLista.primeiro;
    int sobrou = 0;

    if (this->tamanho >= umaLista.tamanho)
    {
        while (aux1 != NULL)
        {
            

            if (aux2 == NULL)
            {
                if (aux1->dado + sobrou> 9)
                {
                    resultado->insere(aux1->dado + sobrou - 10);
                    sobrou = 1;
                }
                else
                {
                    resultado->insere(aux1->dado + sobrou);
                    sobrou = 0;
                }
            }
            else
            {
                if (aux1->dado + aux2->dado + sobrou > 9)
                {
                    resultado->insere(aux1->dado + aux2->dado + sobrou - 10);
                    sobrou = 1;
                }
                else
                {
                    resultado->insere(aux1->dado + aux2->dado + sobrou);
                    sobrou = 0;
                }
                aux2 = aux2->proximo;
            }

            aux1 = aux1->proximo;
        }
    }
    else
    {
        while (aux2 != NULL)
        {
            if (aux1 != NULL)
            {
                if (aux2->dado + sobrou > 9)
                {
                    resultado->insere(aux2->dado + sobrou - 10);
                    sobrou = 1;
                }
                else
                {
                    resultado->insere(aux2->dado + sobrou);
                    sobrou = 0;
                }
            }
            else
            {
                if (aux1->dado + aux2->dado + sobrou > 9)
                {
                    resultado->insere(aux1->dado + aux2->dado + sobrou - 10);
                    sobrou = 1;
                }
                else
                {
                    resultado->insere(aux1->dado + aux2->dado + sobrou);
                    sobrou = 0;
                }
                aux1 = aux1->proximo;
            }

            aux2 = aux2->proximo;
        }
    }

    return *resultado;
}

int main()
{
    Lista lista1;
    Lista lista2;
    int valor;

    cin >> valor;
    while (valor != -1)
    {
        lista1.insere(valor);
        cin >> valor;
    }
    cin >> valor;
    while (valor != -1)
    {
        lista2.insere(valor);
        cin >> valor;
    }

    Lista lista3;
    lista3 = lista1.soma(lista2);
    lista3.imprime();

    return 0;
}