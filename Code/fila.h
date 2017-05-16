#ifndef FilaClass
#define Filaclass

#include <iostream>
#include <cstdlib>
using namespace std;
bool deuCerto = true;

struct node{

    char info;

    struct node *next;

};

class Fila{

    private:

        node *tras;

        node *frente;

    public:

        Fila();

        void Insere(char);

        char Retira();
        
        bool Vazia();
        
        bool Compara(Fila&, Fila&);
        
        int Contador();
        
        
        


};

Fila::Fila(){

    tras = NULL;
    frente = NULL;

}

bool Fila::Vazia(){
	if (tras == NULL && frente == NULL)
		return 1;
	else
		return 0;
}

void Fila::Insere(char nota){

    node *temp = new node;
    
    if (Fila::Vazia() == 1){
    	temp->info = nota;
    	frente = temp;
    	tras = temp;
    	
    	
	} 
    
    if (Fila::Vazia() != 1){
	
    	temp->info = nota;
    	temp->next = frente;
    	tras->next = temp;
    	tras = temp;
	} 

}

char Fila::Retira(){

    node *temp = new node;
    char x;
    
    if (Fila::Vazia() != 1){
    	if (tras == frente){
    		x = tras->info;
    		frente = NULL;
    		tras = NULL;
    		
    		return x;
    		
		} else if (frente->next = tras){
			x = frente->info;
			temp = frente;
			frente = tras;
			delete temp;
			
			return x;
		} else {
			temp = tras;
    	x = tras->info;
    	tras->next = frente->next;
    	frente->next = frente;
    	
    	return x;
    	
    	delete temp;
		}
	} else
		deuCerto = false;

}

bool Fila::Compara(Fila &f1, Fila &f2){
	
	node *temp1 = new node;
	node *temp2 = new node;
	char aux;
	int cont1 = 0, cont2 = 0;
	Fila fAux1;
	Fila fAux2;
	bool igual = true;
	
	while (f1.Vazia() != 1){
		aux = f1.Retira();
		cont1++;
		fAux1.Insere(aux);
	}
	
	while (f2.Vazia() != 1){
		aux = f2.Retira();
		cont2++;
		fAux2.Insere(aux);
	}
	
	//viu se os tamanhos são iguais
	
	while (fAux1.Vazia() != 1){
		aux = fAux1.Retira();
		f1.Insere(aux);
	}
	
	while (fAux2.Vazia() != 1){
		aux = fAux2.Retira();
		f2.Insere(aux);
	}
	
	
	if (cont1 == cont2){
		temp1 = f1.frente;
		temp2 = f2.frente;
		do {
			if (temp2->info == temp1->info){
				temp1 = temp1->next;
				temp2 = temp2->next;
			} else
				igual = false;
				
		} while ((temp1 != f1.tras) && (temp2 != f2.tras));
	} else
		igual = false;
	
	
	if (igual == false)
		return false;
	else
		return true;
		
}


int Fila::Contador(){
	
	Fila fAux;
	int cont = 0;
	char aux;
	
	while (this->Vazia() != 1){
		aux = this->Retira();
		cont++;
		fAux.Insere(aux);
	}
	
	while (fAux.Vazia() != 1){
		aux = fAux.Retira();
		this->Insere(aux);
	}
	
	return cont;
}



#endif
