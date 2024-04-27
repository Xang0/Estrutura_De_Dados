/*
Implemente uma estrutura de dados fila, utilizando armazenamento em vetor, para implementar uma lista de processos para uma repartição pública,
utilizando como base o código fornecido. A estrutura deve possibilitar, pelo menos, as seguintes ações: enfileiramento e desenfileiramento de itens,
verificação do item no topo da pilha e limpeza de processos (remoção de todos os elementos da fila). O desenfileiramento deve escrever mensagem de erro
na saída ("Erro: fila vazia!"), quando a fila já estiver vazia. O enfileiramento também deve gerar mensagem de erro ("Erro: fila cheia!"), quanto todas
as posições do vetor estiverem ocupadas. Os itens da lista de processos possuem os seguintes atributos: assunto (uma string sem espaços), nome do
interessado(uma string sem espaços), tipo (um único caracter) e numero do processo (um inteiro). Além disso, essa repartição tem capacidade para trabalhar
com apenas seis processos por vez.

Entradas:

O programa deve aceitar os seguintes comandos:

    i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de processos
    r: para retirar um item da lista de processos
    l: para limpar (remover todos) os itens da lista de processos
    e: para espiar o topo da lista de processo (escreve o topo sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da
fila são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: fila vazia!
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon a 40
Erro: fila cheia!
r
Nome: processo1 Assunto: Joao Tipo: a Processo: 2
e
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
i processo7 Marlon a 40
f
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
Nome: processo3 Assunto: Severino Tipo: d Processo: 9
Nome: processo4 Assunto: Marcos Tipo: f Processo: 12
Nome: processo5 Assunto: Barnabe Tipo: a Processo: 10
Nome: processo6 Assunto: Tiao Tipo: z Processo: 22
Nome: processo7 Assunto: Marlon Tipo: a Processo: 40
*/

#include <iostream>
#include <cstring>
using namespace std;

const int capacidade_vetor = 6;

struct operacao
{
    string nome;
    string assunto;
    char tipo;
    int numero;
};

void imprimirOperacao(operacao operacao)
{
    cout << "Nome: " << operacao.nome << " Assunto: " << operacao.assunto << " Tipo: " << operacao.tipo << " Processo: " << operacao.numero << endl;
}

class Fila
{
    private:
        operacao* vetor;
        int inicio;
        int fim;
        int tamanho;
    public:
        Fila();
        ~Fila();
        operacao desenfileirar();
        void enfileirar(operacao novo);
        void limpar();
        void espiar();
};

Fila::Fila()
{
    vetor = new operacao[capacidade_vetor];
    inicio = 0;
    fim = 0;
    tamanho = 0;
}

Fila::~Fila()
{
    while (tamanho > 0)
    {
        operacao novo = desenfileirar();
        if (novo.assunto != "")
        {
            imprimirOperacao(novo);
        }
    }
    delete[] vetor;
}

operacao Fila::desenfileirar()
{
    operacao aux = vetor[inicio];
    if (tamanho == 0)
    {
        cout << "Erro: fila vazia!" << endl;
    }
    else
    {
        operacao* novo = new operacao[capacidade_vetor];
        inicio++;
        int cont = 0;
        for (int i=inicio; i<tamanho; i++)
        {
            novo[cont] = vetor[i];
            cont++;
        }
        delete[] vetor;
        vetor = novo;
        tamanho--;
        inicio = 0;
        fim = tamanho-1;
    }
    return aux;
}

void Fila::enfileirar(operacao novo)
{
    if (tamanho == capacidade_vetor)
    {
        cout << "Erro: fila cheia!" << endl;
    }
    else
    {
        if (tamanho == 0)
        {
            vetor[inicio] = novo;
        }
        else
        {
            fim++;
        }
        vetor[fim] = novo;
        tamanho++;
    }
}

void Fila::limpar()
{
    operacao* novo = new operacao[capacidade_vetor];
    vetor = novo;
    delete[] novo;
    inicio = 0;
    fim = 0;
    tamanho = 0;
}

void Fila::espiar()
{
    if (tamanho == 0)
    {
        cout << "Erro: fila vazia!" << endl;
    }
    else
    {
        imprimirOperacao(vetor[inicio]);
    }
}

int main()
{
    Fila fila;
    char comando;
    
    cin >> comando;
    while (comando != 'f')
    {
        switch (comando)
        {
            case 'i':
            {
                operacao nova;
                cin >> nova.nome >> nova.assunto >> nova.tipo >> nova.numero;
                fila.enfileirar(nova);
                break;
            }
            case 'r':
            {
                operacao novo;
                novo = fila.desenfileirar();
                if (novo.assunto != "")
                {
                    imprimirOperacao(novo);
                }
                break;
            }
            case 'l':
            {
                fila.limpar();
                break;
            }
            case 'e':
            {
                fila.espiar();
                break;
            }
            case 'f':
            {
                fila.~Fila();
                break;
            }
        }
        cin >> comando;
    }

    return 0;
}