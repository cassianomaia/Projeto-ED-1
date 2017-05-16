#include <iostream>
using namespace std;

class Fila {
	public:	
		Fila();
		Fila(int);
		~Fila();
		bool Insere(int);
		int Retira();
		bool Vazia();
		bool Cheia();
		bool Igual(Fila, Fila, int);
		int Contador(Fila);
		
	private:
		// do, do#, re, re#, mi, fa, fa#, sol, sol#, la, la#, si [1 a 13] //não usaremos 0 senão a lógica não funciona
		int *array;
		int frente;   //frente == primeiro elemento
		int tras;	  //tras   == ultimo elemento
		int tam;
		
		
};

Fila::Fila(){
}

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


bool Fila::Igual(Fila f1, Fila f2, int _tam){
	bool equalForNow;
	int deuCerto1, deuCerto2, aux;
	Fila fAux1;
	Fila fAux2;
	
	equalForNow = true;
	
	while ((f1.Vazia() == false) && (f2.Vazia() == false)) {
		deuCerto1 = f1.Retira();
		deuCerto2 = f2.Retira();
		if (deuCerto1 != 0)
			fAux1.Insere(deuCerto1);
		if (deuCerto2 != 0)
			fAux2.Insere(deuCerto2);
		//isso aqui checou se o número de elementos das filas era igual
		
		if ((deuCerto1 != 0) && (deuCerto2 == 0)){
			equalForNow = false;
		}
		if ((deuCerto1 == 0) && (deuCerto2 != 0)){
			equalForNow = false;
		}
		if ((deuCerto1 != 0) && (deuCerto2 != 0)){
			if (deuCerto1 != deuCerto2){
				equalForNow = false;
			}
		}
		
	} //checagem feita
	
	//voltando os elementos para suas filas
	while (fAux1.Vazia() != false){
		aux = fAux1.Retira();
		f1.Insere(aux);
	}
	
	while (fAux2.Vazia() != false) {
		aux = fAux2.Retira();
		f2.Insere(aux);
	}
	
	if (equalForNow == true)
		return true;
	else
		return false;
	
} 

// metodo adicionado, pronto para ser usado

int Fila::Contador(Fila f1){
	Fila fAux;
	int cont, x;
	
	while (f1.Vazia() != 1){
		x = f1.Retira();
		cont++;
		fAux.Insere(x);
	}
	
	while (fAux.Vazia() != 1){
		x = fAux.Retira();
		f1.Insere(x);
	}
	
	return cont;
}
