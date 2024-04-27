/*
Crie um programa que seja capaz de armazenar em uma lista duplamente encadeada as ações de usuários em um programa. Cada elemento da lista deve ter um
identificador, o nome da ação, tempo para execução total e tempo já consumido de processamento. Você poderá utilizar o código fornecido como base de implementação.

Os comandos que deverão ser utilizados para execução do programa são:

    i: inserir uma nova ação no inicio da lista. O formato de entrada é: Identificador NomeAcao TempoExecução TempoConsumido
    h: inserir uma nova ação no final da lista. O formato de entrada é: Identificador NomeAcao TempoExecução TempoConsumido
    m: inserir uma nova equipe na posição informada pelo inteiro. Considere 0 como no início e imprima "Posição Inexistente!" caso não seja possível inserir na
    posição indicada. O formato de entrada é: posiçãoASerInserida Identificador NomeAcao TempoExecução TempoConsumido
    r: apagar uma determinada ação do início da lista. Caso não exista a equipe deverá imprimir Remoção em lista vazia!
    a: apagar uma determinada ação do fim da lista. Caso não exista a equipe deverá imprimir Remoção em lista vazia!
    p: imprimir lista de ações cadastradas em ordem de inserção e, em seguida, em ordem inversa. Imprimir Lista vazia! quando não tiver elemento a ser impresso.
    s: buscar por uma ação a partir de seu nome. Imprimir Nao encontrado quando a busca não obtiver sucesso.

Nota: o formato de saída das ações deve ser: (Identificador, NomeAcao, TempoExecução, TempoConsumido). Para mais instâncias de ações (comando de impressão), separar
cada uma delas por quebras de linha.

Entradas:

    Comandos detalhados no exercício

Saídas:

    Impressões detalhadas no exercício

Exemplo de Entrada e Saída misturados:

r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s empilharProcessos
Lista vazia!
i 1 limparCache 123 99
h 2 semaforoProc 32 11
m 1 3 paralelismoProc 65 23
p
(1, limparCache, 123, 99)
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
(1, limparCache, 123, 99)
s empilharProcessos
Nao encontrado
r
p
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO 
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
a
p
(3, paralelismoProc, 65, 23)
 IMPRIMINDO REVERSO 
(3, paralelismoProc, 65, 23)
f
*/

#include <iostream>
using namespace std;

struct Acao
{
    int identificador;
    string nome;
    int tempoExecucao;
    int tempoConsumido;
};

class Noh
{
    friend class Lista;
    private:
        Acao acao;
        Noh* proximo;
        Noh* anterior;
    public:
        Noh(Acao acao);
        void operator=(const Noh& umNoh);
};

Noh::Noh(Acao acao)
{
    proximo = NULL;
    anterior = NULL;
    this->acao = acao;
}

void Noh::operator=(const Noh& umNoh)
{
    acao = umNoh.acao;
    proximo = umNoh.proximo;
    anterior = umNoh.anterior;
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
        void insereInicio(Acao acao);
        void insereFim(Acao acao);
        void insereMeio(int posicao, Acao acao);
        void retiraInicio();
        void retiraFim();
        void imprime();
        void busca(string nome);
};

