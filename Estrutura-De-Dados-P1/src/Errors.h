/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#ifndef ERRORS_H
#define ERRORS_H

// Includes && Using Namespace
#include <iostream>
#include <string>
using namespace std;

// Struct dosd Errors
struct Errors 
{
	static void AvisoOverFlow()
	{
		cout << "ERRO: OVERFLOW" << endl;
	}	

	static void AvisoUnderFlow()
	{
		cout << "ERRO: UNDERFLOW" << endl;
	}
};
#endif // #ifndef ERRORS_H
