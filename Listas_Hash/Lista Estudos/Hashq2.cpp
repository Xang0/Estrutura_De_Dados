/*
Utilize uma tabela hash para implementar um dicionário de capacidade para 23 palavras, sua tabela terá o tratamento de colisões por encadeamento.
Seu programa deve ser capaz de armazenar e buscar por uma palavra e seu significado. Caso seja feita uma busca por uma palavra inexistente em seu
dicionário, o programa imprimirá NULL no lugar do significado da palavra. Seu programa deve permitir quantas buscas forem desejadas pelo usuário,
sendo -1 a palavra que representa a intenção de termino do programa. OBS: Sua função que faz o hash será da seguinte forma: tamanho_da_palavra mod 23.

Entradas:

    Quantidade de palavras a serem inseridas.
    Palavra.
    Significado da Palavra.
    Palavras buscadas.

Saídas:

    [Palavra_buscada] => Significado da palavra buscada.

Exemplo de Entrada:

5
Casa Edifício de formatos e tamanhos variados, ger. de um ou dois andares, quase sempre destinado à habitação.
Aniversário Diz-se de ou dia em que se completa um ou mais anos em que se deu determinado acontecimento.
Carta Mensagem, manuscrita ou impressa, a uma pessoa ou a uma organização, para comunicar-lhe algo.
Exonerado  Libertar ou libertar-se de uma obrigação ou de um dever.
Concomitantemente Que acompanha ou coexiste. Que acontece ou se faz ao mesmo tempo.
Carta
Casa
Boneca
-1

Exemplo de Saída:

[Carta] => Mensagem, manuscrita ou impressa, a uma pessoa ou a uma organização, para comunicar-lhe algo.
[Casa] => Edifício de formatos e tamanhos variados, ger. de um ou dois andares, quase sempre destinado à habitação.
[Boneca] => NULL
*/

#include <iostream>
using namespace std;

int main()
{
    return 0;
}