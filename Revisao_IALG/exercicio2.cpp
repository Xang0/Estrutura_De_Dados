/*
2. Implemente o código a seguir para verificar o uso do operador de endereçamento (&) e avalie os resultados obtidos.
Se possível, avalie em computadores, sistemas operacionais e compiladores diferentes (ex: g++ e clang++).
*/

#include <iostream>

using namespace std;

int main(){
    int a=20;
    cout << &a << endl;

    int v[5];
    cout << v << endl;
    cout << &v << endl;
    cout << &v[0]<< endl;
		
	return 0;	
}

/*
Análise:
O operador & retorna o endereço de memória da variável.
No caso do vetor "v", o endereço de memória que o código imprime no terminal é o mesmo para &v e &v[0] já que vetor é um ponteiro eterno 
que aponta para o primeiro elemento do vetor quando impresso.
*/