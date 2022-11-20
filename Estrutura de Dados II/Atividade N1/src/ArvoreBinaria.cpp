// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#include "ArvoreBinaria.h"
// Classe: No
// Constructor
No::No(Food food, No* parent)
    : dado(food), esq(NULL), dir(NULL), _balanceFactor(0), parent(parent)
{
    chave = dado.getFoodAndServing();
}

void No::updateBalanceFactor()
{
    int leftHeight = esq == NULL ? -1 : calculateHeight(esq);
    int rightHeight = dir == NULL ? -1 : calculateHeight(dir);
    _balanceFactor = rightHeight - leftHeight;
}

int No::calculateHeight(const No* no) const
{
    if (no == NULL || no->isLeaf())
    {
        return 0;
    }
    else
    {
        int left = calculateHeight(no->getEsq());
        int right = calculateHeight(no->getDir());
        int max = left > right ? left : right;
        return 1 + max;
    }
}

bool No::isLeaf() const
{
    return esq == NULL && dir == NULL;
}

// Classe: Arvore BST
// Constructor
ArvoreBST::ArvoreBST()
    : raiz(NULL)
{
}


void ArvoreBST::updateParentChild(No* parent, const No* child, No* newChild)
{
    if (parent != NULL)
    {
        if (parent->getEsq() == child)
            parent->setEsq(newChild);
        else
            parent->setDir(newChild);
    }
    else
    {
        raiz = newChild;
    }

    if (newChild != NULL)
        newChild->setParent(parent);
}

No* ArvoreBST::balance(No* no)
{
    if (no != NULL)
    {
        no->updateBalanceFactor();
        int nodeBF = no->getBalanceFactor();

        // Tree is left heavy.
        //if (nodeBF == 2) // --> Use this if BF=HL-HR.
        if (nodeBF == -2)
        {
            // Get left subtree's height.
            No* left = no->getEsq();
            left->updateBalanceFactor();
            int leftChildBF = left->getBalanceFactor();

            //if (leftChildBF == 1) // --> Use this if BF=HL-HR.
            if (leftChildBF == -1)
                no = rotateRight(no);
            else
                no = rotateLeftRight(no);
        }
        // Tree is right heavy.
        //else if (nodeBF == -2) // --> Use this if BF=HL-HR.
        else if (nodeBF == 2)
        {
            // Get right subtree's height.
            No* right = no->getDir();
            right->updateBalanceFactor();
            int rightChildBF = right->getBalanceFactor();

            //if (rightChildBF == -1) // --> Use this if BF=HL-HR.
            if (rightChildBF == 1)
                no = rotateLeft(no);
            else
                no = rotateRightLeft(no);
        }
    }

    return no;
}

No* ArvoreBST::rotateLeft(No* no)
{
    if (no == NULL) return NULL;

    // The current node must have a right child/subtree.	
    No* newRoot = no->getDir();
    if (newRoot == NULL) return NULL;

    // Swap parent links.
    No* parent = no->getParent();
    updateParentChild(parent, no, newRoot);
    no->setParent(newRoot);

    // Since newRoot is this subtree's new root,
    // its left child becomes the right child of
    // the current node.
    No* left = newRoot->getEsq();
    no->setDir(left);

    // Update the parent of newRoot's left child
    // if there is a left child.
    if (left != NULL)
        left->setParent(no);

    // The new left child of newRoot is the current node.
    newRoot->setEsq(no);

    no->updateBalanceFactor();
    newRoot->updateBalanceFactor();

    return newRoot;
}

No* ArvoreBST::rotateRight(No* no)
{
    if (no == NULL) return NULL;

    // The current node must have a left child/subtree.	
    No* newRoot = no->getEsq();
    if (newRoot == NULL) return NULL;

    // Swap parent links.
    No* parent = no->getParent();
    updateParentChild(parent, no, newRoot);
    no->setParent(newRoot);

    // Since newRoot is this subtree's new root,
    // its right child becomes the left child of
    // the current node.
    No* right = newRoot->getDir();
    no->setEsq(right);

    // Update the parent of newRoot's right child
    // if there is a right child.
    if (right != NULL)
        right->setParent(no);

    // The new right child of newRoot is the current node.
    newRoot->setDir(no);

    no->updateBalanceFactor();
    newRoot->updateBalanceFactor();

    return newRoot;
}

