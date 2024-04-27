// 3. Avalie a execução do código a seguir, se possível utilizando computadores, sistemas operacionais e compiladores diferentes (ex: g++ e clang++).

#include <iostream>

using namespace std;

int main(){
    int aux;
    int *auxPtr;

    cout << "TRECHO PERIGOSO" << endl;
    cout << "Valor de aux:" << aux << endl;
    cout << "Endereço de aux:" << &aux << endl;
    cout << "Valor de auxPtr:" << auxPtr << endl;
    //cout << "Valor apontado por auxPtr:" << *auxPtr << endl;

    aux = 7;
    auxPtr = &aux;

    cout << "TRECHO SEGURO" << endl;
    cout << "Valor de aux:" << aux << endl;
    cout << "Endereço de aux:" << &aux << endl;
    cout << "Valor de auxPtr:" << auxPtr << endl;
    cout << "Valor apontado por auxPtr:" << *auxPtr << endl;
	
    return 0;	
}

/*
Analise:
No trecho perigoso, o código retorna o erro Segment Fault (core dumped) na linha 15, pois tenta acessar o valor do endereço de memória de aux 
sendo que ele não existe ainda.
Como as variáveis aux e auxPtr são inicializados no trecho seguro, o código não retorna erro e imprime os valores corretamente.
*/