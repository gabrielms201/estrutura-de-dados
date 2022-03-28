/*
P1 - Estrutura de Dados
Grupo:
Brian Diniz Bracco						| TIA: 41517687
Mayara Meneghetti Honda					| TIA: 32152280
Paulo Henrique Braga Cechinel			| TIA: 32151128
Ricardo Gabriel Marques dos Santos Ruiz | TIA: 32134908
*/

#include "ProjetoFinal.h"
int main()
{  
	string notacaoInfixa, notacaoPosfixa;  

	cout << " Digite a expressao infixa: (COM LETRAS MAIUSCULAS) ";  
	cin >> notacaoInfixa;  

	notacaoPosfixa = Calculadora::InfixaParaPosfixa(notacaoInfixa);

	cout << "\n Sua notacao infixa eh: " << notacaoInfixa;  
	cout << "\n notacao posfixa convertida: " << notacaoPosfixa;  

	cout << endl << endl << endl;

	// string str =  "A+(B*C-(D/E-G)*G)*H";
	string str =  notacaoInfixa;

	int tamanhoStr = str.length(); // https://www.cplusplus.com/reference/string/string/length/

	char alfabeto[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
						'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	FilaCircular letrasPresentes = FilaCircular();
	for (int i = 0; i < 26; i++)
	{
		char letra = alfabeto[i];
		string valorLetra;
		if (str.find(letra) <= tamanhoStr) 
		{
			cout << "Qual o valor da variavel '" << letra << "'? "; cin >> valorLetra;
			CHAVE_VALOR chaveValor = {letra, valorLetra};
			letrasPresentes.enqueue(chaveValor);
		}
	};

	for (int i = 0; i < letrasPresentes.size(); i++)
	{
		CHAVE_VALOR chaveValor = letrasPresentes.dequeue();
		cout << chaveValor.letra << " = " << chaveValor.valor << endl;
		letrasPresentes.enqueue(chaveValor);
	}

	/*na expressao exemplo: A+(B*C-(D/E-G)*H)*H s� existe valores at� H, por isso s� printei at� H*/


	/*MODIFICAR O QUE FALTA AQUI*/	

	/* string expressaoPosFixa DEVE SER FEITA DE ACORDO COM VALORES PASSADOS PELO USARIO DE CADA LETRA*/
    string expressaoPosFixa = "123*45/6-7*-8*+";

    cout << "RESULTADO (ainda nao eh o correto): ";
    cout << Calculadora::CalculadoraPosFixa(expressaoPosFixa);

	cout << endl ;
	return 0;  

}

/*
	FONTES:
	-> https://www.cplusplus.com/reference/string/string/length/
	-> https://www.cplusplus.com/reference/string/
	-> https://www.cplusplus.com/articles/1AUq5Di1/
*/
