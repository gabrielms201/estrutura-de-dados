/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/

#include "Calculadora.h"

int Calculadora::CalculadoraPosFixa(string notacaoPosfixa)
{
	Pilha p;

	int tamanho = notacaoPosfixa.length();

	for (int x = 0; x < tamanho; x++)
	{

		if (notacaoPosfixa[x] >= '0' && notacaoPosfixa[x] <= '9')
		{
			p.push(notacaoPosfixa[x] - '0');
		}

		else {

			int n1 = p.topo();
			p.pop();

			int n2 = p.topo();
			p.pop();

			if (notacaoPosfixa[x] == '+') p.push(n2 + n1);
			if (notacaoPosfixa[x] == '-') p.push(n2 - n1);
			if (notacaoPosfixa[x] == '*') p.push(n2 * n1);
			if (notacaoPosfixa[x] == '/') p.push(n2 / n1);
			if (notacaoPosfixa[x] == '^') {
				int result = 1;
				for (int x = 0; x < n2; ++x) {
					result *= n1;
				}
				p.push(result);
			}
		}
	}

	return p.topo();
}

bool Calculadora::Operador(char ch)
{
	if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^')
		return true;
	return false;
}

bool Calculadora::Operando(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= 'A' && ch <= 'Z') 
		return true;
	return false;
}

int Calculadora::Comparativo(char oper)
{
	if (oper == '+' || oper == '-')
		return 1;
	if (oper == '*' || oper == '/')
		return 2;
	if (oper == '^')
		return 3;
	return 0;
}

bool Calculadora::IgualOuMaior(char oper1, char oper2)
{
	int n1 = Comparativo(oper1);
	int n2 = Comparativo(oper2);
	if (n1 == n2)
	{
		if (oper1 == '^')
			return false;
		return true;
	}
	return (n1 > n2 ? true : false); // OPERADOR TERNÁRIO: https://www.cplusplus.com/articles/1AUq5Di1/
}

string Calculadora::InfixaParaPosfixa(string infixa)
{
	Pilha p;

	string posfixa = "";
	char c;

	p.push('(');
	infixa += ')';

	for (int x = 0; x < infixa.length(); x++)
	{
		c = infixa[x];

		if (c == ' ') 
			continue;
		else if (c == '(') 
			p.push(c);
		else if (Operando(c)) 
			posfixa += c;
		else if (Operador(c))
		{
			while (!p.isEmpty() && IgualOuMaior(p.topo(), c))
			{
				posfixa += p.topo();
				p.pop();
			}
			p.push(c);
		}
		else if (c == ')')
		{
			while (!p.isEmpty() && p.topo() != '(')
			{
				posfixa += p.topo();
				p.pop();
			}
			p.pop();
		}
	}
	return posfixa;
}
