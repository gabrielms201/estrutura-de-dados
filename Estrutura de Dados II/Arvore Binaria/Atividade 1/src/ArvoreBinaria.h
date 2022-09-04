#pragma once
#include <iostream>

// .h -> Fazemos as declaracoes aqui, e as implementacoes no .cpp
// Funcoes const -> Utilizamos quando o metodo nao/nao pode vai alterar algum atributo
class No
{
private:
	No* esq, * dir;
	int chave;

public:
	No(int dado);

	// Getters
	int getChave() const { return chave; }
	No* getEsq() const { return esq; }
	No* getDir() const { return dir; }

	// Setters
	void setEsq(No* no) { esq = no; }
	void setDir(No* no) { dir = no; }
};

class ArvoreBST 
{
private:
	No* raiz;

public:
	ArvoreBST();
	void inserir(int chave);
	void inserirAux(No* no, int chave) const;
	void emOrdem(No* no) const;
	void preOrdem(No* no) const;
	void posOrdem(No* no) const;

	// Metodos da atividade
	No* pesquisarRec(int chave) const; //Versão Recursiva
	No* pesquisarRecAux(No* no, int chave) const;
	No* pesquisarIter(int chave) const; //Versão Iterativa
	int qdeNos() const;
	int qdeAux(No* no) const;
	int alturaBST() const;
	int alturaBSTAux(No* no) const;
	int min() const; //menor chave presente na BST
	void minAux(No* no, int* min) const;
	int max() const; //maior chave presente na BST
	void maxAux(No* no, int* max) const;
	int folhas() const; //imprimir as chaves, em ordem crescente, dos nós folhas da BST
	int folhasAux(No* no) const;
	int removerFolha(int chave) const;

	

	// Getters
	No* getRaiz() const { return raiz; }

};