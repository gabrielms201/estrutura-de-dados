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

	cout << " Digite a expressao infixa: ";  
	cin >> notacaoInfixa;  
	
	notacaoPosfixa = infixaParaPosfixa(notacaoInfixa);
	  
	cout << "\n Sua notacao infixa eh: " << notacaoInfixa << endl;  
	cout << "\n Notacao convertida para Posfixa : " << notacaoPosfixa;  
	
	cout << endl << endl;
	
	string a, b, c, d, e, f, g, h, i, j , k, l, m, n , o, p, q, r, s ,t, u, v, x, w, y, z;

	string str =  notacaoPosfixa;

	int tamanhoStr = str.length();
		
	if (str.find('a') <= tamanhoStr ) { cout << "Qual o valor da variavel 'a' ?"; cin >> a; }
	if (str.find('b') <= tamanhoStr ) { cout << "Qual o valor da variavel 'b' ?"; cin >> b; }
	if (str.find('c') <= tamanhoStr ) { cout << "Qual o valor da variavel 'c' ?"; cin >> c; } 
	if (str.find('d') <= tamanhoStr ) { cout << "Qual o valor da variavel 'd' ?"; cin >> d; } 
	if (str.find('e') <= tamanhoStr ) { cout << "Qual o valor da variavel 'e' ?"; cin >> e; } 
	if (str.find('f') <= tamanhoStr ) { cout << "Qual o valor da variavel 'f' ?"; cin >> f; } 
	if (str.find('g') <= tamanhoStr ) { cout << "Qual o valor da variavel 'g' ?"; cin >> g; } 
	if (str.find('h') <= tamanhoStr ) { cout << "Qual o valor da variavel 'h' ?"; cin >> h; } 
	if (str.find('i') <= tamanhoStr ) { cout << "Qual o valor da variavel 'i' ?"; cin >> i; } 
	if (str.find('j') <= tamanhoStr ) { cout << "Qual o valor da variavel 'j' ?"; cin >> j; } 
	if (str.find('k') <= tamanhoStr ) { cout << "Qual o valor da variavel 'k' ?"; cin >> k; } 
	if (str.find('l') <= tamanhoStr ) { cout << "Qual o valor da variavel 'l' ?"; cin >> l; } 
	if (str.find('m') <= tamanhoStr ) { cout << "Qual o valor da variavel 'm' ?"; cin >> m; } 
	if (str.find('n') <= tamanhoStr ) { cout << "Qual o valor da variavel 'n' ?"; cin >> n; } 
	if (str.find('o') <= tamanhoStr ) { cout << "Qual o valor da variavel 'o' ?"; cin >> o; } 
	if (str.find('p') <= tamanhoStr ) { cout << "Qual o valor da variavel 'p' ?"; cin >> p; } 
	if (str.find('q') <= tamanhoStr ) { cout << "Qual o valor da variavel 'q' ?"; cin >> q; } 
	if (str.find('r') <= tamanhoStr ) { cout << "Qual o valor da variavel 'r' ?"; cin >> r; } 
	if (str.find('s') <= tamanhoStr ) { cout << "Qual o valor da variavel 's' ?"; cin >> s; } 
	if (str.find('t') <= tamanhoStr ) { cout << "Qual o valor da variavel 't' ?"; cin >> t; } 
	if (str.find('u') <= tamanhoStr ) { cout << "Qual o valor da variavel 'u' ?"; cin >> u; } 
	if (str.find('v') <= tamanhoStr ) { cout << "Qual o valor da variavel 'v' ?"; cin >> v; } 
	if (str.find('x') <= tamanhoStr ) { cout << "Qual o valor da variavel 'x' ?"; cin >> x; } 
	if (str.find('w') <= tamanhoStr ) { cout << "Qual o valor da variavel 'w' ?"; cin >> w; } 
	if (str.find('y') <= tamanhoStr ) { cout << "Qual o valor da variavel 'y' ?"; cin >> y; } 
	if (str.find('z') <= tamanhoStr ) { cout << "Qual o valor da variavel 'z' ?"; cin >> z; } 

	
	string strArr[tamanhoStr];
	
	for (int cont = 0; cont < str.length(); cont++){
		
		if (str[cont] == '+' ) { strArr[cont] = '+'; } 
		if (str[cont] == '-' ) { strArr[cont] = '-'; } 
		if (str[cont] == '*' ) { strArr[cont] = '*'; } 
		if (str[cont] == '/' ) { strArr[cont] = '/'; } 
		if (str[cont] == '^' ) { strArr[cont] = '^'; } 
		
		if (str[cont] == 'a' ) { strArr[cont] = a; } 
		if (str[cont] == 'b' ) { strArr[cont] = b; } 
		if (str[cont] == 'c' ) { strArr[cont] = c; } 
		if (str[cont] == 'd' ) { strArr[cont] = d; } 
		if (str[cont] == 'e' ) { strArr[cont] = e; } 
		if (str[cont] == 'f' ) { strArr[cont] = f; } 
		if (str[cont] == 'g' ) { strArr[cont] = g; } 
		if (str[cont] == 'h' ) { strArr[cont] = h; } 
		if (str[cont] == 'i' ) { strArr[cont] = i; } 
		if (str[cont] == 'j' ) { strArr[cont] = j; } 
		if (str[cont] == 'k' ) { strArr[cont] = k; } 
		if (str[cont] == 'l' ) { strArr[cont] = l; } 
		if (str[cont] == 'm' ) { strArr[cont] = m; } 
		if (str[cont] == 'n' ) { strArr[cont] = n; } 
		if (str[cont] == 'o' ) { strArr[cont] = o; } 
		if (str[cont] == 'p' ) { strArr[cont] = p; } 
		if (str[cont] == 'q' ) { strArr[cont] = q; } 
		if (str[cont] == 'r' ) { strArr[cont] = r; } 
		if (str[cont] == 's' ) { strArr[cont] = s; } 
		if (str[cont] == 't' ) { strArr[cont] = t; } 
		if (str[cont] == 'u' ) { strArr[cont] = u; } 
		if (str[cont] == 'v' ) { strArr[cont] = v; } 
		if (str[cont] == 'x' ) { strArr[cont] = x; } 
		if (str[cont] == 'w' ) { strArr[cont] = w; } 
		if (str[cont] == 'y' ) { strArr[cont] = y; } 
		if (str[cont] == 'z' ) { strArr[cont] = z; } 

	
	}
	
	cout << endl << endl << endl;
	
	string expressaoFinal = "";
	string x1 = "";
	
	for (int xi = 0; xi < str.length(); xi++) {
		
		x1 = strArr[xi];
		expressaoFinal = expressaoFinal + x1;

		
	}

    cout<<"RESULTADO:  " << expressaoFinal << " = ";
    
    cout << calculadoraPosFixa(expressaoFinal);
    
	cout << endl ;
	
	return 0;  
	
}

/*
	FONTES:
	-> https://www.cplusplus.com/reference/string/string/length/
	-> https://www.cplusplus.com/reference/string/
	-> https://www.cplusplus.com/articles/1AUq5Di1/
*/