Lista::Lista()
{
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

Lista::~Lista()
{
    while(tamanho > 0)
    {
        retiraInicio();
    }
}

void Lista::insereInicio(Acao acao)
{
    Noh* novo = new Noh(acao);
    if (tamanho == 0)
    {
        primeiro = novo;
        ultimo = novo;    
    }
    else
    {
        novo->proximo = primeiro;
        primeiro->anterior = novo;
        primeiro = novo;
    }
    tamanho++;
}

void Lista::insereFim(Acao acao)
{
    Noh* novo = new Noh(acao);
    if (tamanho == 0)
    {
        primeiro = novo;
        ultimo = novo;    
    }
    else
    {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    }
    tamanho++;
}

void Lista::insereMeio(int posicao, Acao acao)
{
    if ((posicao > tamanho) || (posicao < 0))
    {
        cout << "Posição Inexistente!" << endl;
    }
    else
    {
        if (posicao == 0)
        {
            insereInicio(acao);
        }
        else if (posicao == tamanho)
        {
            insereFim(acao);
        }
        else
        {
            Noh* novo = new Noh(acao);
            if (tamanho == 0)
            {
                primeiro = novo;
                ultimo = novo;    
            }
            else
            {
                Noh* aux = primeiro;
                for (int i=0; i < posicao-1; i++)
                {
                    aux = aux->proximo;
                }
                aux->proximo->anterior = novo;
                novo->proximo = aux->proximo;
                novo->anterior = aux;
                aux->proximo = novo;
            }
            tamanho++;
        }
    }
}

void Lista::retiraInicio()
{
    if (tamanho == 0)
    {
        cout << "Remoção em lista vazia!" << endl;
    }
    else
    {
        Noh* aux = primeiro;
        primeiro = primeiro->proximo;
        if (primeiro != NULL)
			primeiro->anterior = NULL;
        delete aux;
        tamanho--;
    }
}

void Lista::retiraFim()
{
    if (tamanho == 0)
    {
        cout << "Remoção em lista vazia!" << endl;
    }
    else
    {
        Noh* aux = ultimo;
        ultimo = ultimo->anterior;
        if (ultimo != NULL)
			ultimo->proximo = NULL;
        delete aux;
        tamanho--;
    }
}

void Lista::imprime()
{
    if (tamanho == 0)
    {
        cout << "Lista vazia!" << endl;
    }
    else
    {
        Noh* aux = primeiro;
        while (aux != NULL)
        {
            cout << "(" << aux->acao.identificador << ", " << aux->acao.nome << ", " << aux->acao.tempoExecucao << ", " << aux->acao.tempoConsumido << ")" << endl;
            aux = aux->proximo;
        }
        cout << " IMPRIMINDO REVERSO " << endl;
        aux = ultimo;
        while (aux != NULL)
        {
            cout << "(" << aux->acao.identificador << ", " << aux->acao.nome << ", " << aux->acao.tempoExecucao << ", " << aux->acao.tempoConsumido << ")" << endl;
            aux = aux->anterior;
        }
    }
}

void Lista::busca(string nome)
{
    if (tamanho == 0)
    {
        cout << "Lista vazia!" << endl;
    }
    else
    {
        Noh* aux = primeiro;
        while (aux != NULL)
        {
            if (aux->acao.nome == nome)
            {
                cout << "(" << aux->acao.identificador << ", " << aux->acao.nome << ", " << aux->acao.tempoExecucao << ", " << aux->acao.tempoConsumido << ")" << endl;
            }
            aux = aux->proximo;
        }
        if (aux == NULL)
        {
            cout << "Nao encontrado" << endl;
        }
    }
}

int main()
{
    Lista lista;
    char comando;

    Acao acao;
    int posicao;
    string nome;
    cin >> comando;
    do
    {
        switch (comando)
        {
            case 'i':
                cin >> acao.identificador >> acao.nome >> acao.tempoExecucao >> acao.tempoConsumido;
                lista.insereInicio(acao);
                break;
            case 'h':
                cin >> acao.identificador >> acao.nome >> acao.tempoExecucao >> acao.tempoConsumido;
                lista.insereFim(acao);
                break;
            case 'm':
                cin >> posicao >> acao.identificador >> acao.nome >> acao.tempoExecucao >> acao.tempoConsumido;
                lista.insereMeio(posicao, acao);
                break;
            case 'r':
                lista.retiraInicio();
                break;
            case 'a':
                lista.retiraFim();
                break;
            case 'p':
                lista.imprime();
                break;
            case 's':
                cin >> nome;
                lista.busca(nome);
                break;
            default:
                break;
        }
        cin >> comando;
    }
    while (comando != 'f');
    
    return 0;
}