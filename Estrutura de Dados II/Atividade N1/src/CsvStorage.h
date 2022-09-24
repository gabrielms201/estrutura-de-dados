#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include "ArvoreBinaria.h"


class CsvStorage
{
private:
	std::string _filePath;
	ArvoreBST* _bst;
	unsigned int _headerQuantity;
	static const unsigned int _atributesQuantity = 24;
	char _delimiter;
	void StorageStreamIntoBST(std::stringstream& stream);
public:
	void OpenFileAndStorage();
	CsvStorage(std::string filePath, ArvoreBST* bst);
};