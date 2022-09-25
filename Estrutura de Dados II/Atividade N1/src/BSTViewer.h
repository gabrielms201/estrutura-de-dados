#ifndef BST_VIEWER_HEADER
#define BST_VIEWER_HEADER
// Macro de compilacao para identificar o sistema na hora de limpar a tela

#include <cstdlib>
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
