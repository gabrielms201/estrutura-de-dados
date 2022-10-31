#include "Produto.h"

std::ostream& operator<<(std::ostream& os, const Produto& produto)
{
	os << "Codigo do Produto: " << produto.codigoProduto << ", "
		<< "Nome do Produto: " << produto.nome << ", "
		<< "Quantidade: " << produto.qtde << ", "
	    << "Valor Unitario: R$: " << produto.valorUnitario;
	return os;
}
Produto::Produto(int codigoProduto, const std::string& nome, int qtde, float valorUnitario)
	: codigoProduto(codigoProduto), nome(nome), qtde(qtde), valorUnitario(valorUnitario)
{

}