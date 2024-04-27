/*
Crie um programa que seja capaz de armazenar em uma lista equipes de uma maratona de programação. Para cada equipe deverá ser informado o seu nome,
representante da equipe, a linguagem que será utilizada e os seus respectivos membros. Vale ressaltar que o representante da equipe deverá ser um membro
da mesma. Para cada membro deverá ser obtido seu nome e seu nickname no GitHub.

Os comandos que deverão ser utilizados para execução do programa são:

    i: inserir uma nova equipe. O formato de entrada é: NomeEquipe Lider Linguagem QtdMembros Membro1 Nick1 ... MembroN NickN
    a: apagar uma determinada equipe (comparação pelo nome da mesma). Caso não exista a equipe deverá imprimir Nao encontrado
    p: imprimir lista de equipes cadastradas (não imprimir nada caso não exista dados cadastrados).
    b: buscar por uma equipe a partir de seu nome. Imprimir Nao encontrado quando a busca não obtiver sucesso.

Nota: o formato de saída das equipes deve ser: (Nome, Lider, [Integrante1/Nick1,...,IntegranteN/NickN]). Para mais instâncias de equipes (comando de impressão),
cada uma delas devem ser separadas por quebras de linha.

Entradas:

    Comandos detalhados no exercício

Saídas:

    Impressões detalhadas no exercício

Exemplo de Entrada e Saída misturados:

i Vingadores Stark Ruby 3 Stark tonydeferro Steve capitao Bruce hulkverdao
i LigaDaJustica Batman C++ 4 Bruce batman John lanternaverde Barry flash Virgil staticshock
b Revergers
Nao encontrado
b Vingadores
(Vingadores, Stark, Ruby, [Stark/tonydeferro, Steve/capitao, Bruce/hulkverdao])
p
(Vingadores, Stark, Ruby, [Stark/tonydeferro, Steve/capitao, Bruce/hulkverdao])
(LigaDaJustica, Batman, C++, [Bruce/batman, John/lanternaverde, Barry/flash, Virgil/staticshock])
s
*/

#include <iostream>
using namespace std;

int main()
{
    return 0;
}