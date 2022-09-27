// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#ifndef BST_VIEWER_HEADER
#define BST_VIEWER_HEADER
#include <cstdlib>
// Macro de compilacao para identificar o sistema na hora de limpar a tela
#ifdef _WIN32
#define CLEAR_SCREAM() system("cls");
#else
#define CLEAR_SCREAM() system("clear");
#endif

#include "ArvoreBinaria.h"
#include <list>
#include <iostream>

class BSTViewer
{
public:
	static void Menu(ArvoreBST& bst);
};



#endif
