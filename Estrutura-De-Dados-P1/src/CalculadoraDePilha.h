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
template<class TIPO, const unsigned int TAMANHO_PILHA>
class CalculadoraDePilha
{
public:
	static bool Operador(char ch);
	static bool Operando(char ch);
	static bool igualOuMaior(char oper1, char oper2);
	static string Convert(string notacaoInfixa);
	static int Procedencia(char operador);
};

template<class TIPO, unsigned int TAMANHO_PILHA>
inline bool CalculadoraDePilha<TIPO, TAMANHO_PILHA>::Operador(char ch)
{
	char operadores[5] =
	{
		'*',
		'/',
		'+',
		'-',
		'^'
	};
	// Ve se o operador passado como parâmetro está de acordo com os operadores desejados
	// Para encontrar, é passado o primeiro e último elementos. 
	// Se a função encontrou, a função retorna o último valor, ou seja, 
	// se o valor retornado for diferente do último valor, então não encontrou o elemento.
	if (find(begin(operadores), end(operadores), ch) != end(operadores))
		return true;
	return false;
}

template<class TIPO, unsigned int TAMANHO_PILHA>
inline bool CalculadoraDePilha<TIPO, TAMANHO_PILHA>::Operando(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return true;
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= '0' && ch <= '9')
		return true;
	return false;
}

template<class TIPO, unsigned int TAMANHO_PILHA>
inline bool CalculadoraDePilha<TIPO, TAMANHO_PILHA>::igualOuMaior(char oper1, char oper2)
{
	int x1 = Procedencia(oper1);
	int x2 = Procedencia(oper2);
	if (x1 == x2) 
	{
		if (oper1 == '^')
			return false;
		return true;
	}
	return  (x1 > x2 ? true : false);
}

template<class TIPO, unsigned int TAMANHO_PILHA>
inline string CalculadoraDePilha<TIPO, TAMANHO_PILHA>::Convert(string notacaoInfixa)
{
	Pilha<TIPO, TAMANHO_PILHA> pilha = Pilha<TIPO, TAMANHO_PILHA>();
	string notacao_posfixa = "";
	char ch;

	pilha.Push('(');
	notacaoInfixa += ')';

	for (int i = 0; i < notacaoInfixa.length(); i++)
	{
		ch = notacaoInfixa[i];

		if (ch == ' ')
			continue;
		else if (ch == '(')
			pilha.Push(ch);
		else if (Operando(ch))
			notacao_posfixa += ch;
		else if (Operador(ch))
		{
			while (!pilha.IsEmpty() && igualOuMaior(pilha.Topo(), ch))
			{
				notacao_posfixa += pilha.Topo();
				pilha.Pop();
			}
			pilha.Push(ch);
		}
		else if (ch == ')')
		{
			while (!pilha.IsEmpty() && pilha.Topo() != '(')
			{
				notacao_posfixa += pilha.Topo();
				pilha.Pop();
			}
			pilha.Pop();
		}
	}
	return notacao_posfixa;
}

template<class TIPO, unsigned int TAMANHO_PILHA>
inline int CalculadoraDePilha<TIPO, TAMANHO_PILHA>::Procedencia(char operador)
{
	if (operador == '+' || operador == '-')
		return 1;
	if (operador == '*' || operador == '/')
		return 2;
	if (operador == '^')
		return 3;
	return 0;
}
#endif // #ifndef CALCULADORA_H