/*
Uma empresa de advocacia deseja resolver o problema de prioridade na análise de seus processos, pois alguns com menos importância estão sendo
tratados antes dos processos que possuem relevância mais alta.

Com seus conhecimentos de Estrutura de Dados, implemente uma estrutura para definir corretamente a prioridade dos processos. A ideia do programa
consiste no usuário solicitar qual processo deverá ser analisado e o programa toda vez informar aquele com prioridade mais alta no momento. Você
poderá utilizar o código fornecido como base de implementação. Os processos são representados por um código e uma prioridade. Quando maior o valor
da prioridade, mais urgente é o processo.

Comandos de utilização do programa:

    i: inserir um novo processo, seguido do código (número natural) e da prioridade (número inteiro) do processo.
    o: obter o processo que deverá ser tratado. Causa a retirada do processo mais prioritário do sistema e o programa escreve seu código e sua prioridade.
    Caso não tenha um processo para ser obtido, o programa escreve "Nao encontrado".
    s: sair do programa.

No início da execução, o programa lê a capacidade máxima de processos para trabalhar. Em seguida começa a processar os comandos acima.

Exemplo de Entrada:

10
i 1055 10
o
o
i 1240 1
i 7745 3
i 1249 7
i 7742 9
i 1395 2
i 1098 10
o
o
o
i 1293 10
o
o
s

Exemplo de Saída:

1055 10
Nao encontrado
1098 10
7742 9
1249 7
1293 10
7745 3
*/

#include <iostream>   

typedef unsigned TCodProcesso;

struct processo
{
    TCodProcesso codigo;
    int prioridade;
};

class Heap {
    // classe Heap (max-heap, o maior fica na raiz/inicio)
    public:
        processo* vetor;
        int tamanho;
        int capacidade;
        // Criar heap sem dados e com capacidade informada
        Heap(int cap);
        // Destruttor
        ~Heap();
        // Inserir um dado na heap
        void Inserir(TCodProcesso codigo, int prioridade);
        // Retira e retorna a raiz
        bool Retirar(TCodProcesso* ptCodigo, int* ptPrioridade);
        // Verifica se a heap está vazia
        bool Vazia();
    private:
        void ArrumarDescendo(int i);
        void ArrumarSubindo(int i);
        inline int Direito(int i);
        inline int Esquerdo(int i);
        inline int Pai(int i);
        // Falta colocar os atributos
};

bool operator>(processo item1, processo item2)
{
    return item1.prioridade > item2.prioridade;
}

bool operator<(processo item1, processo item2)
{
    return item1.prioridade < item2.prioridade;
}

using namespace std;

Heap::Heap(int cap) {
    capacidade = cap;
    vetor = new processo[capacidade];
    tamanho = 0;
}

Heap::~Heap() {
    delete[] vetor;
}

void Heap::ArrumarDescendo(int i) {
    // Arruma as posicoes de i para baixo.
    int esq = Esquerdo(i);
    int dir = Direito(i);
    int maior = i;

    if ((esq < tamanho) && (vetor[maior] < vetor[esq]))
    {
        maior = esq;
    }
    if ((dir < tamanho) && (vetor[maior] < vetor[dir]))
    {
        maior = dir;
    }
    if (maior != i)
    {
        swap(vetor[maior], vetor[i]);
        ArrumarDescendo(maior);
    }
}

void Heap::ArrumarSubindo(int i) {
    int pai = Pai(i);

    if (vetor[i] > vetor[pai])
    {
        swap(vetor[i], vetor[pai]);
        ArrumarSubindo(pai);
    }
}

int Heap::Pai(int i) {
    return (i-1)/2;
}

int Heap::Esquerdo(int i) {
    return 2*i +1;
}

int Heap::Direito(int i) {
    return 2*i + 2;
}

bool Heap::Retirar(TCodProcesso* ptCodigo, int* ptPrioridade) {
    // Retira um codigo/prioridade, retornando os dois valores.
    // Retorna falso se o heap estiver vazio.
    if (tamanho > 0)
    {
        *ptCodigo = vetor[0].codigo;
        *ptPrioridade = vetor[0].prioridade;
        swap(vetor[0], vetor[tamanho-1]);
        tamanho--;
        ArrumarDescendo(0);
        return true;
    }
    return false;
}

bool Heap::Vazia() {
    return tamanho == 0;
}

void Heap::Inserir(TCodProcesso codigo, int prioridade) {
    processo novo;
    novo.codigo = codigo;
    novo.prioridade = prioridade;
    if (tamanho <= capacidade)
    {
        if (tamanho == 0)
        {
            vetor[0] = novo;
        }
        else
        {
            vetor[tamanho] = novo;
            ArrumarSubindo(tamanho);
        }
        tamanho++;
    }
}

int main() {
    unsigned capacidade;
    cin >> capacidade;
    Heap heap(capacidade);
    char comando;
    TCodProcesso codigo;
    int prioridade;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir um processo no heap
                cin >> codigo >> prioridade;
                heap.Inserir(codigo, prioridade);
                break;
            case 'o': // obter um processo do heap
                if (heap.Retirar(&codigo, &prioridade))
                    cout << codigo << ' ' << prioridade << endl;
                else
                    cout << "Nao encontrado" << endl;
                break;
            case 's': //sair
                break;
        }
    } while (comando != 's');
    return 0;
}
