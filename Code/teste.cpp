#include <iostream>
#include "fila.h"
using namespace std;

int main(){
	
	int x;
	Fila fila2;
	Fila fila1;
	
	deuCerto = fila1.Vazia();
	if (deuCerto == true){
		cout  << "Vrau1" << endl;
	}
	
	fila1.Insere('a');
	fila1.Insere('b');
	
	x = fila1.Contador();
	
	cout << x << endl;
	
	return 0;
}