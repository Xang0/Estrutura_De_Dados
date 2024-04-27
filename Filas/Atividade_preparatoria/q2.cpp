/*
Implemente uma estrutura de dados fila, utilizando encadeamento de nós, para implementar uma lista de tarefas do jogador, usando como base o código
fornecido. A estrutura deve possibilitar, pelo menos, as seguintes ações: enfileiramento e desenfileiramento de itens, verificação do item no frente
da fila e limpeza da lista (remoção de todos os elementos da fila). O desenfileiramento deve escrever mensagem de erro na saída ("Erro: fila vazia!"),
quando a fila já estiver vazia. Os itens da lista possuem os seguintes atributos: nome da tarefa (uma string sem espaços), prêmio (uma string sem espaços),
tipo (um único caracter) e tempo para realização (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

    i seguido de duas string, um caracter e um inteiro: para inserir um item na lista de tarefas
    r: para retirar um item da lista de tarefas
    l: para limpar (remover todos) os itens da lista de tarefas
    e: para espiar a frente da lista de tarefas (escreve o topo sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido. Ao terminar a execução do programa, todos os itens da
fila são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: Fila vazia!
i destruirArmazen jaqueta f 100
i salvarDonzela hb20 e 300
i montarObservatorioMonteM2 binoculo d 400
i eliminarChefao milDolares a 2000
i eliminarBando dezmilDolares a 30000
r
Nome: destruirArmazen Premio: jaqueta Tipo: f tempo: 100
e
Nome: salvarDonzela Premio: hb20 Tipo: e tempo: 300
f
Nome: salvarDonzela Premio: hb20 Tipo: e tempo: 300
Nome: montarObservatorioMonteM2 Premio: binoculo Tipo: d tempo: 400
Nome: eliminarChefao Premio: milDolares Tipo: a tempo: 2000
Nome: eliminarBando Premio: dezmilDolares Tipo: a tempo: 30000
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct tarefa
{
    string nome;
    string premio;
    char tipo;
    int tempo;
};

class Noh
{
    friend class Fila;
    private:
        tarefa dado;
        Noh* proximo;
    public:
        Noh(tarefa d);       
};

Noh::Noh(tarefa d)
{
    dado = d;
    proximo = NULL;
}

class Fila
{
    private:
        Noh* primeiro;
        Noh* ultimo;
        int tamanho;
    public:
        Fila();
        ~Fila();
        void enfileira(tarefa d);
        void desenfileira();
        void limpa();
        void espiar();
        void imprime(tarefa d);
};

Fila::Fila()
{
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

Fila::~Fila()
{
    limpa();
}

void Fila::enfileira(tarefa d)
{
    Noh* novo = new Noh(d);
    if (tamanho == 0)
    {
        primeiro = novo;
    }
    else
    {
        ultimo->proximo = novo;
    }
    ultimo = novo;
    tamanho++;
}

void Fila::desenfileira()
{
    if (tamanho == 0)
    {
        cout << "Erro: Fila vazia!" << endl;
    }
    else
    {
        Noh* temp = primeiro;
        tarefa removido = temp->dado;
        primeiro = primeiro->proximo;
        delete temp;
        tamanho--;
        if (tamanho == 0)
        {
            ultimo = NULL;
        }
        cout << "Nome: " << removido.nome << " Premio: " << removido.premio << " Tipo: " << removido.tipo << " tempo: " << removido.tempo << endl;
    }
}

void Fila::limpa()
{
    while (tamanho > 0)
    {
        desenfileira();
    }
}

void Fila::espiar()
{
    cout << "Nome: " << primeiro->dado.nome << " Premio: " << primeiro->dado.premio << " Tipo: " << primeiro->dado.tipo << " tempo: " << primeiro->dado.tempo << endl;
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
                tarefa nova;
                cin >> nova.nome >> nova.premio >> nova.tipo >> nova.tempo;
                fila.enfileira(nova);
                break;
            }
            case 'r':
            {
                fila.desenfileira();
                break;
            }
            case 'l':
            {
                fila.limpa();
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