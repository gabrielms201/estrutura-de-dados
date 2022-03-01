/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#include "Calculadora.h"

bool Calculadora::Operador(char ch) {
	
	if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^')
		return true;
	return false;
}

bool Calculadora::Operando(char ch){
	
	if (ch >= 'A' && ch <= 'Z')
		return true;
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= '0' && ch <= '9')
		return true;
	return false;
}

int Calculadora::Procedencia(char operador){
	
	if (operador == '+' || operador == '-')
		return 1;
	if (operador == '*' || operador == '/')
		return 2;
	if (operador == '^')
		return 3;
	return 0;
}

bool Calculadora::igualOuMaior(char oper1, char oper2){
	
	int x1 = Calculadora::Procedencia(oper1);
	int x2 = Calculadora::Procedencia(oper2);
	if (x1 == x2) {
		if (oper1 == '^')
			return false;
		return true;
	}
	return  (x1 > x2 ? true : false);
}

string Calculadora::Convert(string notacao_infixa){
	
	Pilha S = Pilha();
	string notacao_posfixa = "";
	char ch;

	S.Push('(');
	notacao_infixa += ')';

	for (int i = 0; i < notacao_infixa.length(); i++)
	{
		ch = notacao_infixa[i];

		if (ch == ' ')
			continue;
		else if (ch == '(')
			S.Push(ch);
		else if (Calculadora::Operando(ch))
			postfix += ch;
		else if (Calculadora::Operador(ch)) 
		{
			while (!S.IsEmpty() && Calculadora::igualOuMaior(S.Topo(), ch)) 
			{
				notacao_posfixa += S.Topo();
				S.Pop();
			}
			S.Push(ch);
		}
		else if (ch == ')') 
		{
			while (!S.IsEmpty() && S.Topo() != '(') 
			{
				notacao_posfixa += S.Topo();
				S.Pop();
			}
			S.Pop();
		}
	}
	return notacao_posfixa;
}
