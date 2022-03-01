/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#ifndef CALCULADORA_H
#define CALCULADORA_H

// Includes && Using Namespace
#include <iostream>
#include "Pilha.h"
using namespace std;

// Class Calculadora
class Calculadora
{
public:
	static bool IsOperator(char);
	static bool IsOperand(char);
	static bool EqlOrhigher(char, char);
	static string Convert(string);
	static int Precedence(char op);
};


#endif // #ifndef CALCULADORA_H