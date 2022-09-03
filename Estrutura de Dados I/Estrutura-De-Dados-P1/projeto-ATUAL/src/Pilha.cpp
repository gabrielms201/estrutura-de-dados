/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#include "Pilha.h"

Pilha::Pilha()
{
    this->topoPilha = -1;
}

Pilha::~Pilha() {};

bool Pilha::isEmpty()
{
    if (this->topoPilha == -1)
        return true;
    else
        return false;
}

bool Pilha::isFull()
{
    if (this->topoPilha == TAM_PILHA - 1)
        return true;
    else
        return false;
}

void Pilha::push(Elem e)
{
    if (!this->isFull())
        this->e[++this->topoPilha] = e;
    else
        cout << "overflow - Estouro de Pilha";
}

Elem Pilha::pop()
{
    if (!this->isEmpty())
        return this->e[this->topoPilha--];
    else
    {
        cout << "underflow - Esvaziamento de Pilha";
        return -1;
    }
}

Elem Pilha::topo()
{
    if (!this->isEmpty())
        return this->e[this->topoPilha];
    else
    {
        cout << "underflow - Esvaziamento de Pilha";
        return -1;
    }
}

int Pilha::size()
{
    return topoPilha + 1;
}