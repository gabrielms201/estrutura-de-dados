
#include <iostream>

using namespace std;

typedef int Elem; 

const int TAM_PILHA = 100;

class Pilha {
	private:
   		int topoPilha;
   		Elem e[TAM_PILHA];
   	public:
   		Pilha();
   		~Pilha();
   		bool isEmpty();
   		bool isFull();
   		void push(Elem e);
   		Elem pop();
   		Elem topo(); 
		int size();		
};


Pilha::Pilha(){
  this->topoPilha = -1;
}

Pilha::~Pilha(){};

bool Pilha::isEmpty( ) {
  if (this->topoPilha == -1)
   	return true;
  else
   	return false;
}

bool Pilha::isFull( ){
  if (this->topoPilha == TAM_PILHA-1)
   	return true;
  else
   	return false;
}

void Pilha::push( Elem e ){
  if (! this->isFull( ))
    this->e[++this->topoPilha] = e;
  else 
    cout << "overflow - Estouro de Pilha";
}

Elem Pilha::pop( ){
  if (! this->isEmpty( ))
   return this->e[this->topoPilha--];
  else{
    cout << "underflow - Esvaziamento de Pilha";
    return -1;
  }
}

Elem Pilha::topo( ){
  if ( ! this->isEmpty( ))
   	return this->e[this->topoPilha];
  else{
    cout << "underflow - Esvaziamento de Pilha";
    return -1;
  }
}

int Pilha::size( ){
  return topoPilha+1;
}



