#ifndef LISTA_H
#define LISTA_H

#if !(__cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900))
    #define nullptr NULL
#endif

#include "Paciente.h"
#include <string>
#include <ostream>
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
    bool Insert(TYPE& data);
    bool Remove(TYPE& data);
    void Clear();
    bool Find(const TYPE& data) const;
    TYPE& FindByPosition(unsigned int position) const;
    unsigned int FindPosition(TYPE& data) const;
    unsigned int GetSize() const { return _size; }
    string ToString() const;
private:
    unsigned int _size;
    Node* _head;
    Node* _tail;
};
inline ostream& operator <<(ostream& str, const Lista& lista)
{
    return str << lista.ToString();
}

#endif