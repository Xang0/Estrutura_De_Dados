/*


Elabore um programa que preencha uma matriz 10 x 10 com números inteiros, execute cada operação de troca especificada a seguir na matriz original e
mostre cada matriz resultante. Você vai precisar de ao menos uma matriz extra para realizar as operações.

Operações de troca a serem realizadas (considerando índices que começam em 1):

    a linha 2 com a linha 8;
    a coluna 4 com a coluna 10;
    a diagonal principal com a diagonal secundária;
    a linha 5 com a coluna 10.

Entrada:

    Uma matriz 10 x 10 de inteiros.

Saída:

    A matriz 10 x 10 resultante das devidas operações descritas em 1, 2, 3, e 4 (utilizando um índice numérico antes de exibir cada matriz).

Exemplo de entrada:

1 2 3 4 5 6 7 8 9 0
2 3 4 5 6 7 8 9 0 1
3 4 5 6 7 8 9 0 1 2
4 5 6 7 8 9 0 1 2 3
5 6 7 8 9 0 1 2 3 4
6 7 8 9 0 1 2 3 4 5
7 8 9 0 1 2 3 4 5 6
8 9 0 1 2 3 4 5 6 7
9 0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9

Exemplo de saí­da:


1.
1 2 3 4 5 6 7 8 9 0
8 9 0 1 2 3 4 5 6 7
3 4 5 6 7 8 9 0 1 2
4 5 6 7 8 9 0 1 2 3
5 6 7 8 9 0 1 2 3 4
6 7 8 9 0 1 2 3 4 5
7 8 9 0 1 2 3 4 5 6
2 3 4 5 6 7 8 9 0 1
9 0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9
2.
1 2 3 0 5 6 7 8 9 4
2 3 4 1 6 7 8 9 0 5
3 4 5 2 7 8 9 0 1 6
4 5 6 3 8 9 0 1 2 7
5 6 7 4 9 0 1 2 3 8
6 7 8 5 0 1 2 3 4 9
7 8 9 6 1 2 3 4 5 0
8 9 0 7 2 3 4 5 6 1
9 0 1 8 3 4 5 6 7 2
0 1 2 9 4 5 6 7 8 3
3.
0 2 3 4 5 6 7 8 9 1
2 0 4 5 6 7 8 9 3 1
3 4 0 6 7 8 9 5 1 2
4 5 6 0 8 9 7 1 2 3
5 6 7 8 0 9 1 2 3 4
6 7 8 9 1 0 2 3 4 5
7 8 9 3 1 2 0 4 5 6
8 9 5 1 2 3 4 0 6 7
9 7 1 2 3 4 5 6 0 8
9 1 2 3 4 5 6 7 8 0
4.
1 2 3 4 5 6 7 8 9 5
2 3 4 5 6 7 8 9 0 6
3 4 5 6 7 8 9 0 1 7
4 5 6 7 8 9 0 1 2 8
0 1 2 3 4 5 6 7 8 9
6 7 8 9 0 1 2 3 4 0
7 8 9 0 1 2 3 4 5 1
8 9 0 1 2 3 4 5 6 2
9 0 1 2 3 4 5 6 7 3
0 1 2 3 4 5 6 7 8 4
*/

#include <iostream>
using namespace std;

int main()
{
    int matriz [10][10];
    int matrizReserva [10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> matriz[i][j];
        }
    }
    // Copiando os valores da matriz original para a matriz reserva
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrizReserva[i][j] = matriz[i][j];
        }
    }
    cout << endl;

    int vetorAuxiliar[10];

    // Troco a linha 2 pela linha 8
    for (int i = 0; i < 10; i++)
    {
        vetorAuxiliar[i] = matriz[7][i];
        matriz[7][i] =  matriz[1][i];
        matriz[1][i] = vetorAuxiliar[i];
    }
    cout << "1." << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Restauro a matriz original
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matriz[i][j] = matrizReserva[i][j];
        }
    }

    // Troco a caluna 4 pela coluna 10
    for (int i = 0; i < 10; i++)
    {
        vetorAuxiliar[i] = matriz[i][3];
        matriz[i][3] =  matriz[i][9];
        matriz[i][9] = vetorAuxiliar[i];
    }
    cout << "2." << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Restauro a matriz original
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matriz[i][j] = matrizReserva[i][j];
        }
    }

    // Troco a diagonal principal pela diagonal secundária
    int posDiagonalSecundaria = 9;
    for (int i = 0; i < 10; i++)
    {
        vetorAuxiliar[i] = matriz[i][i];
        matriz[i][i] = matriz[posDiagonalSecundaria][posDiagonalSecundaria];
        matriz[posDiagonalSecundaria][posDiagonalSecundaria] = vetorAuxiliar[i];
        posDiagonalSecundaria--;
    }
    cout << "3." << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Restauro a matriz original
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matriz[i][j] = matrizReserva[i][j];
        }
    }

    // Troco a linha 5 pela coluna 10
    for (int i = 0; i < 10; i++)
    {
        vetorAuxiliar[i] = matriz[4][i];
        matriz[4][i] = matriz[i][9];
        matriz[i][9] = vetorAuxiliar[i];
    }
    cout << "4." << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//0 1 2 3 4 5 6 7 8 9
//1 2 3 4 5 6 7 8 9 10