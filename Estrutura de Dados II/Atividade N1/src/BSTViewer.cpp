#include "BSTViewer.h"

void BSTViewer::Menu(ArvoreBST& bst)
{
	int option;
	//bst.printDadosArvore();
	std::cout << "Bem vindo ao FCRDB (Food Csv Reader And DB)!" << std::endl;
	std::list<std::string> list;
	list.push_back("Apple");
	list.push_back("Grapes");
	bst.gerarInformacoesNutricionais(list);

	// Criar opcao que soma a porra toda 
}
