/*
Uma escola resolveu criar um sistema para fazer o registro de notas dos seus alunos. Para isso, você deve criar um programa que recebe as seguintes informações:
número total de alunos e para cada aluno o nome, número de matrícula e nota final do mesmo. É garantido que os dados serão fornecidos em ordem crescente de matrícula.
Esses dados devem ser gravados em um arquivo tipado chamado de "alunos.bin".

A seguir, o programa recebe dois números de matrícula. O seu programa deve: buscar o aluno no arquivo tipado com o primeiro número de matrícula (busca binária).
Em seguida, alterar esse campo para o segundo número de matrícula fornecido. Esse registro agora deve ser reposicionado para manter a ordem do arquivo tipado.
Para isso, deve-se deslocar as posições dos registros no arquivo. No final, um relatório contendo o nome e nota de cada aluno, na mesma ordem que aparecem no arquivo
tipado deve ser gerado na tela.

OBS: Não é permitida a utilização de vetores ou matrizes nesse programa.

Entradas:

    Número de Alunos - (inteiro)
    Sequência de dados de aluno: nome (sem espaco), matrícula, nota - (string, inteiro, real)
    matrícula do registro que deve ser modificado
    nova matrícula

Saídas:

    Lista de alunos ordenada (nome, nota)

Exemplo de Entrada:

3
Joao 1010 80.0
Paulo 1020 85.0
Ana 1030 90.5
1030 1000

Exemplo de Saída:

Ana 90.5
Joao 80.0
Paulo 85.0
*/

#include <iostream>
#include <fstream>
using namespace std;

struct aluno
{
    string nome;
    int matricula;
    float nota;
};

int main()
{
    aluno listaAluno;
    fstream arquivo("alunos.bin", ios::binary);
    int nDeAlunos = 0;
    cin >> nDeAlunos;

    for (int i = 0; i < nDeAlunos; i++)
    {
        cin >> listaAluno.nome >> listaAluno.matricula >> listaAluno.nota;
        arquivo.write((char*)&listaAluno, sizeof(aluno));
    }
    arquivo.close();

    int matriculaAntiga, matriculaNova;
    cin >> matriculaAntiga >> matriculaNova;

    arquivo.open("alunos.bin", ios::in | ios::out | ios::binary);
    int inicio = 0, fim = nDeAlunos - 1, meio;
    fstream arquivoAux(ios::binary);
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        arquivo.seekg(meio * sizeof(aluno), ios::cur);
        arquivoAux = arquivo.read((char*)&listaAluno.matricula, sizeof(aluno));
        if (listaAluno.matricula == matriculaAntiga)
        {
            listaAluno.matricula = matriculaNova;

        }
        else if(listaAluno.)
    }

    return 0;
}