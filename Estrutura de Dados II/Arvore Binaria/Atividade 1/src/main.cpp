#include "main.h"
using namespace std;

int main(int argc, char* argv[])
{
	ArvoreBST arv;
	int opcao, x;
	cout << ("\nTestando o TAD BST (Elementos do tipo int)\n");
	do {
		cout << "\n\n";
		cout << "\n***********************************";
		cout << "\n\tMenu - Arvore BST\n";
		cout << "\nEntre com a opcao:";
		cout << "\n ----1: Inserir";
		cout << "\n ----2: Excluir";
		cout << "\n ----3: Pesquisar";
		cout << "\n ----4: Imprimir em ordem";
		cout << "\n ----5: Quantidade de nos";
		cout << "\n ----6: Altura da BST";
		cout << "\n ----7: Menor chave presente";
		cout << "\n ----8: Maior chave presente";
		cout << "\n ----9: Imprimir as chaves dos nos folhas em ordem crescente";
		cout << "\n ----10: Remover uma folha";
		cout << "\n ----0: Sair do programa\n";
		cout << "\n***********************************";
		cout << "\n-> ";
		cin >> opcao;
		switch (opcao) {
		case 1: {
			cout << "\n Informe o valor (int) -> ";
			cin >> x;
			arv.inserir(x);
			break;
		}
		case 2: {
			cout << "\n Ainda nao implementado! ";

			break;
		}
		case 3: {
			cout << "\n Informe o valor (int) -> ";
			cin >> x;
			cout << "\n Resultado da pesquisa: \n";
			int opcao;
			cout << " 1- Pesquisa recursiva\n";
			cout << " 2- Pesquisa iterativa\n";
			cin >> opcao;
			No* resultado = NULL;
			if (opcao == 1)
			{
				resultado = arv.pesquisarRec(x);
			}
			else
			{
				resultado = arv.pesquisarIter(x);
			}
			
			if (resultado == NULL)
			{
				cout << " No nao encontrado" << endl;
			}
			else 
			{
				cout << " Chave do no: " << resultado->getChave() << endl;
				cout << " Endereco do no: " << resultado << endl;
			}
			break;
		}
		case 4: {
			cout << "Percorrendo em ordem...\n";
			arv.emOrdem(arv.getRaiz());
			break;
		}
		case 5: {
			cout << "Quantidade de nos:\n";
			cout << arv.qdeNos();
			break;
		}
		case 6: {
			cout << " Altura da BST:\n";
			cout << arv.alturaBST();
			break;
		}
		case 7: {
			cout << " Menor chave presente:\n";
			cout << arv.min();
			break;
		}
		case 8: {
			cout << " Maior chave presente:\n";
			cout << arv.max();
			break;
		}
		case 9: {
			cout << " Folhas: \n";
			arv.folhas();
			break;
		}
		case 10:
		{
			cout << " Digite a chave da folha: ";
			cin >> x;
			cout << " Removendo folha...\n";
			arv.removerFolha(x);
			break;
		}
		case 0: {
			break;
		}

		default:
			cout << "\n Opcao invalida! \n\n\n";
		} // fim switch
	} while (opcao != 0);


	return 0;
}