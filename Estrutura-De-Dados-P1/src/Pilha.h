/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/
#ifndef PILHA_H
#define PILHA_H

// Includes && Using Namespace
#include "Errors.h"
using namespace std;

// Class Pilha
template<class TIPO, const unsigned int TAM_PILHA>
class Pilha 
{
public:
	bool IsEmpty();
	void Push(TIPO element);
	TIPO Pop();
	TIPO Topo();
	bool IsFull();
	int Size();
	void Print();
	unsigned int getTotalSize();
	Pilha();
private: 
	int _topo;
	TIPO _pilha[TAM_PILHA];

};

template<class TIPO, unsigned int TAM_PILHA>
inline bool Pilha<TIPO, TAM_PILHA>::IsEmpty()
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

template<class TIPO, unsigned int TAM_PILHA>
inline void Pilha<TIPO, TAM_PILHA>::Push(TIPO element)
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

template<class TIPO, unsigned int TAM_PILHA>
inline TIPO Pilha<TIPO, TAM_PILHA>::Pop()
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

template<class TIPO, unsigned int TAM_PILHA>
inline TIPO Pilha<TIPO, TAM_PILHA>::Topo()
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

template<class TIPO, unsigned int TAM_PILHA>
inline bool Pilha<TIPO, TAM_PILHA>::IsFull()
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

template<class TIPO, unsigned int TAM_PILHA>
inline int Pilha<TIPO, TAM_PILHA>::Size()
{
	return _topo + 1;
}

template<class TIPO, unsigned int TAM_PILHA>
inline void Pilha<TIPO, TAM_PILHA>::Print()
{
	for (int i = 0; i < _topo; i++)
	{
		cout << _pilha[i];
		if (i != _topo - 1)
		{
			cout << ", ";
		}
	}
}

template<class TIPO, unsigned int TAM_PILHA>
inline unsigned int Pilha<TIPO, TAM_PILHA>::getTotalSize()
{
	return TAM_PILHA;
}

template<class TIPO, unsigned int TAM_PILHA>
inline Pilha<TIPO, TAM_PILHA>::Pilha()
{
	_topo = -1;
}

#endif // #ifndef PILHA_H

