#ifndef CALCULADORA_H
#define CALCULADORA_H
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
#include "Pilha.h"

using namespace std;


class Calculadora 
{
public:
	static int CalculadoraPosFixa(string notacaoPosfixa);
	static bool Operador(char ch);
	static bool Operando(char ch);
	static int Comparativo(char oper);
	static bool IgualOuMaior(char oper1, char oper2);
	static string InfixaParaPosfixa(string infixa);
private:
};
#endif // !CALCULADORA_H