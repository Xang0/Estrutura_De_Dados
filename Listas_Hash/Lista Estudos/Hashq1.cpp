/*
Uma estrutura de dados do tipo conjunto (set) é uma coleção de elementos. Dado os conjuntos S, A e B, e um elemento x, um conjunto geralmente implementa
as seguintes operações básicas:

    membro(S,x) – Retorna true se o item x for membro do conjunto S.
    adiciona(S,x) – Adiciona o elemento x no conjunto S, descartando duplicatas. Se x já fizer parte de S, não é gerado erro, apenas não se modifica o conteúdo de S.
    remove(S,x) – Remove o elemento x do conjunto S. Se x não fizer parte de S, não é gerado erro, apenas não se modifica o conteúdo de S.
    tamanho(S) – Retorna o número de elementos de S.
    imprime(S) – Imprime os elementos de S. Caso o conjunto seja vazio, imprime {}
    uniao(A,B) – Retorna um novo conjunto A ∪ B, formado pela união dos elementos de A e B.
    intersecao(A,B) – Retorna um novo conjunto A ∩ B, formado pela interseção dos elementos de A e B.
    diferenca(A,B) – Retorna um novo conjunto A - B, formado pelos elementos de A que não fazem parte de B.

Como pode-se perceber, um conjunto é muito similar a uma lista, com algumas particularidades (a impossibilidade de duplicatas, por exemplo). Conjuntos podem
ser implementados de várias formas, incluindo: i) dicionários (tabelas hash); ii) árvores ou iii) listas dinâmicas com ponteiros. No caso de listas dinâmicas,
os dados podem ainda ser armazenados por meio de ponteiros ou arranjos.

Neste exercício, você deverá implementar a hash e os métodos para simular as operações básicas de conjuntos listadas anteriormente. Perceba que as operações de
uniao(A,B), intersecao(A,B) e diferenca(A,B) não precisam ser necessariamente implementadas, uma vez que estamos utilizando dicionários (tabelas hash).

Para este problema em específico, o conjunto estará limitado a 100 elementos inteiros, portanto, utilize a função de espelhamento dada por hash(k) = k mod 101.
O vetor de armazenamento do hash terá obviamente 101 posições. O valor associado à chave (o elemento) a ser armazenado é 1 (para indicar pertinência do elemento
ao conjunto) ou -1 (quando o elemento não pertence ao conjunto). Obviamente, como o conjunto inicialmente encontra-se vazio, todas os valores nas posições do vetor
de armazenamento devem ser inicializadas em -1. Obviamente também, por usar um vetor para armazenamento, o tratamento de colisões deverá ser por endereçamento aberto.

Além da estrutura de dados, você deverá implementar uma aplicação básica para teste, que irá criar um conjunto e executará uma série de operações na seguinte ordem:

    Constrói o conjunto a partir de uma lista de 10 elementos digitada pelo usuário.
    Remove três elementos indicados pelo usuário.
    Verifica se um dado valor informado pelo usuário é membro do conjunto (imprima 1 para pertinência e -1 para não-pertinência.
    Repete a operação de verificação de pertinência para outro valor informado pelo usuário.
    Imprime o conteúdo do conjunto, na ordem em que estão armazenados.
    Adiciona três novos elementos indicados pelo usuário
    Imprime novamente o conteúdo do conjunto, na ordem em que estão armazenados.

Entradas:

    10 elementos a serem inseridos no conjunto
    3 elementos a serem removidos do conjunto
    2 valores para verificação de pertinência
    3 elementos a serem inseridos no conjunto

Saídas:

    Informação sobre pertinência de um valor fornecido pelo usuário
    Informação sobre pertinência de outro valor fornecido pelo usuário
    Elementos do conjunto
    Elementos do conjunto, após inserção de novos elementos

Exemplo de Entrada:

1 2 3 4 5 6 7 8 9 10
9 10 11
7 10
1 9 10

Exemplo de Saída:

1 
-1
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 7 8 9 10 
*/

#include <iostream>
using namespace std;

int main()
{
    return 0;
}