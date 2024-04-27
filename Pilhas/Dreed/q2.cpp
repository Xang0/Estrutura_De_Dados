/*
Implemente uma estrutura de dados pilha, utilizando armazenamento em vetor, para implementar uma lista de tarefas para um robô doméstico.
A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo da pilha
e limpeza da lista de afazeres (remoção de todos os elementos da pilha). O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"),
quando a pilha já estiver vazia. O empilhamento também deve gerar mensagem de erro ("Erro: pilha cheia!"), quanto todas as posições do vetor estiverem ocupadas.
Os itens da lista de tarefas possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e tempo de execução em minutos (um inteiro).
Além disso, sabe-se que esse robô tem capacidade de memória limitada para no máximo seis tarefas.

Entradas:

O programa deve aceitar os seguintes comandos:

    i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de tarefas
    r: para retirar um item da lista de tarefas
    l: para limpar (remover todos) os itens da lista de tarefas
    e: para espiar o topo da lista de tarefas (escreve o topo sem removê-lo)
    f: para finalizar a execução do programa

Antes dos comandos, o programa recebe a capacidade de armazenamento da pilha.

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da pilha
são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i sala s 150
i quarto1 q 45
i quarto2 q 45
i quarto3 q 60
i cozinha c 130	
r
Nome: cozinha Tipo: c Valor: 130
i cozinha c 145
e
Nome: cozinha Tipo: c Valor: 145
i varanda v 100
i banheiro b 120
Erro: pilha cheia!
f
Nome: varanda Tipo: v Valor: 100
Nome: cozinha Tipo: c Valor: 145
Nome: quarto3 Tipo: q Valor: 60
Nome: quarto2 Tipo: q Valor: 45
Nome: quarto1 Tipo: q Valor: 45
Nome: sala Tipo: s Valor: 150
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
        void criarNoh(string n, char t, int v);
};

noh::noh()
{
    this->nome = "";
    this->tipo = ' ';
    this->valor = 0;
    this->proximo = NULL;
}

void noh::criarNoh(string n, char t, int v)
{
    this->nome = n;
    this->tipo = t;
    this->valor = v;
    this->proximo = NULL;
}

class pilha
{
    private:
        noh* vetor;
        int topo;
    public:
        pilha();
        ~pilha();
        int getTopo();
        void empilha(string n, char t, int v);
        void desempilha();
        void limpaPilha();
};

pilha::pilha()
{
    vetor = new noh[6];
    topo = -1;
}

pilha::~pilha()
{
    limpaPilha();
}

int pilha::getTopo()
{
    cout << "Nome: " << vetor[topo].nome << "Tipo" << vetor[topo].tipo << "Valor: " << vetor[topo].valor << endl;
    return topo;
}

void pilha::empilha(string n, char t, int v)
{
    if (topo < 5)
    {
        noh* novoNoh = new noh();
        novoNoh->criarNoh(n, t, v);
        novoNoh->proximo = &vetor[topo];
        vetor[topo + 1] = *novoNoh;
        topo++;
    }
    else
    {
        cout << "Erro: pilha cheia!" << endl;
    }
}

void pilha::desempilha()
{
    if (topo >= 0)
    {
        cout << "Nome: " << vetor[topo].nome << " Tipo: " << vetor[topo].tipo << " Valor: " << vetor[topo].valor << endl;
        topo--;
    }
    else
    {
        cout << "Erro: pilha vazia!" << endl;
    }
}

void pilha::limpaPilha()
{
    while (topo >= 0)
    {
        cout << "Nome: " << vetor[topo].nome << " Tipo: " << vetor[topo].tipo << " Valor: " << vetor[topo].valor << endl;
        topo--;
    }
}

int main()
{
    pilha p1;
    char comando;

    cout << "Escolha dentre os comandos: ";
    cout << "i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de tarefas" << endl;
    cout << "r: para retirar um item da lista de tarefas" << endl;
    cout << "l: para limpar (remover todos) os itens da lista de tarefas" << endl;
    cout << "e: para espiar o topo da lista de tarefas (escreve o topo sem removê-lo)" << endl;
    cout << "f: para finalizar a execução do programa" << endl;

    cin >> comando;
    while (comando != 'f')
    {
        switch (comando)
        {
            case 'i':
            {
                string nome;
                char tipo;
                int valor;
                cin >> nome >> tipo >> valor;
                p1.empilha(nome, tipo, valor);
                break;
            }
            case 'r':
            {
                p1.desempilha();
                break;
            }
            case 'l':
            {
                p1.limpaPilha();
                break;
            };
            case 'e':
            {
                p1.getTopo();
                break;
            };
            case 'f':
            {
                p1.limpaPilha();
                break;
            }
        }

        cin >> comando;
    }
    

    return 0;
}