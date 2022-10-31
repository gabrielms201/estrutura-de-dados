// mainAVL.cpp
#include <iostream>
#include <string>
#include "Produto.h"
#include "AVL.h"


void CalculateProductInventoryValue(AVL* avl)
{
	int codigo;
	std::cout << "Inserir codigo do produto: ";
	std::cin >> codigo;

	NodeAVL* node = avl->Search(codigo);
	if (!node)
	{
		std::cout << "Produto nao encontrado! ";
		return;
	}
	std::cout << "Produto encontrado: " << std::endl;
	Produto produto = node->GetData();
	double valorTotal = produto.qtde * produto.valorUnitario;
	std::cout << "Dados do produto: " << produto << std::endl << "Valor Total: " << valorTotal;
}

void CalculateInventoryTotalValue(AVL* avl)
{
	auto allProducts = avl->StorageAllProductsIntoAList();
	double sum = 0;
	for (auto it = allProducts.begin(); it != allProducts.end(); it++)
	{
		sum += it->valorUnitario * it->qtde;
	}
	std::cout << "Valor total do inventario: R$:" << sum << std::endl;
}
void CalculateInferiorValueProducts(AVL* avl)
{
	int filter = 0;
	std::cout << "Digite a quantidade de estoque para ver produtos com estoque menor: " << std::endl;
	std::cin >> filter;

	auto allProducts = avl->StorageAllProductsIntoAList();
	for (auto it = allProducts.begin(); it != allProducts.end(); it++)
	{
		if (it->qtde < filter)
		{
			std::cout << *it << std::endl;
		}
	}
}

Produto CreateProduct()
{
	int codigo;
	int qde;
	float valorUnitario;
	std::string nome;

	std::cin.ignore();
	std::cout << "Inserir nome do produto: ";
	std::getline(std::cin, nome);
	std::cout << "Inserir codigo do produto: ";
	std::cin >> codigo;
	std::cout << "Inserir Quantidade: ";
	std::cin >> qde;
	std::cout << "Inserir Valor Unitario: ";
	std::cin >> valorUnitario;
	Produto produto = Produto(codigo, nome, qde, valorUnitario);
	return produto;

}
void Insert(AVL* avl)
{
	Produto produto = CreateProduct();
	NodeAVL* node = avl->Insert(produto);
	if (node)
		std::cout << "Node inserted!\n";
	else
		std::cout << "*** ERROR! Couldn't insert node!\n";
}

void Remove(AVL* avl)
{
	int num;
	std::cout << "Remove number: ";
	std::cin >> num;
	avl->Remove(num);
}

void Search(AVL* avl)
{
	int num;
	std::cout << "Search number: ";
	std::cin >> num;
	NodeAVL* node = avl->Search(num);
	if (node)
		std::cout << "Node found:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find node!\n";
}

void Predecessor(AVL* avl)
{
	int num;
	std::cout << "Find predecessor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Predecessor(num);
	if (node)
		std::cout << "Predecessor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no predecessor of " << num << "!\n";
}

void Successor(AVL* avl)
{
	int num;
	std::cout << "Find successor of: ";
	std::cin >> num;
	NodeAVL* node = avl->Successor(num);
	if (node)
		std::cout << "Successor of " << num << ":\n" << node->ToString();
	else
		std::cout << "*** ERROR! There is no successor of " << num << "!\n";
}

void FindMin(AVL* avl)
{
	NodeAVL* node = avl->FindMin();
	if (node)
		std::cout << "Minimum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find minimum (tree is probably empty...)\n";
}

void FindMax(AVL* avl)
{
	NodeAVL* node = avl->FindMax();
	if (node)
		std::cout << "Maximum:\n" << node->ToString();
	else
		std::cout << "*** ERROR! Couldn't find maximum (tree is probably empty...)\n";
}

void TraverseInOrder(AVL* avl)
{
	std::cout << avl->TraverseInOrder() << '\n';
}

void TraversePreOrder(AVL* avl)
{
	std::cout << avl->TraversePreOrder() << '\n';
}

void TraversePostOrder(AVL* avl)
{
	std::cout << avl->TraversePostOrder() << '\n';
}

void Clear(AVL* avl)
{
	avl->Clear();
}

int main()
{

	AVL* avl = new AVL();

	int option = 0;
	do
	{
		std::cout << "*** AVL Tree ***\n"
			<< "[1] Insert (opcao 1)\n"
			<< "[2] Remove\n"
			<< "[3] Search\n"
			<< "[4] Predecessor\n"
			<< "[5] Successor\n"
			<< "[6] Find minimum\n"
			<< "[7] Find maximum\n"
			<< "[8] Traverse in-order (opcao 2)\n"
			<< "[9] Traverse pre-order\n"
			<< "[10] Traverse post-order\n"
			<< "[11] Clear\n"
			<< "[12] Valor do produto em Estoque (opcao 3)\n"
			<< "[13] Valor do Estoque (opcao 4)\n"
			<< "[14] Valores inferiores (opcao 5)\n"
			<< "[0] Exit (opcao 6)\n"
			<< "Option: ";
		std::cin >> option;
		std::cout << '\n';

		switch (option)
		{
		case 1: Insert(avl); break;
		case 2: Remove(avl); break;
		case 3: Search(avl); break;
		case 4: Predecessor(avl); break;
		case 5: Successor(avl); break;
		case 6: FindMin(avl); break;
		case 7: FindMax(avl); break;
		case 8: TraverseInOrder(avl); break;
		case 9: TraversePreOrder(avl); break;
		case 10: TraversePostOrder(avl); break;
		case 11: Clear(avl); break;
		case 12: CalculateProductInventoryValue(avl); break;
		case 13: CalculateInventoryTotalValue(avl); break;
		case 14: CalculateInferiorValueProducts(avl); break;
		}

		std::cout << '\n';
	} while (option != 0);

	delete avl;
}
//#endif
