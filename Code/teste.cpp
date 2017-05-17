#include <iostream>
#include "fila.h"
using namespace std;

int main(){
	
	int x;
	Fila fila2;
	Fila fila1;
	Fila fila3;
	Fila fila4;
	bool deuCerto;
	
	deuCerto = fila1.Vazia();
	if (deuCerto == true){
		cout  << "Vrau1" << endl;
	}
	
	fila1.Insere(1);
	fila1.Insere(2);
	fila1.Insere(3);
	fila1.Insere(3);
	fila1.Insere(3);
	fila1.Insere(3);
	fila1.Insere(3);
	fila1.Insere(3);
	fila1.Insere(3);
	fila1.Insere(3);
	/*
	x = fila1.Contador();
	cout << x << endl;
	x = fila1.Retira();
	cout << x << endl;
	x = fila1.Contador();
	cout << x << endl;
	x = fila1.Retira();
	cout << x << endl;
	x = fila1.Contador();
	cout << x << endl;
	*/
	fila2.Insere(1);
	fila2.Insere(2);
	fila2.Insere(3);
	fila2.Insere(3);
	fila2.Insere(3);
	fila2.Insere(3);
	fila2.Insere(3);
	fila2.Insere(3);
	fila2.Insere(3);
	fila2.Insere(3);

	fila3.Insere(10);
	fila3.Insere(20);
	fila3.Insere(30);
	fila3.Insere(30);
	fila3.Insere(30);
	fila3.Insere(30);
	fila3.Insere(30);
	fila3.Insere(30);
	fila3.Insere(30);
	fila3.Insere(30);

	fila4.Insere(2);
	fila4.Insere(2);

	if (fila1.Compara(fila1, fila2)){
		cout << "true" <<endl;
	}else{
		cout << "false" << endl;
	}

	if (fila1.Compara(fila1, fila4)){
		cout << "true" <<endl;
	}else{
		cout << "false" << endl;
	}
	if (fila1.Compara(fila1, fila3)){
		cout << "true" <<endl;
	}else{
		cout << "false" << endl;
	}
	return 0;
}