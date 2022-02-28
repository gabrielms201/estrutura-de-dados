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
#include <stdarg.h> 
using namespace std;

// Tipo e tamanho da pilha

// Class Pilha
template <class T, size_t size>
class Pilha 
{
public:
	void Init();
	bool IsEmpty();
#define Push(...) m_Push(__VA_ARGS__, NULL)
	void m_Push(T element, ...);
	T Pop();
	T Topo();
	bool IsFull();
	int Size();
	void Print();
	~Pilha();
	
private: 
	int _topo;
	T _pilha[size];
};



template<class T, size_t size>
inline void Pilha<T, size>::Init()
{
	_topo = -1;
}

template<class T, size_t size>
inline bool Pilha<T, size>::IsEmpty()
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

template<class T, size_t size>
inline void Pilha<T, size>::m_Push(T element, ...)
{
	va_list elements;
	for (va_start(elements, element); element != NULL; element = va_arg(elements, T))
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
	
}

template<class T, size_t size>
inline T Pilha<T, size>::Pop()
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

template<class T, size_t size>
inline T Pilha<T, size>::Topo()
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

template<class T, size_t size>
inline bool Pilha<T, size>::IsFull()
{
	if (_topo == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T, size_t size>
inline int Pilha<T, size>::Size()
{
	return _topo + 1;
}

template<class T, size_t size>
inline void Pilha<T, size>::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << _pilha[i];
		if (i != size - 1)
		{
			cout << ", ";
		}
	}
}

template<class T, size_t size>
inline Pilha<T, size>::~Pilha()
{

}

#endif // #ifndef PILHA_H
