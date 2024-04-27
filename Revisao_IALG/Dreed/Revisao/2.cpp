/*
Na matemática a união de dois conjuntos A e B é representada por A ∪ B e é formada por todos os elementos pertencentes a A ou B.
Por exemplo, seja A = {1, 2, 3} e B = {4, 5}, então a união destes dois conjuntos será A ∪ B = {1, 2, 3, 4, 5},
porém caso um elemento esteja em ambos os conjuntos ele não irá aparecer duas vezes no conjunto união, por exemplo, seja A = {1, 2, 3} e B = {1, 2, 4},
assim a união será A ∪ B = {1, 2, 3, 4}.

Utilizando os conceitos de conjunto faça um programa que leia dois vetores A e B e determine a união. O tamanho de cada vetor será informado pelo usuário.

Obs.: Considere que não existirão vetores vazios.

Obs.2: Os vetores devem ser alocados dinamicamente.

Entradas:

    Tamanho do vetor A.
    Elementos do vetor A.
    Tamanho do vetor B.
    Elementos do vetor B.

Saídas:

    Vetor C representado a união dos vetores A e B.

Exemplo de Entrada:

3
1 2 3
2
2 4

Exemplo de Saída:

1 2 3 4
*/


#include <iostream>
using namespace std;

int main()
{
    int tamA = 0;
    cin >> tamA;
    int vetorA[tamA];
    for (int i = 0; i < tamA; i++)
    {
        cin >> vetorA[i];
    }

    int tamB = 0;
    cin >> tamB;
    int vetorB[tamB];
    for (int i = 0; i < tamB; i++)
    {
        cin >> vetorB[i];
    }

    int capacidadeC = tamA + tamB;
    int tamC = 0;
    int vetorC[capacidadeC];

    for (int i = 0; i < tamA; i++)
    {
        vetorC[i] = vetorA[i];
        tamC++;
    }
    for (int i = 0; i < tamB; i++)
    {
        bool ehRepetido = false;
        for (int j = 0; j < tamA; j++)
        {
            if (vetorB[i] == vetorA[j])
            {
                ehRepetido = true;
            }
        }

        if (!ehRepetido)
        {
            vetorC[tamC] = vetorB[i];
            tamC++;
        }
    }

    for (int i = 0; i < tamC; i++)
    {
        cout << vetorC[i] << " ";
    }

    cout << endl;

    return 0;
}