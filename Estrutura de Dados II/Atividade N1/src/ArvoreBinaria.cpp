#include "ArvoreBinaria.h"
// Classe: No
// Constructor
No::No(Food food)
    : dado(food), esq(NULL), dir(NULL)
{
    chave = dado.getFoodAndServing();
}

// Classe: Arvore BST
// Constructor
ArvoreBST::ArvoreBST()
    : raiz(NULL)
{
}

// Metodos
void ArvoreBST::inserir(Food food)
{
    if (raiz == NULL)
        raiz = new No(food);
    else
        inserirAux(raiz, food);
}

void ArvoreBST::inserirAux(No* no, Food food)
{
    std::string chave = food.getFoodAndServing();
    // se for menor, entao insere na sub-�rvore � esquerda
    if (chave < no->getChave())
    {
        // verifica se nao tem filho a esquerda: achou local de inser��o 
        if (no->getEsq() == NULL)
        {
            No* novo_no = new No(food);
            no->setEsq(novo_no); // add o novo_no na esquerda do no atual
        }
        else
        {
            // senao, continua percorrendo recursivamente para esquerda
            inserirAux(no->getEsq(), food);
        }
    }
    // se for maior, entao insere na sub-arvore da direita
    else if (chave > no->getChave())
    {
        // verifica se nao tem filho a direita: achou local de inser��o
        if (no->getDir() == NULL)
        {
            No* novo_no = new No(food);
            no->setDir(novo_no); // add o novo_no � direita do n� atual
        }
        else
        {
            // senao, continua percorrendo recursivamente para direita
            inserirAux(no->getDir(), food);
        }
    }
    // se a chave for igual a alguma presente na arvore, nao vamos inserir
    // nao pode existir 2 chaves iguais na nossa BST
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
//Pesquisa: Versao iterativa
No* ArvoreBST::Pesquisar(std::string dado, No* no) const
{
    if (raiz == NULL) return NULL; //arvore vazia
    No* atual = no;  // cria ptr aux (atual) e comeca a procurar
    while (atual->getChave() != dado)
    {
        if (dado < atual->getChave())
            atual = atual->getEsq(); // caminha para esquerda
        else
            atual = atual->getDir(); // caminha para direita
        if (atual == NULL)
            return NULL; // encontrou uma folha e nao encontrou a chave
    }
    return atual; //encontrou o dado
}
//Pesquisa: Versao recursiva
No* ArvoreBST::PesquisarRec(No* r, std::string k) const
{
    if (r == NULL || r->getChave() == k)
        return r;
    if (r->getChave() > k)
        return PesquisarRec(r->getEsq(), k);
    else
        return PesquisarRec(r->getDir(), k);
}

//Versao recursiva
//Uma arvore nao vazia tem 1 nos raiz + x nos na sub-arvore na esq + y nos na sub-arvore da dir
int ArvoreBST::contarNos(No* atual) const
{
    if (atual == NULL)  return 0;
    else return (1 + contarNos(atual->getEsq()) + contarNos(atual->getDir()));
}

// versao recursiva
int ArvoreBST::altura(No* atual) const
{
    if (atual == NULL)
        return -1; //�rvore ou sub-arvore vazia: altura = -1
    else
    {
        if (atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0; //�vore com apenas 1 no, altura = 0
        else
        { //altura da �rvore � a altura da sub-�rvore de maior altura
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return (1 + altura(atual->getEsq()));
            else
                return (1 + altura(atual->getDir()));
        }
    }
}
//versao A
No* ArvoreBST::excluir(No* t, std::string key)
{
    //Arvore t vazia
    if (t == NULL)
        return t;

    if (key < t->getChave())
        t->setEsq(excluir(t->getEsq(), key));
    else
        if (key > t->getChave())
            t->setDir(excluir(t->getDir(), key));

    //encontramos o no a ser removido
        else
        {
            //Caso1: o no a ser excluido nao tem filhos
            if (t->getEsq() == NULL && t->getDir() == NULL)
            {
                delete(t);
                return NULL; //faz o pai apontar para NULL e o n� n�o faz mais parte da BST	
            }
            else
                //Caso2: tem apenas um filho, a esquerda ou a direita
                if (t->getEsq() == NULL)
                {
                    No* temp = t->getDir();
                    delete(t);
                    return temp; //Faz o pai apontar para o �nico filho do n�
                }
                else
                    if (t->getDir() == NULL)
                    {
                        No* temp = t->getEsq();
                        delete(t);
                        return temp; //Faz o pai apontar para o �nico filho do n�
                    }

            //Caso3: o no a ser excluido tem 2 filhos. Vamos escolher o menor dos maiores
            //para substituir o no que sera removido. Sucessor = menor no na sub-arvore da direita

            No* temp = findMin(t->getDir());

            //Copia a chave do sucessor para o no que esta sendo removido
            t->setChave(temp->getChave());

            //Remove da arvore o sucessor!
            t->setDir(excluir(t->getDir(), temp->getChave()));
        }

    //retorna a raiz da arvore
    return t;
}

int ArvoreBST::folhas(No* atual) const
{
    if (atual == NULL) return 0;
    if (atual->getEsq() == NULL && atual->getDir() == NULL) return 1;
    return folhas(atual->getEsq()) + folhas(atual->getDir());
}

std::string ArvoreBST::min() const
{
    No* atual = raiz;
    No* anterior = NULL;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->getEsq();
    }
    if (anterior == NULL)
        return "null";
    return anterior->getChave();
}
// Iterativo
std::string ArvoreBST::max() const
{
    No* atual = raiz;
    No* anterior = NULL;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->getDir();
    }
    if (anterior == NULL)
        return "null";
    return anterior->getChave();
}
//recursivo
No* ArvoreBST::findMin(No* t) const
{
    if (t == NULL)
        return NULL;
    else if (t->getEsq() == NULL)
        return t;
    else
        return findMin(t->getEsq());
}
// recursivo
No* ArvoreBST::findMax(No* t) const
{
    if (t == NULL)
        return NULL;
    else if (t->getDir() == NULL)
        return t;
    else
        return findMax(t->getDir());
}

