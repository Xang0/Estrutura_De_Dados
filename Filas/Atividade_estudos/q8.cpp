/*
Um homem decidiu aproveitar um espaço existente em uma das ruas do bairro em que mora para estacionar carros e complementar sua renda oferecendo
o serviço de vallet. Para aumentar a renda, o homem estaciona os carros em 45o, o que não permite que um carro sai do estacionamento sem que os
carros estacionados à sua frente também tenham que sair. O serviço oferecido tem sido bem sucedido e ele decidiu contratá-lo para implementar um
aplicativo que simule a operação do estacionamento de modo que ele saiba quantos carros terá que deslocar para que um determinado carro possa ser removido.
Os carros deslocados são conduzidos por uma rua paralela e depois estacionados novamente.

Defina a estrutura de dados adequada, utilizando encadeamento, para simular o funcionamento do negócio e implemente essa estrutura (não é permitido o uso da
STL ou similares). Lembrando-se que você deve respeitar as regras da estrutura para acesso aos dados, implemente:

    o método que permita simular a operação de estacionar (E);
    o método que permita simular a operação de retirar um carro do estacionamento (D);
    o método que permita ao dono do negócio saber quantos carros foram removidos para a retirada de um determinado carro e imprima a configuração do
    estacionamento após a remoção.
    a execução é encerrada quando a opção de saída é selecionada (S);

Os carros estacionados são caracterizados pela sua placa. Para executar uma operação, o usuário deve indicar a operação desejada e informar a placa do carro.
Caso seja solicitada a operação de retirado de um carro e este não seja encontrado no estacionamento, deve ser emitida a mensagem "NAO ENCONTRADO". Sempre que
um carro é retirado, deve ser impresso o número de carros retirados e a nova configuração do estacionamento.

Entradas:

    Conjunto de operações de estacionar e retirar carros do estacionamento

Saídas:

    Número de carros retirados.
    Configuração dos carros no estacionamento a cada retirada do carro desejado.

Exemplos de Entrada e Saída:

Entrada

E abc1234
E def4567
E poi0987
E zxc5687
D poi0987
D abc1234
S

Exemplo de Saída:

3
zxc5687
abc1234
def4567
2
def4567
zxc5687

Entrada

D poi0987
E abc1234
E def4567
E zxc5687
D abc1234
S

Exemplo de Saída:

NAO ENCONTRADO
1
def4567
zxc5687

Entrada

E VFT1010
D VFT1010
S

Exemplo de Saída:

1
*/

#include <iostream>
using namespace std;

class noh
{
    friend class fila;
    private:
        noh* proximo;
        string placa;
    public:
        noh();
};

noh::noh()
{
    this->proximo = NULL;
    this->placa = "";
}

class fila
{
    private:
        noh* inicio;
        noh* fim;
        int tamanho;
    public:
        fila();
        void estacionar(string placa);
        string desenfilerar();
        void retirar(string placa, int& carrosRemovidos);
        void imprimir(int carrosRemovidos);
};

fila::fila()
{
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

void fila::estacionar(string placa)
{
    noh* novo = new noh();
    novo->placa = placa;
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

string fila::desenfilerar()
{
    string valor = inicio->placa;
    noh* aux = inicio;
    inicio = inicio->proximo;
    delete aux;
    tamanho--;
    if (tamanho == 0)
    {
        fim = NULL;
    }
    return valor;
}

void fila::retirar(string placa, int& carrosRemovidos)
{
    string procurado = placa;
    if (inicio->placa == placa)
    {
        desenfilerar();
        carrosRemovidos++;
    }
    else
    {
        string placa = desenfilerar();
        carrosRemovidos++;
        estacionar(placa);
        retirar(procurado, carrosRemovidos);
    }
}

void fila::imprimir(int carrosRemovidos)
{
    noh* aux = inicio;
    cout << carrosRemovidos << endl;
    while (aux != NULL)
    {
        cout << aux->placa << endl;
        aux = aux->proximo;
    }
}

int main()
{
    fila etacionamento;
    char operacao = ' ';
    string placa;
    int carrosRemovidos = 0;

    while (operacao != 'S')
    {
        cin >> operacao;
        switch (operacao)
        {
        case 'E':
            cin >> placa;
            etacionamento.estacionar(placa);
            break;
        case 'D':
            cin >> placa;
            etacionamento.retirar(placa, carrosRemovidos);
            etacionamento.imprimir(carrosRemovidos);
            carrosRemovidos = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}