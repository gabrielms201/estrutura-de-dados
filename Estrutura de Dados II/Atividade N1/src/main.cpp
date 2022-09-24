#include "main.h"

int main(int argc, char* argv[])
{
    /*Food cenoura = Food("Cenoura", 300, 300, 300, 300, 300,300, 300, 300,300,300,300,300,300,
        300, 300,300,300,300,300,300,300, "Vegetal");
    std::cout << cenoura;*/

    menuArvore();

}

int menuArvore()
{
    ArvoreBST arv;
    int opcao, x;
    std::cout << ("\n***** Testando o TAD BST (Elementos do tipo int) ***** \n");

    do
    {
        std::cout << "\n\n";
        std::cout << "\n__________________________________________";
        std::cout << "\n\n\t   Menu - Arvore BST\n";
        std::cout << "\n__________________________________________";
        std::cout << "\n";
        std::cout << "\n ----1: Inserir";
        std::cout << "\n ----2: Excluir";
        std::cout << "\n ----3: Pesquisar";
        std::cout << "\n ----4: Imprimir em ordem";
        std::cout << "\n ----5: Qde de nos";
        std::cout << "\n ----6: Altura";
        std::cout << "\n ----7: Imprimir 2D";
        std::cout << "\n ----8: Informacoes";
        std::cout << "\n ----9: Sair do programa\n";
        std::cout << "\nOp: ";
        std::cin >> opcao;
        std::cout << "\n\n";
        switch (opcao)
        {
        case 1:
        {
            std::cout << "\n Informe o valor (int) -> ";
            std::cin >> x;
            arv.inserir(x);
            break;
        }
        case 2:
        {
            std::cout << "\n Informe o valor (int) -> ";
            std::cin >> x;
            No* resp = arv.excluir(arv.getRaiz(), x);
            arv.setRaiz(resp);
            if (resp != NULL)
                std::cout << "Raiz: " << resp->getChave() << std::endl;
            else
                std::cout << "A arvore esta vazia!" << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "\n Informe o valor da chave (int) -> ";
            std::cin >> x;
            //No *ret = arv.Pesquisar(x,arv.getRaiz());
            No* ret = arv.PesquisarRec(arv.getRaiz(), x);
            if (ret == NULL)
            {
                std::cout << "\n Chave nao encontrada! ";
            }
            else
            {
                std::cout << "\n Chave encontrada! ";
            }
            break;
        }
        case 4:
        {
            std::cout << "Percorrendo em ordem...\n";
            arv.emOrdem(arv.getRaiz());
            break;
        }
        case 5:
        {
            std::cout << "Qde de nos: " << arv.contarNos(arv.getRaiz());
            break;
        }
        case 6:
        {
            std::cout << "Altura da Arvore: " << arv.altura(arv.getRaiz());
            break;
        }
        case 7:
        {
            arv.print();

            break;
        }
        case 8:
        {
            //arv.infs(arv.getRaiz());
            std::cout << arv;
            break;
        }
        default:
            if (opcao != 9)
                std::cout << "\n Opcao invalida! \n\n\n";
        } // fim switch
    } while (opcao != 9);

    return 0;
}