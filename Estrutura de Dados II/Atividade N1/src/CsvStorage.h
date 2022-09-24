#ifndef CSV_STORAGE_HEADER
#define CSV_STORAGE_HEADER

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "ArvoreBinaria.h"


class CsvStorage
{
private:
	// Atributos
	//			Caminho do arquivo
	std::string _filePath;
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

	// Construtor
	CsvStorage(std::string filePath, ArvoreBST* bst);

};

#endif