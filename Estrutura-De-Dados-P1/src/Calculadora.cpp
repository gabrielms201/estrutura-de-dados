/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#include "Calculadora.h"

bool Calculadora::IsOperator(char c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}

bool Calculadora::IsOperand(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

int Calculadora::Precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}

bool Calculadora::EqlOrhigher(char op1, char op2)
{
	int p1 = Calculadora::Precedence(op1);
	int p2 = Calculadora::Precedence(op2);
	if (p1 == p2) {
		if (op1 == '^')
			return false;
		return true;
	}
	return  (p1 > p2 ? true : false);
}

string Calculadora::Convert(string infix)
{
	Pilha S = Pilha();
	string postfix = "";
	char ch;

	S.Push('(');
	infix += ')';

	for (int i = 0; i < infix.length(); i++)
	{
		ch = infix[i];

		if (ch == ' ')
			continue;
		else if (ch == '(')
			S.Push(ch);
		else if (Calculadora::IsOperand(ch))
			postfix += ch;
		else if (Calculadora::IsOperator(ch)) 
		{
			while (!S.IsEmpty() && Calculadora::EqlOrhigher(S.Topo(), ch)) 
			{
				postfix += S.Topo();
				S.Pop();
			}
			S.Push(ch);
		}
		else if (ch == ')') 
		{
			while (!S.IsEmpty() && S.Topo() != '(') 
			{
				postfix += S.Topo();
				S.Pop();
			}
			S.Pop();
		}
	}
	return postfix;
}