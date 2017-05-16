#ifndef FilaClass
#define Filaclass
#include <iostream>
using namespace std;

class Fila {
	public:	
		Fila(int);
		~Fila();
		bool Insere(char);
		char Retira(bool&);
		bool Vazia();
		bool Cheia();
		bool Igual(Fila&, Fila&, int);
		int Contador(Fila&);
		
	private:
		// do, do#, re, re#, mi, fa, fa#, sol, sol#, la, la#, si [1 a 13] //não usaremos 0 senão a lógica não funciona
		char *array;
		int frente;   //frente == primeiro elemento
		int tras;	  //tras   == ultimo elemento
		int tam;
		
		
};

Fila::Fila(int _tam){
	tam = _tam;
	array = new char[tam];
	frente = 0;
	tras = tam;
	
	for (i = 0; i< tam, i++){
		array[i] = "";
	}
}


Fila::~Fila(){
	delete [] array;
}

bool Fila::Insere(char nota){
	if (!Fila::Cheia()) {
		array[tras] = nota;
		tras = (tras + 1)% tam;
		return true;
	}
	else
		return false;
}

char Fila::Retira(&bool deuCerto){
	char aux = "";
	if (!Fila::Vazia()){
		aux = array[frente];
		frente = (frente + 1)% tam;
		return aux;
		deuCerto = true;
	}
	else
		deuCerto = false;
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


bool Fila::Igual(Fila &f1, Fila &f2, int _tam){
	bool equalForNow;
	char deuCerto1, deuCerto2, aux;
	Fila fAux1(50);
	Fila fAux2(50);
	
	
	equalForNow = true;
	
	while ((f1.Vazia() == false) && (f2.Vazia() == false)) {
		deuCerto1 = f1.Retira();
		deuCerto2 = f2.Retira();
		if (deuCerto1 != "")
			fAux1.Insere(deuCerto1);
		if (deuCerto2 != "")
			fAux2.Insere(deuCerto2);
		//isso aqui checou se o número de elementos das filas era igual
		
		if ((deuCerto1 != "") && (deuCerto2 == "")){
			equalForNow = false;
		}
		if ((deuCerto1 == "") && (deuCerto2 != "")){
			equalForNow = false;
		}
		if ((deuCerto1 != "") && (deuCerto2 != "")){
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

int Fila::Contador(Fila &f1){
	Fila fAux(50);
	int cont;
	char x;
	
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

#endif
