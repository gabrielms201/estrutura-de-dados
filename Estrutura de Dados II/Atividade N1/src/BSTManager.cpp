// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#include "BSTManager.h"
BSTManager::BSTManager(CsvManager& csvManager, ArvoreBST* bst) :
	_csvManager(csvManager), _bst(bst)
{
}
/// <summary>
//  Imprime o menu na tela
/// </summary>
void BSTManager::Menu()
{
	int option = 999;
	std::cout << "Bem vindo ao FCRDB (Food Csv Reader And DB)!" << std::endl;
	do
	{
		std::cout << "\t\t==============" << std::endl;
		std::cout << "\t\t< FCRDB Menu >" << std::endl;
		std::cout << "\t\t==============" << std::endl;
		std::cout << "1-  ~> Consultar refeicao." << std::endl;
		std::cout << "2-  ~> Informacoes da Arvore." << std::endl;
		std::cout << "3-  ~> Visualizar alimentos armazenados. " << std::endl;
		std::cout << "4-  ~> Visualizar tabela nutricional de todos os alimentos armazenados. " << std::endl;
		std::cout << "5-  ~> Visualizar todos os nos." << std::endl;
		std::cout << "6-  ~> Print 2D." << std::endl;
		std::cout << "7-  ~> Remover alimento da base de dados." << std::endl;
		std::cout << "8-  ~> Limpar arvore." << std::endl;
		std::cout << "9-  ~> Salvar informacoes da arvore no arquivo de backup." << std::endl;
		std::cout << "10- ~> Carregar arquivo de Backup" << std::endl;
		std::cout << "0-  ~> Sair." << std::endl;
		std::cout << "$ ";
		std::cin.clear();
		std::cin >> option;
		switch (option)
		{
		case 1: // Consultar refeicao
		{
			int qty = 0;
			std::cout << "Por favor, informe a quantidade de alimentos da sua refeicao: " << std::endl;
			std::cin >> qty;
			std::cin.ignore();
			std::list<std::string> meal;
			std::string currentFood;
			for (int i = 0; i < qty; i++)
			{
				std::cout << "Informe a refeicao n" << i + 1 << " :" << std::endl;
				std::cout << "$ ";
				getline(std::cin, currentFood);
				meal.push_back(currentFood);
			}
			// Imprime as informacoes nutricionais da refeicao
			_bst->gerarInformacoesNutricionais(meal);
			std::cout << "Total consumido: ";
			_bst->imprimirTotalConsumido(meal);
			Freeze();
			break;
		}
		case 2: // Informacoes da arvore
		{
			std::cout << *_bst;
			Freeze();
			break;
		}
		case 3: // Imprime chaves em ordem
		{
			_bst->emOrdem(_bst->getRaiz());
			Freeze();
			break;
		}
		case 4: // Tabelas nutricionais
		{
			_bst->printDadosArvore();
			Freeze();
			break;
		}
		case 5: // Visualizar todos os nos
		{
			_bst->checkNodes();
			Freeze();
			break;
		}
		case 6: // Print 2D
		{
			_bst->print();
			Freeze();
			break;
		}
		case 7: // Excluir
		{
			std::cout << "Por favor, informe o alimento que deseja remover: " << std::endl;
			cin.ignore();
			string foodToDelete;
			std::getline(std::cin, foodToDelete);
			_bst->excluir(foodToDelete);
			Freeze();
			break;
		}
		case 8: // Clear
		{
			std::cout << "LIMPANDO ARVORE!!" << std::endl;
			_bst->clear();
			Freeze();
			break;
		}
		case 9: // Salvar
		{
			_csvManager.SaveBackup();
			Freeze();
			break;
		}
		case 10: // Carregar
		{
			_bst->clear();
			_csvManager.OpenFileAndStorage(CsvType::BACKUP);
			Freeze();
			break;
		}
		case 0: // SAir
		{
			break;
		}
		default:
			int clear = CLEAR_SCREAM();
			break;
		}
	} while (option != 0);


}

void BSTManager::Freeze()
{
	std::cout << std::endl << "Digite uma tecla para continuar: " << std::endl;
	std::cin.ignore();
	std::cin.get();
	int clear = CLEAR_SCREAM();
}