No* ArvoreBST::rotateLeftRight(No* no)
{
    no->setEsq(rotateLeft(no->getEsq()));
    return rotateRight(no);
}

No* ArvoreBST::rotateRightLeft(No* no)
{
    no->setDir(rotateRight(no->getDir()));
    return rotateLeft(no);
}

void ArvoreBST::checkNodes() const
{
    checkNodes(raiz);
    std::cout << "All balance factor OK!!" << std::endl;
}

void ArvoreBST::checkNodes(No* no) const
{
    if (no != NULL)
    {
        checkNodes(no->getEsq());
        int balance = no->getBalanceFactor();


        No* parentNode = no->getParent();
        No* esqNode = no->getEsq();
        No* dirNode = no->getDir();

        string parent = "null";
        string esq = "null";
        string dir = "null";

        // getting all parents
        if (parentNode != NULL)
        {
            parent = parentNode->getChave();
        }
        if (esqNode != NULL)
        {
            esq = esqNode->getChave();
        }
        if (dirNode != NULL)
        {
            dir = dirNode->getChave();
        }


        cout << "Chave: " << no->getChave() 
            << " | Parent: " << parent
            << " | Esq: " << esq
            << " | Dir: " << dir
            << " | Balance: " << balance
            << std::endl;
        if (balance < -1 || balance > 1)
        {
            std::cerr << "FATAL: WRONG AVL IMPLEMENTATION!!!" << std::endl;
            exit(1);
        }
        checkNodes(no->getDir());
    }
}

// Metodos
void ArvoreBST::inserir(Food food)
{
    if (raiz == NULL)
        raiz = new No(food);
    else
        inserirAux(raiz, NULL, food);
}

No* ArvoreBST::inserirAux(No* no, No* parent, Food food)
{
    std::string chave = food.getFoodAndServing();
    if (no == NULL)
        no = new No(food, parent);
    else if (no->getChave() == chave)
    {
        std::cerr << "Impossivel inserir chave duplicada!" << std::endl;
        return NULL;
    }
    else if (chave < no->getChave())
        no->setEsq(inserirAux(no->getEsq(), no, food));
    else if (chave > no->getChave())
        no->setDir(inserirAux(no->getDir(), no, food));
    no = balance(no);
    return no;
}
// imprime em ordem
void ArvoreBST::emOrdem(No* no) const
{
    if (no != NULL)
    {
        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
    }
}
// imprime pre ordem
void ArvoreBST::preOrdem(No* no) const
{
    if (no != NULL)
    {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}
// imprime pos ordem
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
// Ao chamar esse metodo, cada objeto armazenado na arvore eh impresso
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
    // Para cada elemento dentro da lista de refeicao (iterator) - https://cplusplus.com/reference/iterator/
    for (list<std::string>::iterator it = meal.begin(); it != meal.end(); it++)
    {
        // Procura o alimento na BST
        No* no = Pesquisar(*it, raiz);
        if (no == NULL)
        {
            // Se nao encontrar, ira para o proximo
            std::cout << "Alimento " << *it << " nao encontrado na arvore!" << std::endl;
            continue;
        }
        Food food = no->getDado();
        std::cout << "Dados do alimento: " << *it << std::endl << food << std::endl;
    }
}

