/*
Implemente uma estrutura de dados pilha, utilizando encadeamento de nós, para implementar um inventário de itens em um jogo digital.
A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo
da pilha e limpeza do inventário (remoção de todos os elementos da pilha). O desempilhamento deve escrever mensagem de erro na saída
("Erro: pilha vazia!"), quando a pilha já estiver vazia. Os itens do inventários possuem os seguintes atributos: nome (uma string sem espaços),
tipo (um único caracter) e valor (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

    i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
    r: para retirar um item do inventário
    l: para limpar (remover todos) os itens do inventário
    e: para espiar o topo do inventário (escreve o topo sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa,
todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1
*/

#include <iostream>
using namespace std;

class noh
{
    friend class pilha;
    private:
        string nome;
        char tipo;
        int valor;
        noh* proximo;
    public:
        noh();
};

noh::noh()
{
    nome = "";
    tipo = ' ';
    valor = 0;
    proximo = NULL;
}

class pilha
{
    private:
        noh* topo;
        int tamanho;
    public:
        pilha();
        ~pilha();
        void getTopo();
        int getTamanho();
        void empilha(string n, char t, int v);
        void desempilha();
        void limpaPilha();
};

pilha::pilha()
{
    topo = NULL;
    tamanho = 0;
}

pilha::~pilha()
{
    limpaPilha();
}

int pilha::getTamanho()
{
    return tamanho;
}

void pilha::empilha(string n, char t, int v)
{
    noh* novoNoh = new noh();
    novoNoh->nome = n;
    novoNoh->tipo = t;
    novoNoh->valor = v;
    novoNoh->proximo = topo;
    topo = novoNoh;
    tamanho++;
}

void pilha::desempilha()
{
    if (topo != NULL)
    {
        noh* aux = topo;
        cout << "Nome: " << aux->nome << " Tipo: " << aux->tipo << " Valor: " << aux->valor << endl;
        topo = aux->proximo;
        delete aux;
        tamanho--;
    }
    else
    {
        cout << "Erro: pilha vazia!" << endl;
    }
}

void pilha::limpaPilha()
{
    while (topo != NULL)
    {
        desempilha();
    }
}

void pilha::getTopo()
{
    if (topo != NULL)
    {
        cout << "Nome: " << topo->nome << " Tipo: " << topo->tipo << " Valor: " << topo->valor << endl;
    }
    else
    {
        cout << "Erro: pilha vazia!" << endl;
    }
}

int main()
{
    pilha inventario;
    cout << "Escolha entre as seguintes operações:" << endl;
    cout << "i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário" << endl;
    cout << "r: para retirar um item do topo do inventário" << endl;
    cout << "l: para limpar (remover todos) os itens do inventário" << endl;
    cout << "e: para espiar o topo do inventário (escreve o topo sem removê-lo)" << endl;
    cout << "f: para finalizar a execução do programa" << endl;

    char opcao;
    cin >> opcao;

    while (opcao != 'f')
    {
        switch (opcao)
        {
            case 'i':
            {
                string nome;
                char tipo;
                int valor;
                cin >> nome >> tipo >> valor;
                inventario.empilha(nome, tipo, valor);

                cout << "Escolha entre as seguintes operações:" << endl;
                cout << "i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário" << endl;
                cout << "r: para retirar um item do topo do inventário" << endl;
                cout << "l: para limpar (remover todos) os itens do inventário" << endl;
                cout << "e: para espiar o topo do inventário (escreve o topo sem removê-lo)" << endl;
                cout << "f: para finalizar a execução do programa" << endl;
                cin >> opcao;

                break;
            }
            case 'r':
            {
                inventario.desempilha();

                cout << "Escolha entre as seguintes operações:" << endl;
                cout << "i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário" << endl;
                cout << "r: para retirar um item do topo do inventário" << endl;
                cout << "l: para limpar (remover todos) os itens do inventário" << endl;
                cout << "e: para espiar o topo do inventário (escreve o topo sem removê-lo)" << endl;
                cout << "f: para finalizar a execução do programa" << endl;
                cin >> opcao;

                break;
            }
            case 'l':
            {
                inventario.limpaPilha();

                cout << "Escolha entre as seguintes operações:" << endl;
                cout << "i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário" << endl;
                cout << "r: para retirar um item do topo do inventário" << endl;
                cout << "l: para limpar (remover todos) os itens do inventário" << endl;
                cout << "e: para espiar o topo do inventário (escreve o topo sem removê-lo)" << endl;
                cout << "f: para finalizar a execução do programa" << endl;
                cin >> opcao;

                break;
            }
            case 'e':
            {
                inventario.getTopo();

                cout << "Escolha entre as seguintes operações:" << endl;
                cout << "i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário" << endl;
                cout << "r: para retirar um item do topo do inventário" << endl;
                cout << "l: para limpar (remover todos) os itens do inventário" << endl;
                cout << "e: para espiar o topo do inventário (escreve o topo sem removê-lo)" << endl;
                cout << "f: para finalizar a execução do programa" << endl;
                cin >> opcao;

                break;
            }
        }
    }

    inventario.limpaPilha();
    
    return 0;
}