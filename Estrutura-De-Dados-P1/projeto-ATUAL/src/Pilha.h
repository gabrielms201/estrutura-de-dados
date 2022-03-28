#ifndef PILHA_H
#define PILHA_H
/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#include <iostream>

using namespace std;

typedef int Elem; 

const int TAM_PILHA = 100;

class Pilha 
{
	private:
   		int topoPilha;
   		Elem e[TAM_PILHA];
   	public:
   		Pilha();
   		~Pilha();
   		bool isEmpty();
   		bool isFull();
   		void push(Elem e);
   		Elem pop();
   		Elem topo(); 
		int size();		
};
#endif // #ifndef PILHA_H





