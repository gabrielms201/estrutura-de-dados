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
	// Deve colocar o numero "2" como último elemento da pilha:
	pilha.Push(2);
	pilha.Print();
}
int main() 
{
	sample();
}