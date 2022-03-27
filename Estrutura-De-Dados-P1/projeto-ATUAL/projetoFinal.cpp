#include<iostream> 
 
#include"Pilha.h"  

using namespace std;  
  
 
int calculadoraPosFixa(string notacaoPosfixa)
{
	Pilha p;
	
    int tamanho = notacaoPosfixa.length();

    for (int x = 0; x < tamanho; x++)
    {

        if ( notacaoPosfixa[x] >= '0' &&  notacaoPosfixa[x] <= '9')
        {
            p.push( notacaoPosfixa[x] - '0');
        }

        else{
        	
            int n1 = p.topo();
            p.pop();
            
            int n2 = p.topo();
            p.pop();

			if (notacaoPosfixa[x] == '+' ) p.push(n2 + n1);
			if (notacaoPosfixa[x] == '-' ) p.push(n2 - n1);
			if (notacaoPosfixa[x] == '*' ) p.push(n2 * n1);
			if (notacaoPosfixa[x] == '/' ) p.push(n2 / n1);
			if (notacaoPosfixa[x] == '^' ) {
				int result = 1;
				for(int x = 0; x < n2; ++x){
					result *= n1;
				}
				p.push(result);
			}
        }
    }

    return p.topo();
}


bool operador(char);  
bool operando(char);  
bool igualOuMaior(char, char);  
string infixaParaPosfixa(string);  

bool operador(char ch) { 
 
	if(ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^' ) return true;     
	return false;  
	
}  
   
bool operando(char ch) {  

	if(ch >= '0' && ch <= '9') return true; 
	if (ch >= 'a' && ch <= 'z') return true;
	if( ch >= 'A' && ch <= 'Z') return true;  	 
	return false;  
	
}  
 
int comparativo(char oper) {  

	if(oper == '+' || oper == '-')  return 1;  
	if (oper == '*' || oper == '/') return 2;  
	if(oper == '^')return 3;       
	return 0; 
	
} 
  
bool igualOuMaior (char oper1, char oper2)  {  

	int n1 = comparativo(oper1);  
	int n2 = comparativo(oper2);  
	if (n1 == n2) {  
		if (oper1 == '^' ) return false;  
		return true;  
	}  
	return  (n1>n2 ? true : false);  
	
}  
   
string infixaParaPosfixa(string infixa)  
{  

	Pilha p;

	string posfixa ="";    
	char c;  
	  
	p.push( '(' );  
	infixa += ')';  
	  
	for(int x = 0; x < infixa.length(); x++) {  
		c = infixa[x];  
		  
		if (c == ' ') continue;  
		else if (c == '(') p.push(c);  
		else if (operando(c)) posfixa += c;  
		else if (operador(c)) {  
		
			while(!p.isEmpty() && igualOuMaior( p.topo(), c) ) {  
				posfixa += p.topo();  
				p.pop();  
				
			}  
			p.push(c);  
		}  
		else if(c == ')')  {  
			while(!p.isEmpty() && p.topo() != '(')  {   
			
				posfixa += p.topo();  
				p.pop();  
				
		}  
		p.pop();  
		}  
	}  
	return posfixa;  
}  

int main() {  

	string notacaoInfixa, notacaoPosfixa;  

	cout << " Digite a expressao infixa: ";  
	cin >> notacaoInfixa;  
	
	notacaoPosfixa = infixaParaPosfixa(notacaoInfixa);
	  
	cout << "\n Sua notacao infixa eh: " << notacaoInfixa;  
	cout << "\n notacao posfixa convertida: " << notacaoPosfixa;  
	
	cout << endl << endl << endl;
	
	
	string a, b, c, d, e, f, g, h, i, j , k, l, m, n , o, p, q, r, s ,t, u, v, x, w, y, z;

	string str =  "a+(b*c-(d/e-f)*g)*h";

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

	
	cout << endl << "VALORES:" << endl; 
	cout << "a = " << a << endl ;
	cout << "b = " << b << endl ;
	cout << "c = " << c << endl ;
	cout << "d = " << d << endl ;
	cout << "e = " << e << endl ;
	cout << "f = " << f << endl ;
	cout << "g = " << g << endl ;
	cout << "h = " << h << endl ;
	
	/*na expressao exemplo: a+(b*c-(d/e-f)*g)*h só existe valores até h, por isso só printei até h*/
	

	/*MODIFICAR O QUE FALTA AQUI*/	
		
	/* string expressaoPosFixa DEVE SER FEITA DE ACORDO COM VALORES PASSADOS PELO USARIO DE CADA LETRA*/
    string expressaoPosFixa = "123*45/6-7*-8*+";
    
    cout<<"RESULTADO (ainda nao eh o correto): ";
    cout<<calculadoraPosFixa(expressaoPosFixa);
    
	cout <<endl ;
	
	

	return 0;  
	
} 
