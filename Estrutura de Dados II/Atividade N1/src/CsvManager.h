// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#ifndef CSV_MANAGER_HEADER
#define CSV_MANAGER_HEADER

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "ArvoreBinaria.h"


class CsvManager
{
private:
	// Atributos
	//			Caminho do arquivo
	std::string _filePath;
	//			Caminho do arquivo de backup
	std::string _backupPath;
	//			Ponteiro para a arvore que sera populada
	ArvoreBST* _bst;
	//			Quantidade de headers do CSV
	unsigned int _headerQuantity;
	//			Quantidades de atributos de cada comida
	static const unsigned int _atributesQuantity = 24;
	//			Delimitador do CSV
	char _delimiter;

	// Metodos Privados (explicacao de cada um em suas implementacoes)
	void StorageStreamIntoBST(std::stringstream& stream);
	Food ConvertAtributesIntoFood(std::string* atributes);

public:
	// Metodos Publicos
	void OpenFileAndStorage();
	void SaveBackup();

	std::list<std::string> StorageBstIntoCsvLinesList() const;
	const No* StorageBstIntoCsvLinesList(std::list<std::string>& lines, const No* node) const;

	// Construtor
	CsvManager(std::string filePath, ArvoreBST* bst);


};

#endif