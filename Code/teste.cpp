#include<iostream>
#include "fila.h"
using namespace std;

int main(){
	bool certo;
	Fila fila1(10);
	certo = fila1.Vazia();
	if (certo == true){
		cout  << "Vrau" << endl;
	}
	fila1.Insere('a');

	Fila fila(10);
	fila2.Insere('a');
	certo = fila1.Igual(fila1, fila2, 10);
	if (certo == true){
		cout  << "Vrau" << endl;
	}






	return 0;
}