#include "ArvoreBinaria.h"
using namespace std;

// No
No::No(int dado)
	: esq(NULL), dir(NULL), chave(dado)
{

}

// ArvoreBST
// Arvore BST esta sendo inicializada pelo metodo ArvoreBST
ArvoreBST::ArvoreBST()
	: raiz(NULL)
{

}
//const -> não altera atributo
// Implementacao de metodos:
// TIPO_RETORNO CLASSE::NOME_DO_METODO(TIPO_PARAMETRO NOME_PARAMETRO, ...) 

void ArvoreBST::inserir(int chave)
{
	if (raiz == NULL) // verifica se a �rvore est� vazia
		raiz = new No(chave); // cria um novo n�
	else
		inserirAux(raiz, chave);
}

void ArvoreBST::inserirAux(No* no, int chave) const
{
	// se for menor, ent�o insere � esquerda
	
	if (chave < no->getChave())
	{
		// verifica se a esquerda � nulo
		if (no->getEsq() == NULL)
		{
			No* novo_no = new No(chave);
			no->setEsq(novo_no); // seta o novo_no � esquerda
		}
		else
		{
			// sen�o, continua percorrendo recursivamente
			inserirAux(no->getEsq(), chave);
		}
	}
	// se for maior, ent�o insere � direita
	else if (chave > no->getChave())
	{
		// verifica se a direita � nulo
		if (no->getDir() == NULL)
		{
			No* novo_no = new No(chave);
			no->setDir(novo_no); // seta o novo_no � direita
		}
		else
		{
			// sen�o, continua percorrendo recursivamente
			inserirAux(no->getDir(), chave);
		}
	}
	// se for igual, n�o vai inserir
	// n�o pode existir 2 chaves iguais
}

void ArvoreBST::emOrdem(No* no) const
{
	if (no != NULL)
	{
		emOrdem(no->getEsq());
		cout << no->getChave() << " ";
		emOrdem(no->getDir());
	}
}

void ArvoreBST::preOrdem(No* no) const
{
	if (no != NULL)
	{
		cout << no->getChave() << " ";
		preOrdem(no->getEsq());
		preOrdem(no->getDir());
	}
}

void ArvoreBST::posOrdem(No* no) const
{
	if (no != NULL)
	{
		posOrdem(no->getEsq());
		posOrdem(no->getDir());
		cout << no->getChave() << " ";

	}
}

No* ArvoreBST::pesquisarRec(int chave) const
{
	return pesquisarRecAux(raiz, chave);
}

No* ArvoreBST::pesquisarRecAux(No* no, int chave) const
{
	if (no == NULL)
	{
		return NULL;
	}
	No* aux = no;
	if (chave > no->getChave()) 
	{
		aux = pesquisarRecAux(no->getDir(), chave);
	}
	else if (chave < no->getChave())
	{
		aux = pesquisarRecAux(no->getEsq(), chave);
	}
	return aux;
}

No* ArvoreBST::pesquisarIter(int chave) const
{
	No* no = raiz;
	while (no != nullptr && no->getChave() != chave)
	{
		if (chave > no->getChave())
		{
			no = no->getDir();
		}
		else
		{
			no = no->getEsq();
		}
	}
	return no;
}

int ArvoreBST::qdeNos() const
{
	return qdeAux(raiz);
}

int ArvoreBST::qdeAux(No* no) const
{
	if (no != NULL)
	{
		return 1 + qdeAux(no->getEsq()) + qdeAux(no->getDir());
	}
	else
	{
		return 0;
	}
}

int ArvoreBST::alturaBST() const
{
	return alturaBSTAux(raiz) - 1;
}

int ArvoreBST::alturaBSTAux(No* no) const
{
	if (no == NULL)
	{
		return 0;
	}
	int esq = alturaBSTAux(no->getEsq());
	int dir = alturaBSTAux(no->getDir());
	if (esq > dir)
	{
		return esq + 1;
	}
	else
	{
		return dir + 1;
	}
}

int ArvoreBST::min() const
{
	int chave = raiz->getChave();
	minAux(raiz, &chave);
	return chave;
}
void ArvoreBST::minAux(No* no, int* min) const
{
	if (no != NULL)
	{
		if (no->getChave() < *min)
		{
			*min = no->getChave();
		}
		minAux(no->getEsq(), min);
	}
}

int ArvoreBST::max() const
{
	int chave = raiz->getChave();
	maxAux(raiz, &chave);
	return chave;
}

void ArvoreBST::maxAux(No* no, int* max) const
{
	if (no != NULL)
	{
		if (no->getChave() > *max)
		{
			*max = no->getChave();
		}
		maxAux(no->getDir(), max);
	}
}

void ArvoreBST::folhas() const
{
	return folhasAux(raiz);
}

void ArvoreBST::folhasAux(No* no) const
{
	if (no != NULL)
	{
		folhasAux(no->getEsq());
		folhasAux(no->getDir());
		if (no->getEsq() == NULL && no->getDir() == NULL)
		{
			cout << no->getChave() << " ";
		}
	}

}
int ArvoreBST::removerFolha(int chave)
{
	No* no = removerFolhaAux(raiz, chave);
	return 1;
}
No* ArvoreBST::removerFolhaAux(No* no, int chave)
{
	if (no == NULL)
	{
		return 0;
	}
	if (chave > no->getChave())
	{
		no->setDir(removerFolhaAux(no->getDir(), chave));
		return no;
	}
	else if (chave < no->getChave())
	{
		no->setEsq(removerFolhaAux(no->getEsq(), chave));
		return no;
	}

	if (no->getDir() == NULL && no->getEsq() == NULL)
	{
		delete no;
		no = NULL;
		return no;
	}
}


