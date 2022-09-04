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
		cout << "\n ----5: Sair do programa\n";
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
			No* resultado = arv.pesquisarRec(x);
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
			break;
		}

		default:
			cout << "\n Opcao invalida! \n\n\n";
		} // fim switch
	} while (opcao != 5);


	return 0;
}