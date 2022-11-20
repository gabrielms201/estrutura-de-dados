// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#include "CsvManager.h"

// Construtor
CsvManager::CsvManager(std::string filePath, ArvoreBST* bst)
	: _filePath(filePath), _bst(bst)
{
	_headerQuantity = 2;
	_delimiter = ',';
	_backupPath = _filePath;
	_backupPath.replace(_backupPath.end() - 4, _backupPath.end(), "_bkp.csv");
}



/// <summary>
/// Esse metodo abrir o CSV, pular os headers e então criar uma stream com os dados desse arquivo
/// Atraves dessa stream, o método StorageStreamIntoBST() é chamado.
/// </summary>
void CsvManager::OpenFileAndStorage(CsvType type)
{
	// Aqui estamos criado um "Input File Stream" para podermos ler o arquivo no caminho (configurado no atributo) 
	// std::ifstream::in -> Modo de leitura (input)
	std::string path;
	if (type == CsvType::BACKUP)
		path = _backupPath;
	else
		path = _filePath;
	std::ifstream inputFile(path, std::ifstream::in);

	if (!inputFile.is_open())
	{
		std::string message = "Erro tentando abrir o arquivo CSV\n Por favor verifique se o caminho do mesmo esta configurado corretamente.";
		throw std::invalid_argument(message);
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

	// Após terminarmos o trabalho, precisamos fechar o arquivo.
	if (inputFile.is_open())
	{
		inputFile.close();
	}
}

void CsvManager::SaveBackup()
{
	// https://cplusplus.com/reference/fstream/ifstream/ifstream/
	std::ofstream backupFile(_backupPath, std::ifstream::out | std::ios_base::in | std::ios_base::trunc);

	std::list<std::string> lines = StorageBstIntoCsvLinesList();
	if (!backupFile.is_open())
	{
		std::string message = "Erro tentando abrir o arquivo CSV\n Por favor verifique se o caminho do mesmo esta configurado corretamente.";
		throw std::invalid_argument(message);
	}
	// Write each line
	backupFile << "header1,\n" << "header2,\n";
	for (list<std::string>::iterator it = lines.begin(); it != lines.end(); it++)
	{
		backupFile << *it;
		backupFile << "\n";
	}
	// Após terminarmos o trabalho, precisamos fechar o arquivo.
	if (backupFile.is_open())
	{
		backupFile.close();
	}
}
std::list<std::string> CsvManager::StorageBstIntoCsvLinesList() const
{
	std::list<std::string> lines = std::list<std::string>();
	if (_bst->getRaiz() != NULL)
		lines.push_back(_bst->getRaiz()->transformIntoCsvLine());
	StorageBstIntoCsvLinesList(lines, _bst->getRaiz());
	return lines;
}

const No* CsvManager::StorageBstIntoCsvLinesList(std::list<std::string>& lines, const No* node) const
{
	// pre ordem
	if (node != NULL)
	{
		const No* noEsquerda = StorageBstIntoCsvLinesList(lines, node->getEsq());
		if (noEsquerda != NULL)
			lines.push_back(noEsquerda->transformIntoCsvLine());
		const No* noDireita = StorageBstIntoCsvLinesList(lines, node->getDir());
		if (noDireita != NULL)
			lines.push_back(noDireita->transformIntoCsvLine());
		return node;
	}
	return NULL;
}


/// <summary>
/// Esse método recebe uma stream, que através dela realizará o filtro de cada linha armazenada e criará um "Food"
/// para cada linha armazenada (com seus respectivos atributos)
/// </summary>
/// <param name="stream"></param>
void CsvManager::StorageStreamIntoBST(std::stringstream& stream)
{
	std::string content;
	while (getline(stream, content))
	{
		// Criacao da conteudo da linha
		istringstream line(content);
		// Para cada linha, vamos armazenar os atributos em um buffer (tamanho do buffer estatico e constante definido na propria classe)
		std::string* atributes = new std::string[_atributesQuantity];

		unsigned short atributePosition = 0;
		while (getline(line, content, _delimiter))
		{
			content = (content == "") ? "0" : content;
			atributes[atributePosition] = content;
			atributePosition++;
		}
		// Obtem o objeto atraves do conversos de atributos
		Food food = ConvertAtributesIntoFood(atributes);

		_bst->inserir(food);
		delete[] atributes;
	}
}
/// <summary>
/// Atraves de um array, os atributos são armazenados em uma variável, que por sua vez serão utilizadas na criação do objeto
/// </summary>
/// <param name="atributes">: buffer</param>
/// <returns>Food</returns>
Food CsvManager::ConvertAtributesIntoFood(std::string* atributes)
{	// Poderiamos ter construido o objeto passando já a posicao do array para o construtor:
	// ex: Food food = Food(atributes[0], stoi[atributes[1], ..., stoi[atributes[N])
	// Mas com o intuito de promover a organizacao do codigo, mesmo com o custo de mais linhas, atribuimos cada valor em uma variavel
	// através disso, tornamos o nosso código mais legível
	std::string foodAndServing = atributes[0];
	int calories = stoi(atributes[1]);
	int caloriesFromFat = stoi(atributes[2]);
	double totalFatG = stod(atributes[3]);
	int totalFatDv = stoi(atributes[4]);
	int sodiumG = stoi(atributes[5]);
	int sodiumDv = stoi(atributes[6]);
	int potassiumG = stoi(atributes[7]);
	int potassiumDv = stoi(atributes[8]);
	int totalCarboHydrateG = stoi(atributes[9]);
	int totalCarboHydrateDv = stoi(atributes[10]);
	int dietaryFiberG = stoi(atributes[11]);
	int dieteryFiberDv = stoi(atributes[12]);
	int sugarsG = stoi(atributes[13]);
	int proteinG = stoi(atributes[14]);
	int vitaminADv = stoi(atributes[15]);
	int vitaminCDv = stoi(atributes[16]);
	int calciumDv = stoi(atributes[17]);
	int eeironeeDv = stoi(atributes[18]);
	double saturatedFatDv = stod(atributes[19]);
	int saturatedFatMgE = stoi(atributes[20]);
	int choleSterolDv = stoi(atributes[21]);
	int choleSterolMgE = stoi(atributes[22]);
	std::string foodType = atributes[23];

	Food food = Food(foodAndServing, calories, caloriesFromFat, totalFatG, totalFatDv, sodiumG, sodiumDv, potassiumG, potassiumDv,
		totalCarboHydrateG, totalCarboHydrateDv, dietaryFiberG, dieteryFiberDv, sugarsG, proteinG, vitaminADv, vitaminCDv, calciumDv, eeironeeDv, saturatedFatDv,
		saturatedFatMgE, choleSterolDv, choleSterolMgE, foodType);
	return food;
}


