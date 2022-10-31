#pragma once
#include <string>
#include <ostream>

struct Produto
{
	Produto(int codigoProduto, const std::string& nome, int qtde, float valorUnitario);
	int codigoProduto;
	std::string nome;
	int qtde;
	float valorUnitario;
};

std::ostream& operator<<(std::ostream& os, const Produto& produto);