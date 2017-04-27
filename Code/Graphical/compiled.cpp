#include <iostream>
using namespace std;

class Fila {
	public:	
		Fila(int);
		~Fila();
		bool Insere(int);
		int Retira();
		bool Vazia();
		bool Cheia();
		bool Compara(Fila, int);
		
	private:
		// do, do#, re, re#, mi, fa, fa#, sol, sol#, la, la#, si [0 a 12]
		int *array;
		int frente;   //frente == primeiro elemento
		int tras;	  //tras   == ultimo elemento
		int tam;
		
		
};

Fila::Fila(int _tam){
	tam = _tam;
	array = new int[tam];
	frente = 0;
	tras = tam;
}


Fila::~Fila(){
	delete [] array;
}

bool Fila::Insere(int nota){
	if (!Fila::Cheia()) {
		array[tras] = nota;
		tras = (tras + 1)% tam;
		return true;
	}
	else
		return false;
}

int Fila::Retira(){
	int aux = 0;
	if (!Fila::Vazia()){
		aux = array[frente];
		frente = (frente + 1)% tam;
		return aux;
	}
	else
		return 0;
}

bool Fila::Vazia(){
	if (frente == tras)
		return true;
	else
		return false;
}

bool Fila::Cheia(){
	if ((tras + 1)% tam == frente)
		return true;
	else
		return false;
}


/*
bool Fila::Compara(Fila _fila, int _tam){
	int i;
	
	for (i=0; i < _tam; i++){
		if (this->array[i] != _fila.array[i]){ 
			return false;
			break;
		}
		else 
			return true;
	}
}; */

// esse metodo não está funcionando ainda 


int main(){
	
	
	
	return 0;
}
