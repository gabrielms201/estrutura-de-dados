#include "CsvStorage.h"
#include <vector>


CsvStorage::CsvStorage(std::string filePath, ArvoreBST* bst)
	: _filePath(filePath), _bst(bst)
{
	_headerQuantity = 2;
	_delimiter = ',';
}
/// <summary>
/// Esse metodo abrir o CSV, pular os headers e então criar uma stream com os dados desse arquivo
/// Atraves dessa stream, o método StorageStreamIntoBST() é chamado.
/// </summary>
void CsvStorage::OpenFileAndStorage()
{
	// Aqui estamos criado um "Input File Stream" para podermos ler o arquivo no caminho (configurado no atributo) 
	// std::ifstream::in -> Modo de leitura (input)
	std::ifstream inputFile(_filePath, std::ifstream::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Erro tentando abrir o arquivo CSV\nPor favor verifique se o mesmo esta configurado corretamente.";
		exit(1);
	}
	// Stream que vai armazenar o conteudo do buffer.
	std::stringstream ss;
	// Leitura do buffer para dentro da stream
	ss << inputFile.rdbuf();

	// Aqui ignoramos os dois headers
	for (int i = 0; i < _headerQuantity; i++)
	{
		// String que vai armazenar o conteudo da linha da stream (temporario)
		std::string content;
		getline(ss, content);
		// Declaracao do delimitador do csv (baseado na separacao do primeiro header)
		if (i == 0)
			_delimiter = content.find(',') != string::npos ? ',' : ';';
	}
	// Chamada do método que vai armazenar o conteudo do a stream na BST 
	StorageStreamIntoBST(ss);


	if (inputFile.is_open())
	{
		inputFile.close();
	}
}

/// <summary>
/// Esse método recebe uma stream, que através dela realizará o filtro de cada linha armazenada e criará um "Food"
/// para cada linha armazenada (com seus respectivos atributos)
/// </summary>
/// <param name="stream"></param>
void CsvStorage::StorageStreamIntoBST(std::stringstream& stream)
{
	std::string content;
	while (getline(stream, content))
	{
		// Criacao da conteudo da linha
		istringstream line(content);
		// Para cada linha, vamos armazenar os atributos em um buffer
		std::string* buffer = new std::string[_atributesQuantity];

		unsigned short atributePosition = 0;
		while (getline(line, content, _delimiter))
		{
			content = (content == "") ? "0" : content;
			buffer[atributePosition] = content;
			atributePosition++;
		}

		std::string foodAndServing = buffer[0];
		int calories = stoi(buffer[1]);
		int caloriesFromFat = stoi(buffer[2]);
		double totalFatG = stod(buffer[3]);
		int totalFatDv = stoi(buffer[4]);
		int sodiumG = stoi(buffer[5]);
		int sodiumDv = stoi(buffer[6]);
		int potassiumG = stoi(buffer[7]);
		int potassiumDv = stoi(buffer[8]);
		int totalCarboHydrateG = stoi(buffer[9]);
		int totalCarboHydrateDv = stoi(buffer[10]);
		int dietaryFiberG = stoi(buffer[11]);
		int dieteryFiberDv = stoi(buffer[12]);
		int sugarsG = stoi(buffer[13]);
		int proteinG = stoi(buffer[14]);
		int vitaminADv = stoi(buffer[15]);
		int vitaminCDv = stoi(buffer[16]);
		int calciumDv = stoi(buffer[17]);
		int eeironeeDv = stoi(buffer[18]);
		double saturatedFatDv = stod(buffer[19]);
		int saturatedFatMgE = stoi(buffer[20]);
		int choleSterolDv = stoi(buffer[21]);
		int choleSterolMgE = stoi(buffer[22]);
		std::string foodType = buffer[23];

		Food food = Food(foodAndServing, calories, caloriesFromFat, totalFatG, totalFatDv, sodiumG, sodiumDv, potassiumG, potassiumDv,
			totalCarboHydrateG, totalCarboHydrateDv, dietaryFiberG, dieteryFiberDv, sugarsG, proteinG, vitaminADv, vitaminCDv, calciumDv, eeironeeDv, saturatedFatDv,
			saturatedFatMgE, choleSterolDv, choleSterolMgE, foodType);
		_bst->inserir(food);
		delete[] buffer;
	}
}


