/*
4. Avalie a execução do código a seguir, se possível utilizando computadores, sistemas operacionais e compiladores diferentes (ex: g++ e clang++).
Observação: o código deve gerar erros, mas depende do SO, do compilador, etc. Experimente alterar a ordem de declaração de variáveis, para avaliar o impacto também.
*/

#include <iostream>

using namespace std;

int main(){
    int vetor[5]={0,1,2,3,4};
    
    int a = 8;
    char b = 'x';
    float c = 7;
    double d = 13.1;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    
    cout << "MUITA CACA NESSA HORA!" << endl;

    vetor[-3] = 163;
    vetor[-1] = 145;
    vetor[-2] = 198;
    vetor[6] = 125;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;    

    return 0;	
}

/*
Analise:
Os valores das váriaveis c e d são alteradas após o código tentar acessar endereços de memória que não existem.
Isso se deve ao fato de ao escrever em endereços de memória que não existem, o código sobrescreve valores de outras variáveis.
*/