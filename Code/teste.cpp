#include <iostream>
#include "fila.h"
using namespace std;

int main(){
	
	int x;
	Fila fila2;
	Fila fila1;
	bool deuCerto;
	
	deuCerto = fila1.Vazia();
	if (deuCerto == true){
		cout  << "Vrau1" << endl;
	}
	
	fila1.Insere(1);
	fila1.Insere(2);
	fila1.Insere(3);
	fila1.Insere(4);
	
	x = fila1.Contador();
	cout << x << endl;
	/*
	x = fila1.Retira();
	cout << x << endl;
	x = fila1.Contador();
	cout << x << endl;
	
	fila2.Insere(1);
	fila2.Insere(2);
	deuCerto = fila1.Compara(fila1, fila2);
	if (deuCerto == true){
		cout << "vrau2" <<endl;
	}else{
		cout << "vrau3" << endl;
	}
	x = fila2.Contador();
	cout << x << endl;
	*/
	return 0;
}