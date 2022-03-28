/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#include "FilaCircular.h"

// Construtor que Inicia a fila vazia
FilaCircular::FilaCircular()
{
	inicio = fim = qtde = 0;
}

// verifica se a fila está vazia
bool FilaCircular::qIsEmpty()
{
	if (qtde == 0)
		return true;
	else
		return false;
}
// Verifica se a fila está cheia
bool FilaCircular::qIsFull()
{
	if (qtde == TAM_FILA)
		return true;
	else
		return false;
}
// insere um ElemFilaento no final da fila
void FilaCircular::enqueue(ElemFila e)
{
	if (!qIsFull())
	{
		this->e[this->fim++] = e;
		this->fim = this->fim % TAM_FILA;
		this->qtde++;
	}
	else
		cout << "oveflow - Estouro de Fila";
}
// remove um ElemFilaento do final da fila
ElemFila FilaCircular::dequeue()
{
	ElemFila aux;
	if (!qIsEmpty())
	{
		aux = this->e[this->inicio];
		this->inicio = ++this->inicio % TAM_FILA;
		this->qtde--;
		return aux;
	}
	else
	{
		cout << "underflow - Esvaziamento de Fila";
	}
}
// retorna quem está no início da fila
// caso a fila não esteja vazia
ElemFila FilaCircular::front()
{
	if (!qIsEmpty())
		return e[inicio];
	else
	{
		cout << "underflow - Esvaziamento de Fila";
	}
}
// retorna quem está no final da fila caso ela não esteja vazia
ElemFila FilaCircular::rear()
{
	if (!qIsEmpty())
	{
		int final = this->fim - 1;
		return this->e[final];
	}
	else
	{
		cout << "underflow - Esvaziamento de Fila";
	}
}

// Retorna o total de ElemFilaentos da fila
int FilaCircular::size()
{
	return qtde;
}