/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128 
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#include "Programa.h"
void sample()
{
	Pilha pilha = Pilha();
	pilha.Init();
	// Deve popular a pilha
	pilha.Push(10);
	pilha.Push(9);
	pilha.Push(8);
	pilha.Push(7);
	pilha.Push(6);
	pilha.Push(5);
	pilha.Push(4);
	pilha.Push(3);
	pilha.Push(2);
	pilha.Push(1);
	// Deve remover o ultimo elemento da pilha
	pilha.Pop();
	cout << "Apos o primeiro pop: " << endl;
	cout << "\tTamanho: " << pilha.Size() << endl;
	// Deve colocar o numero "2" como último elemento da pilha:
	pilha.Push(2);
	//
	cout << "Apos o push do valor 2: " << endl;
	cout << "\tIsEmpty: " << pilha.IsEmpty() << endl;
	cout << "\tIsFull: " << pilha.IsFull() << endl;
	cout << "\tTamanho: " << pilha.Size() << endl;
	cout << "Valor da Pilha: ";
	pilha.Print();
	for (int i = 0; i < 10; i++)
	{
		pilha.Pop();
	}
	cout << "\nApos esvaziar a pilha: " << endl;
	cout << "\tIsEmpty: " << pilha.IsEmpty() << endl;
}
int main() 
{
	//sample();
	string infix_expression, postfix_expression;
	int ch;
	do 
	{
		cout << " Coloque a notacao infixa: ";
		cin >> infix_expression;
		postfix_expression = Calculadora::Convert(infix_expression);
		cout << "\n Sua notacao infixa eh: " << infix_expression;
		cout << "\n\n A notacao posfixa eh: " << postfix_expression << "\n";
		cout << "\n \t Quer inserir outra notacao infixa (1/ 0)\n?";
		cin >> ch;

	} while (ch == 1);
	return 0;
}