void ArvoreBST::infs(No* r)
{
    No* aux;
    cout << "\nInformacoes gerais da arvore: \n";
    cout << "\n Altura da arvore: " << altura(raiz);
    cout << "\n Quantidade de folhas: " << folhas(raiz);
    cout << "\n Quantidade de Nos: " << contarNos(raiz);
    if (raiz != NULL)    // se arvore nao esta vazia
    {
        aux = findMin(r);
        cout << "\n Valor minimo: " << aux->getChave();
        aux = findMax(r);
        cout << "\n Valor maximo: " << aux->getChave();
    }
}

void ArvoreBST::printDadosArvore()
{
    printDadosArvore(raiz);
}
void ArvoreBST::printDadosArvore(No* no)
{
    if (no != NULL)
    {
        printDadosArvore(no->getEsq());
        cout << no->getDado() << std::endl;
        printDadosArvore(no->getDir());
    }
}

// print2D
void ArvoreBST::print() const
{
    print(raiz, 0);
}

void ArvoreBST::print(No* no, int space) const
{
    if (no != NULL)
    {
        print(no->getDir(), space + 5);
        for (int k = 0; k < space; ++k)
            cout << " ";
        cout << no->getChave() << "\n";
        print(no->getEsq(), space + 5);
    }
}

void ArvoreBST::gerarInformacoesNutricionais(std::list<std::string> meal)
{
    for (list<std::string>::iterator it = meal.begin(); it != meal.end(); it++)
    {

        No* no = Pesquisar(*it, raiz);
        if (no == NULL)
        {
            std::cout << "Alimento " << *it << " nao encontrado na arvore!" << std::endl;
            continue;
        }
        Food food = no->getDado();
        std::cout << "Dados do alimento: " << *it << std::endl << food << std::endl;
    }
}

// Overloads!!
std::ostream& operator<<(std::ostream& os, const ArvoreBST& tree)
{
    No* aux;
    os << "\nInformacoes gerais da arvore: \n";
    os << "\n Altura da arvore: " << tree.altura(tree.raiz);
    os << "\n Quantidade de folhas: " << tree.folhas(tree.raiz);
    os << "\n Quantidade de Nos: " << tree.contarNos(tree.raiz);
    if (tree.raiz != NULL)    // se arvore nao esta vazia
    {
        aux = tree.findMin(tree.raiz);
        os << "\n Valor minimo: " << aux->getChave();
        aux = tree.findMax(tree.raiz);
        os << "\n Valor maximo: " << aux->getChave();
    }
    return os;
}