void ArvoreBST::imprimirTotalConsumido(std::list<std::string> meal)
{
    int caloriesSum = 0;
    int caloriesFromFatSum = 0;
    double totalFatGSum = 0;
    int totalFatDvSum = 0;
    int sodiumGSum = 0;
    int sodiumDvSum = 0;
    int potassiumGSum = 0;
    int potassiumDvSum = 0;
    int totalCarboHydrateGSum = 0;
    int totalCarboHydrateDvSum = 0;
    int dietaryFiberGSum = 0;
    int dieteryFiberDvSum = 0;
    int sugarsGSum = 0;
    int proteinGSum = 0;
    int vitaminADvSum = 0;
    int vitaminCDvSum = 0;
    int calciumDvSum = 0;
    int eeironeeDvSum = 0;
    double saturatedFatDvSum = 0;
    int saturatedFatMgESum = 0;
    int choleSterolDvSum = 0;
    int choleSterolMgESum = 0;
    
    // Para cada elemento dentro da lista de refeicao (iterator) - https://cplusplus.com/reference/iterator/
    for (list<std::string>::iterator it = meal.begin(); it != meal.end(); it++)
    {
        // Procura o alimento na BST
        No* no = Pesquisar(*it, raiz);
        if (no == NULL)
        {
            // Se nao encontrar, ira para o proximo
            continue;
        }
        Food food = no->getDado();
        caloriesSum += food.getCalories();
        caloriesFromFatSum += food.getCaloriesFromFat();
        totalFatGSum += food.getTotalFatG();
        totalFatDvSum += food.getTotalFatDv();
        sodiumGSum += food.getSodiumG();
        sodiumDvSum += food.getSodiumDv();
        potassiumGSum += food.getPotassiumG();
        potassiumDvSum += food.getPotassiumDv();
        totalCarboHydrateGSum += food.getTotalCarboHydrateG();
        totalCarboHydrateDvSum += food.getTotalCarboHydrateDv();
        dietaryFiberGSum += food.getDietaryFiberG();
        dieteryFiberDvSum += food.getDieteryFiberDv();
        sugarsGSum += food.getSugarsG();
        proteinGSum += food.getProteinG();
        vitaminADvSum += food.getVitaminADv();
        vitaminCDvSum += food.getVitaminCDv();
        calciumDvSum += food.getCalciumDv();
        eeironeeDvSum += food.getEeironeeDv();
        saturatedFatDvSum += food.getSaturatedFatDv();
        saturatedFatMgESum += food.getSaturatedFatMgE();
        choleSterolDvSum += food.getCholeSterolDv();
        choleSterolMgESum += food.getCholeSterolMgE();
    }
    std::cout 
        << "Total Consumido: "                                                      << std::endl
        << "calories: "                 << caloriesSum                              << std::endl
        << "caloriesFromFat: "          << caloriesFromFatSum                       << std::endl
        << "totalFatG: "                << totalFatGSum                             << std::endl
        << "totalFatDv: "               << totalFatDvSum                            << std::endl
        << "sodiumG: "                  << sodiumGSum                               << std::endl
        << "sodiumDv:"                  << sodiumDvSum                              << std::endl
        << "potassiumG: "               << potassiumGSum                            << std::endl
        << "potassiumDv: "              << potassiumDvSum                           << std::endl
        << "totalCarboHydrateG: "       << totalCarboHydrateGSum                    << std::endl
        << "totalCarboHydrateDv: "      << totalCarboHydrateDvSum                   << std::endl
        << "dietaryFiberG: "            << dietaryFiberGSum                         << std::endl
        << "dieteryFiberDv: "           << dieteryFiberDvSum                        << std::endl
        << "sugarsG: "                  << sugarsGSum                               << std::endl
        << "proteinG: "                 << proteinGSum                              << std::endl
        << "vitaminADv: "               << vitaminADvSum                            << std::endl
        << "vitaminCDv: "               << vitaminCDvSum                            << std::endl
        << "calciumDv: "                << calciumDvSum                             << std::endl
        << "eeironeeDv: "               << eeironeeDvSum                            << std::endl
        << "saturatedFatDv: "           << saturatedFatDvSum                        << std::endl
        << "saturatedFatMgE: "          << saturatedFatMgESum                       << std::endl
        << "choleSterolDv: "            << choleSterolDvSum                         << std::endl
        << "choleSterolMgE: "           << choleSterolMgESum                        << std::endl;

}

// Overloads!!
// Fizemos isso para facilitar o print da arvore BST.
// Quando aplicamos um operador bitwise na arvore (quando utilizamos o cout), 
// esse trecho de codigo eh chamado
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
