// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#include "BSTViewer.h"
/// <summary>
/// Imprime o menu na tela
/// </summary>
/// <param name="bst"></param>
void BSTViewer::Menu(ArvoreBST& bst)
{
	int option = 999;
	std::cout << "Bem vindo ao FCRDB (Food Csv Reader And DB)!" << std::endl;
	do
	{
		std::cout << "\t\t==============" << std::endl;
		std::cout << "\t\t< FCRDB Menu >" << std::endl;
		std::cout << "\t\t==============" << std::endl;
		std::cout << "1- ~> Consultar refeicao." << std::endl;
		std::cout << "2- ~> Informacoes da Arvore." << std::endl;
		std::cout << "3- ~> Visualizar alimentos armazenados. " << std::endl;
		std::cout << "4- ~> Visualizar tabela nutricional de todos os alimentos armazenados. " << std::endl;
		std::cout << "0- ~> Sair." << std::endl;
		std::cout << "$ ";
		std::cin.clear();
		std::cin >> option;
		switch (option)
		{
		case 1:
		{
			// Consultar refeicao
			int qty = 0;
			std::cout << "Por favor, informe a quantidade de alimentos da sua refeicao: " << std::endl;
			std::cin >> qty;
			std::cin.ignore();
			std::list<std::string> meal;
			std::string currentFood;
			for (int i = 0; i < qty; i++)
			{
				std::cout << "Informe a refeicao n" << i + 1 << " :" << std::endl ;
				std::cout << "$ ";
				getline(std::cin, currentFood);
				meal.push_back(currentFood);
			}
			// Imprime as informacoes nutricionais da refeicao
			bst.gerarInformacoesNutricionais(meal);
			std::cout << "Total de calorias consumidas: " << bst.totalDeCaloriasConsumidas(meal);
			std::cout << std::endl << "Digite uma tecla para continuar: " << std::endl;
			std::cin.ignore();
			std::cin.get();
			int clear = CLEAR_SCREAM();
			break;
		}
		case 2:
		{
			// Informacoes da arvore
			std::cout << bst;
			std::cout << std::endl << "Digite uma tecla para continuar: " << std::endl;
			std::cin.ignore();
			std::cin.get();
			int clear = CLEAR_SCREAM();
			break;
		}
		case 3:
		{
			// Imprime chaves em ordem
			bst.emOrdem(bst.getRaiz());
			std::cout << std::endl << "Digite uma tecla para continuar: " << std::endl;
			std::cin.ignore();
			std::cin.get();
			int clear = CLEAR_SCREAM();
			break;
		}
		case 4:
		{
			// Tabelas nutricionais
			bst.printDadosArvore();
			std::cout << std::endl << "Digite uma tecla para continuar: " << std::endl;
			std::cin.ignore();
			std::cin.get();
			int clear = CLEAR_SCREAM();
			break;
		}
		case 0:
		{
			break;
		}
		default:
			int clear = CLEAR_SCREAM();
			break;
		}
	} while (option != 0);


}
