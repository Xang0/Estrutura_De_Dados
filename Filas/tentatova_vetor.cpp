/*
Implemente uma função que realize a ordenação dos elementos da fila pelo número do processo. O elemento com menor número deve ficar na frente
da fila e o de maior valor no fim.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Fila com armazenamento em vetor - Lista de processos em uma repartição pública" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

o: para ordenar a fila.
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção. Ao terminar a execução
do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: fila vazia!
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon m 40
Erro: fila cheia!
r
Nome: processo1 Assunto: Joao Tipo: a Processo: 2
e
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
i processo7 Marlon m 4
o
f
Nome: processo7 Assunto: Marlon Tipo: m Processo: 4
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
Nome: processo3 Assunto: Severino Tipo: d Processo: 9
Nome: processo5 Assunto: Barnabe Tipo: a Processo: 10
Nome: processo4 Assunto: Marcos Tipo: f Processo: 12
Nome: processo6 Assunto: Tiao Tipo: z Processo: 22
*/

#include <iostream>
using namespace std;

struct Dado
{
    string nome;
    string assunto;
    char tipo;
    int nProcesso;
};

class Fila
{
    private:
        Dado* vetor;
        int capacidade;
        int tamanho;
        int inicio;
        int fim;
    public:
        Fila();
        ~Fila();
        void enfileirar(Dado d);
        Dado desenfileirar();
        void espiar(Dado d);
        bool vazio();
        void imprimir();
        void ordenar();
};

Fila::Fila()
{
    capacidade = 6;
    vetor = new Dado[capacidade];
    tamanho = 0;
    fim, inicio = -1;
}

Fila::~Fila()
{
    delete[] vetor;
}

void Fila::enfileirar(Dado d)
{
    if (tamanho != capacidade)
    {
        if (tamanho == 0)
        {
            fim = (fim+1) % capacidade;
            vetor[fim] = d;
            tamanho++;
        }
        if (inicio == -1)
        {
            inicio = 0;
        }
    }
    else{
        cout << "Erro: fila cheia!" << endl;
    }
}

Dado Fila::desenfileirar()
{
    Dado d;
    if (tamanho == 0)
    {
        cout << "Erro: fila vazia!" << endl;
        d.nProcesso = -1;
    }
    else
    {
        d = vetor[inicio];
        if (inicio == fim)
        {
            inicio = fim -1;
        }
        else
        {
            inicio = (inicio+1) % capacidade;
        }
        tamanho--;
    }
    return d;
}

void imprimir(Dado d)
{
    cout << "Nome: " << d.nome << " Assunto: " << d.assunto << " Tipo: " << d.tipo << " Processo: " << d.nProcesso << endl;
}

bool Fila::vazio()
{
    return tamanho == 0;
}

void Fila::ordenar()
{
    Fila filaAux;
}

int main()
{
    return 0;
}