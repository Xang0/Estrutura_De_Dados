#include <iostream>
using namespace std;

class Quadrinhos
{
    private:
        string nome, autor;
        int ano;
        float valor;
        char tipo;
    public:
        Quadrinhos();
        void cadastrarQuadrinhos(string nome, string autor, int ano, float valor, char tipo);
        void imprimir();
        string getNome() {return nome;}
};

Quadrinhos::Quadrinhos()
{
    nome = "-";
    autor = "-";
    ano = 0;
    valor = 0.0;
    tipo = '-';
}

void Quadrinhos::cadastrarQuadrinhos(string n, string au, int an, float v, char t)
{
    nome = n;
    autor = au;
    ano = an;
    valor = v;
    tipo = t;
}

void Quadrinhos::imprimir()
{
    cout << "Nome: " << nome << endl;
    cout << "Autor: " << autor << endl;
    cout << "Ano de lançamento: " << ano << endl;
    cout << "Valor em R$: " << valor << endl;
    cout << "Gênero: " << tipo << endl;
    cout << "-----------------------------" << endl << endl;
}

int particiona(Quadrinhos quadrinhos[], int comeco, int fim)
{
    string pivo = quadrinhos[comeco].getNome();
    int i = comeco;
    Quadrinhos aux;

    for (int j = comeco + 1; j <= fim; j++)
    {
        if (quadrinhos[j].getNome() < pivo)
        {
            i++;
            aux = quadrinhos[i];
            quadrinhos[i] = quadrinhos[j];
            quadrinhos[j] = aux;
        }
    }

    aux = quadrinhos[comeco];
    quadrinhos[comeco] = quadrinhos[i];
    quadrinhos[i] = aux;

    return i;
}

void ordenar(Quadrinhos quadrinhos[], int comeco, int fim)
{
    if (comeco < fim)
    {
        int pivo = particiona(quadrinhos, comeco, fim);
        ordenar(quadrinhos, comeco, pivo - 1);
        ordenar(quadrinhos, pivo + 1, fim);
    }
}

int main()
{
    Quadrinhos quadrinhos[20];
    string nome, autor;
    int ano;
    float valor;
    char tipo;
    char comando;
    int tam = 0;

    cout << "Deseja cadastrar um quadrinho? (s/n)" << endl;
    cin >> comando;
    cout << endl;

    while (comando == 's')
    {
        cin >> nome >> autor >> ano >> valor >> tipo;
        quadrinhos[tam].cadastrarQuadrinhos(nome, autor, ano, valor, tipo);
        tam++;

        cout << "Deseja cadastrar um quadrinho? (s/n)" << endl;
        cin >> comando;
        cout << endl;
    }

    ordenar(quadrinhos, 0, tam - 1);

    cout << "Quadrinhos cadastrados: " << endl << endl;
    for (int i = 0; i < tam; i++)
    {
        quadrinhos[i].imprimir();
    }

    return 0;
}