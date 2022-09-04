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
	No* pesquisarRec(int chave); //Versão Recursiva
	No* pesquisarIter(int chave); //Versão Iterativa
	int qdeNos();
	int alturaBST();
	int min(); //menor chave presente na BST
	int max(); //maior chave presente na BST
	int folhas(); //imprimir as chaves, em ordem crescente, dos nós folhas da BST
	int removerFolha(int chave);

	

	// Getters
	No* getRaiz() const { return raiz; }

};