// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#ifndef ARVORE_BINARIA_HEADER
#define ARVORE_BINARIA_HEADER

#include <iostream>
#include <ostream>
#include <string>
#include <list>
#include "Food.h"
using namespace std;

// No
class No
{
private:
    No* esq, * dir, * parent;
    std::string chave;
    Food dado;
    int _balanceFactor;

public:
    No(Food food, No* parent = NULL);
    // funcoes getters e setters
    std::string getChave() const { return chave; }
    No* getEsq() const { return esq; }
    No* getDir() const { return dir; }
    No* getParent() const { return parent;  };
    void setParent(No* no) { parent = no; }
    Food getDado() const { return dado; }
    int getBalanceFactor() const { return _balanceFactor; }
    void setEsq(No* no) { esq = no; }
    void setDir(No* no) { dir = no; }
    void setChave(std::string k) { chave = k; }
    void setDado(Food& dado) { this->dado = dado; }
    void updateBalanceFactor();
    int calculateHeight(const No* no) const;
    bool isLeaf() const;
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
    void inserir(Food food);
    No* inserirAux(No* no, No* parent, Food food);
    void emOrdem(No* no) const;
    void preOrdem(No* no) const;
    void posOrdem(No* no) const;
    No* Pesquisar(std::string dado, No* no) const;
    No* PesquisarRec(No* r, std::string k) const;
    int contarNos(No* atual) const;
    int altura(No* atual) const;
    No* excluir(No* t, std::string key);
    int folhas(No* atual) const;
    std::string min() const;
    std::string max() const;
    No* findMin(No* t) const;
    No* findMax(No* t) const;
    void infs(No* r);
    void printDadosArvore();
    void printDadosArvore(No* no);
    void print() const;
    void print(No* no, int space) const;
    void gerarInformacoesNutricionais(std::list<std::string> meal);
    void imprimirTotalConsumido(std::list<std::string> meal);
    
    // Avl methods
    void updateParentChild(No* parent, const No* child, No* newChild);
    No* balance(No* no);
    No* rotateLeft(No* no);
    No* rotateRight(No* no);
    No* rotateLeftRight(No* no);
    No* rotateRightLeft(No* no);
    void checkNodes() const;
    void checkNodes(No* no) const;



    // Friend operator para o overload do operador bitwise
    friend ostream &operator<<(ostream &os, const ArvoreBST &bst);
};

#endif