#include "main.h"

int main(int argc, char* argv[])
{
    try
    {
        // Pegando dos parametros onde esta o arquivo
        std::string filePath = argc >= 2 ? argv[1] : "filtered_data.csv";

        ArvoreBST bst = ArvoreBST();
        // Objeto da classe que realiza o armazenamento do Csv dentro da BST
        CsvStorage storage = CsvStorage(filePath, &bst);
        // Metodo que armazena o Csv na BST
        storage.OpenFileAndStorage();
        // Chama o menu (metodo estatico da classe BSTViewer)
        BSTViewer::Menu(bst);

        return 0;
    }
    catch (std::exception ex)
    {
        std::cerr << "Execption ao rodar o FCRD: \n" << ex.what();
        exit(1);
    }

}