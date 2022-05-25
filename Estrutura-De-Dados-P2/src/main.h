/*
ESTRUTURA DE DADOS - P2 - Lista Encadeada
  Grupo:
    Caio Cezar Oliveira Filardi do Carmo        |   TIA: 31891365   |
    Mayara Meneghetti Honda	                    |   TIA: 32152280   |
    Paulo Henrique Braga Cechinel               |   TIA: 32151128   |
    Ricardo Gabriel Marques dos Santos Ruiz     |   TIA: 32134908   |
*/

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "Paciente.h"
#include "Fila.h"
#include "Lista.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

// Macro de compilacao para identificar o sistema na hora de limpar a tela
#ifdef WIN32 
    #define CLEAR_SCREAM() system("cls");
#else
    #define CLEAR_SCREAM() system("clear");
#endif


using namespace std;
using namespace chrono;

struct KEY_AND_VALUE
{
    string key;
    long value;
};
void submenuComorbidade(ostringstream& opcoes);
void submenuCovid(ostringstream& opcoes);
void submenuMorte(ostringstream& opcoes);
KEY_AND_VALUE consultar(ostringstream& opcoes, Lista& lista);
void testes(Lista& list);
void putContentIntoList(string filePath, Lista& list);
void menu(Lista& list);


#endif