/*
ESTRUTURA DE DADOS - P2 - Lista Encadeada
  Grupo:
    Caio Cezar Oliveira Filardi do Carmo        |   TIA: 31891365   |
    Mayara Meneghetti Honda	                    |   TIA: 32152280   |
    Paulo Henrique Braga Cechinel               |   TIA: 32151128   |
    Ricardo Gabriel Marques dos Santos Ruiz     |   TIA: 32134908   |
*/

#ifndef LISTA_H
#define LISTA_H

#if !(__cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900))
    #define nullptr NULL
#endif

#include "Paciente.h"
#include <string>
#include <ostream>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;
typedef Paciente TYPE;
// No

class Node
{
public:
    Node(TYPE& data, Node* nextNode);
    Node();
    ~Node();
    TYPE& GetData() { return _data; }
    Node* GetNextNode() const { return _nextNode; }
    void SetNextNode(Node* node) { _nextNode = node;}
private:
    TYPE _data;
    Node* _nextNode;
};

// Lista
class Lista
{
public:
    Lista();
    ~Lista();
    bool IsEmpty() const;
    bool IsFull() const;
    bool Insert(TYPE& data);                                // O(1)
    bool Remove(TYPE& data);                                // O(n)
    void Clear();                                           // O(n)
    bool Find(const TYPE& data) const;                      // O(n)
    TYPE& FindByPosition(unsigned int position) const;      // O(n)
    unsigned int FindPosition(TYPE& data) const;            // O(n)
    unsigned int GetSize() const { return _size; }
    string ToString() const;
    // Custom Query - [ O (n) ]
    unsigned int GetDeadQuantity() const;
    unsigned int GetCovidDeadQuantity() const;

    
    // Men - Obese
    unsigned int GetMenObeseCovidDead() const;
	unsigned int GetMenObeseCovidNotDead() const;    
	unsigned int GetMenObeseNotCovidDead() const;	
	unsigned int GetMenObeseNotCovidNotDead() const;		
	
	// Men - Diabetic
    unsigned int GetMenDiabeticCovidDead() const;
	unsigned int GetMenDiabeticCovidNotDead() const;    
	unsigned int GetMenDiabeticNotCovidDead() const;	
	unsigned int GetMenDiabeticNotCovidNotDead() const;		
	
	// Men - Icu
    unsigned int GetMenIcuCovidDead() const;
	unsigned int GetMenIcuCovidNotDead() const;    
	unsigned int GetMenIcuNotCovidDead() const;
    unsigned int GetMenIcuNotCovidNotDead() const;


    // Woman - Obese
    unsigned int GetWomanObeseCovidDead() const;
    unsigned int GetWomanObeseCovidNotDead() const;
    unsigned int GetWomanObeseNotCovidDead() const;
    unsigned int GetWomanObeseNotCovidNotDead() const;

    // Woman - Diabetic
    unsigned int GetWomanDiabeticCovidDead() const;
    unsigned int GetWomanDiabeticCovidNotDead() const;
    unsigned int GetWomanDiabeticNotCovidNotDead() const;
    unsigned int GetWomanDiabeticNotCovidDead() const;

    // Woman - Icu
    unsigned int GetWomanIcuCovidDead() const;
    unsigned int GetWomanIcuCovidNotDead() const;
    unsigned int GetWomanIcuNotCovidNotDead() const;
    unsigned int GetWomanIcuNotCovidDead() const;
			
private:
    unsigned int _size;
    Node* _head;
    Node* _tail;
};
// Overload do operador bitwise para facilitar o print da lista
inline ostream& operator <<(ostream& str, const Lista& lista)
{
    return str << lista.ToString();
}

#endif
