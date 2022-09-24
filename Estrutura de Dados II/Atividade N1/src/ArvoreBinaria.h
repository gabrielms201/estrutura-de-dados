#pragma once

#include <iostream>
#include <ostream>
using namespace std;

// No
class No
{
private:
    No* esq, * dir;
    int chave;

public:
    No(int chave);
    // funcoes getters e setters
    int getChave() const { return chave; }
    No* getEsq() const { return esq; }
    No* getDir() const { return dir; }
    void setEsq(No* no) { esq = no; }
    void setDir(No* no) { dir = no; }
    void setChave(int k) { chave = k; }
};

// ArvoreBST
class ArvoreBST
{
private:
    No* raiz;

public:
    ArvoreBST();
    // Setters
    void setRaiz(No* root) { raiz = root; }
    // Getters
    No* getRaiz() const { return raiz; }
    // Methods
    void inserir(int chave);
    void inserirAux(No* no, int chave);
    void emOrdem(No* no) const;
    void preOrdem(No* no) const;
    void posOrdem(No* no) const;
    No* Pesquisar(int dado, No* no) const;
    No* PesquisarRec(No* r, int k) const;
    int contarNos(No* atual) const;
    int altura(No* atual) const;
    No* excluir(No* t, int key);
    int folhas(No* atual) const;
    int min() const;
    int max() const;
    No* findMin(No* t) const;
    No* findMax(No* t) const;
    void infs(No* r);
    void print() const;
    void print(No* no, int space) const;

    // Friends :)
    friend ostream &operator<<(ostream &os, const ArvoreBST &bst);
};