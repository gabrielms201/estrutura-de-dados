/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#ifndef PILHA_H
#define PILHA_H

// Includes && Using Namespace
#include "Errors.h"
using namespace std;

// Tipo e tamanho da pilha
const int TAM_PILHA = 10;
typedef char TIPO;

// Class Pilha
class Pilha 
{
public:
	void Init();
	bool IsEmpty();
	void Push(TIPO element);
	TIPO Pop();
	TIPO Topo();
	bool IsFull();
	int Size();
	void Print();
private: 
	int _topo;
	TIPO _pilha[TAM_PILHA];

};
#endif // #ifndef PILHA_H