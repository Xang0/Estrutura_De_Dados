/*
Implemente uma função que realize a remoção dos jogos com valores inferiores a um valor informado, denominada remoção especial. Você poderá utilizar 
somente como estrutura auxiliar outra pilha. Os demais valores da pilha devem permanecer na posição original. Os valores removidos devem ser impressos 
no momento da remoção.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Pilha com encadeamento - Inventário de itens de jogo" como base.

Entradas:

Com essa finalidade, você deverá adicionar mais um comando, como segue:

    x: seguido de um inteiro: para remover (e imprimir) todos os elementos com valor inferiores ao informado

Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção especial. Ao
terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i dez j 10
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
x 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1
f
Nome: sete Tipo: g Valor: 7
Nome: quatro Tipo: d Valor: 4
Nome: dez Tipo: j Valor: 10
*/


#include <iostream>
using namespace std;

struct Dados
{
    string nome;
    char tipo;
    int valor;
};

class Noh
{
    friend class Pilha;
    private:
        Dados* dado;
        Noh* proximo;
    public:
        Noh();
        Noh(Dados dado);
};

Noh::Noh()
{
    dado = NULL;
    proximo = NULL;
}

Noh::Noh(Dados dado)
{
    this->dado = new Dados;
    this->dado->nome = dado.nome;
    this->dado->tipo = dado.tipo;
    this->dado->valor = dado.valor;
    proximo = NULL;
}

class Pilha
{
    private:
        Noh* topo;
        int tamanho;
    public:
        Pilha();
        ~Pilha();
        void inserir(Dados d);
        Dados remover();
        void espiar();
        void imprimir(Dados d);
        void removerEspecial(int valor);
};

Pilha::Pilha()
{
    topo = NULL;
    tamanho = 0;
}

Pilha::~Pilha()
{
    while (tamanho > 0)
    {
        Dados d = remover();
        imprimir(d);
    }
}

void Pilha::inserir(Dados d)
{
    Noh* novo = new Noh(d);
    novo->proximo = topo;
    topo = novo;
    tamanho++;
}

Dados Pilha::remover()
{
    Dados d;
    if (tamanho > 0)
    {
        Noh* removido = topo;
        d = *topo->dado;
        topo = removido->proximo;
        delete removido;
        tamanho--;
        return d;
    }
    cout << "Erro: pilha vazia!" << endl;
    d.nome = "";
    return d;
}

void Pilha::imprimir(Dados d)
{
    cout << "Nome: " << d.nome << " Tipo: " << d.tipo << " Valor: " << d.valor << endl;
}

void Pilha::espiar()
{
    imprimir(*topo->dado);
}

void Pilha::removerEspecial(int valor)
{
    Pilha* aux = new Pilha();
    int contador = 0;
    while (tamanho > 0)
    {
        Dados removido = remover();
        if (removido.valor < valor)
        {
            contador++;
            aux->inserir(removido);
        }
        else
        {
            aux->inserir(removido);
        }
    }   
    while (contador > 0)
    {
        Dados d = aux->remover();
        imprimir(d);
        contador--;
    }
    while (aux->tamanho > 0)
    {
        Dados d = aux->remover();
        inserir(d);
    }
}

int main()
{
    Pilha pilha;
    char comando;

    cin >> comando;
    while (comando != 'f')
    {
        switch (comando)
        {
            case 'r':
            {
                Dados d = pilha.remover();
                if (d.nome != "")
                {
                    pilha.imprimir(d);
                }
                break;
            }
            case 'i':
            {
                Dados d;
                cin >> d.nome >> d.tipo >> d.valor;
                pilha.inserir(d);
                break;
            }
            case 'e':
            {
                pilha.espiar();
                break;
            }
            case 'x':
            {
                int valor;
                cin >> valor;
                pilha.removerEspecial(valor);
                break;
            }
            default:
            {
                pilha.~Pilha();
                break;
            }
        }
        cin >> comando;
    }

    return 0;
}