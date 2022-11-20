// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908
#include "main.h"

int main(int argc, char* argv[])
{
    try
    {
        // Pegando dos parametros onde esta o arquivo
        std::string filePath = argc >= 2 ? argv[1] : "filtered_data.csv";

        ArvoreBST bst = ArvoreBST();
        // Objeto da classe que realiza o armazenamento do Csv dentro da BST
        CsvManager manager = CsvManager(filePath, &bst);
        // Metodo que armazena o Csv na BST
        manager.OpenFileAndStorage();
        // Chama o menu (metodo estatico da classe BSTViewer)
        BSTManager::Menu(bst);

        return 0;
    }
    catch (std::exception ex)
    {
        std::cerr << "Exception ao rodar o FCRD: \n" << ex.what();
        exit(1);
    }

}