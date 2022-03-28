#ifndef FILA_CIRCULAR_CLASSE_H
#define FILA_CIRCULAR_CLASSE_H
/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/

#include <iostream>
#include <string>
using namespace std;
// KEY AND VALUE STRUCT
struct CHAVE_VALOR
{
	char letra;
	string valor;
};

// definição de um novo tipo de dado
typedef CHAVE_VALOR ElemFila;

// constante que indica o Tamanho alocado para a Fila
const int TAM_FILA = 30;

// Classe que representa a fila circular estática e sequencial
class FilaCircular 
{
	private:
		int inicio, fim, qtde;
		ElemFila e[TAM_FILA];
	public:
		FilaCircular();
		~FilaCircular(){};
		bool qIsEmpty();
		bool qIsFull();
		void enqueue(ElemFila e);
		ElemFila dequeue();
		ElemFila front();
		ElemFila rear();
		int size();	
};
#endif //#ifndef FILA_CIRCULAR_CLASSE_H

