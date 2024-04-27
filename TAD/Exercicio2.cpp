#include <iostream>
#include <cstdlib>
using namespace std;

class vectorx
{
    private:
        int *vetor;
        int tam;
        int capacidade;
    public:
        vectorx();
        ~vectorx();
        bool membro(int n); // Verifica se o elemento n pertence ao vetor
        void operator+(int n); // Adiciona um elemento ao vetor
        void operator-(int n); // Remove um elemento do vetor
        int tamanho(){return tam;};
        int getCapacidade(){return capacidade;};
        void imprimir();
        vectorx operator+(const vectorx &vetor); // Operador de união
        vectorx operator*(const vectorx &vetor); // Operador de interseção
        vectorx operator-(const vectorx &vetor); // Operador de diferença
};

vectorx::vectorx()
{
    capacidade = 5;
    vetor = new int[capacidade];
    tam = 0;
}

vectorx::~vectorx()
{
    delete[] vetor;
}

bool vectorx::membro(int n)
{
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == n)
        {
            return true;
        }
    }
    return false;
}

void vectorx::imprimir()
{
    if (tam > 0)
    {
        cout << "{ ";
        for (int i = 0; i < tam; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}";
        cout << endl;
        cout << "----------------" << endl;
        cout << endl;
    }
    else
    {
        cout << "{ }" << endl;
    }

}

void vectorx::operator+(int n)
{
    if (tam == capacidade)
    {
        int *novo = new int[capacidade+5];
        for (int i=0; i < tam; i++)
        {
            novo[i] = vetor[i];
        }
        delete[] vetor;
        vetor = novo;
    }
    for (int i=0; i<tam; i++)
    {
        if (vetor[i] == n)
        {
            return;
        }
    }
    vetor[tam] = n;
    tam++;
}

void vectorx::operator-(int n)
{
    vectorx aux = *this;

    if (aux.membro(n))
    {
        for (int i = 0; i < tam; i++)
        {
            if (vetor[i] == n)
            {
                vetor[i] = NULL;
            }
        }
    }
    else
    {
        cout << "O elemento " << n << "não pertence ao conjunto" << endl;
    }
}

vectorx vectorx::operator+(const vectorx &vetor2)
{
    vectorx* novo;
    novo = new vectorx[tam+vetor2.tam];

    for (int i = 0; i < tam; i++)
    {
        novo->vetor[i] = vetor[i];
    }
    for (int i = tam; i<vetor2.tam; i++)
    {
        novo->vetor[i] = vetor2.vetor[i];
    }

    return *novo;
}

vectorx vectorx::operator*(const vectorx &vetor2)
{
    vectorx* novo;
    int cont = 0;
    for(int i=0; i<tam; i++)
    {
        if(vetor[i] == vetor2.vetor[i])
        {
            cont++;
        }
    }

    novo = new vectorx[cont];

    for (int i=0; i<cont; i++)
    {
        if(vetor[i] == vetor2.vetor[i])
        {
            novo->vetor[i] = vetor[i];
        }
    }

    return *novo;
}

vectorx vectorx::operator-(const vectorx &vetor2)
{
    vectorx* novo;
    vectorx aux = vetor2;
    int cont = 0;

    for (int i = 0; i<tam; i++)
    {
        if (!aux.membro(vetor[i]))
        {
            cont++;
        }
    }

    novo = new vectorx[cont];

    for (int i = 0; i<cont; i++)
    {
        if (!aux.membro(vetor[i]))
        {
            novo->vetor[i] = vetor[i];
        }
    }

    return *novo;
}

int main()
{
    vectorx S, A, B;
    S + 1;
    S + 24;
    S + 30;
    S + 3;
    S + 7;
    S + 12;

    cout << "S = ";
    S.imprimir();

    A + 30;
    A+ 27;
    A + 70;
    A+ 64;

    cout << "A = ";
    A.imprimir();

    B + 1;
    B + 71;
    B  + 89;
    B + 69;
    B + 43;

    cout << "B = ";
    B.imprimir();

    if (B.membro(72))
    {
        cout << "O elemento 72 pertence ao vetor B" << endl;
    }
    else
    {
        cout << "O elemento 72 não pertence ao vetor B" << endl;
    }
    cout << endl;

    if (S.membro(24))
    {
        cout << "O elemento 24 pertence ao vetor S" << endl;
    }
    else
    {
        cout << "O elemento 24 não pertence ao vetor S" << endl;
    }
    cout << endl;

    vectorx C = A + B;

    C.imprimir();

    return 0;
}