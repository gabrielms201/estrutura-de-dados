#include "Pilha.h"

void Pilha::Init()
{
	_topo = -1;
}

bool Pilha::IsEmpty()
{
	if (_topo == -1) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Pilha::Push(TIPO element)
{
	if (!IsFull())
	{
		_pilha[++_topo] = element;
	}
	else
	{
		Errors::AvisoOverFlow();
	}
}

TIPO Pilha::Pop()
{
	if (!IsEmpty())
	{
		return _pilha[_topo--];
	}
	else
	{
		Errors::AvisoUnderFlow();
	}
}

TIPO Pilha::Topo()
{
	if (!IsEmpty()) 
	{
		return _pilha[_topo];
	}
	else
	{
		Errors::AvisoUnderFlow();
		return -1;
	}
}

bool Pilha::IsFull()
{
	if (_topo == TAM_PILHA - 1) 
	{
		return true;
	}
	else
	{
		return false;
	}

}

int Pilha::Size()
{
	return _topo + 1;
}

void Pilha::Print()
{
	for (int i = 0; i < TAM_PILHA; i++)
	{
		cout << _pilha[i];
		if (i != TAM_PILHA - 1) 
		{
			cout << ", ";
		}
	}
}
