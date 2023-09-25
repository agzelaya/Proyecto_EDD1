#include "LinkedStack.h"
#define NULL 0

LinkedStack::LinkedStack(){
	inicio = NULL;
}

LinkedStack::~LinkedStack(){
	if(inicio)
		delete inicio;
}

void LinkedStack::anula() {
	delete inicio;
}

Object* LinkedStack::tope() {
	if (inicio != null)
		return inicio;
	else
		return null;
}

void LinkedStack::mete(Object* data) { //push
	Nodo* temp = data;
	if (inicio != null){
		inicio->anterior = temp;
		temp->siguiente = inicio;
		inicio = temp;
	}else {
		inicio = temp;
		inicio->anterior = null;
		inicio->siguiente = null;
	}
}

Object* LinkedStack::saca() { //pop
	if (inicio != null) {
		Nodo* temp = inicio;
		inicio = null;
		return temp->obj;
		//falta borrar temp
	}else
		return null;
}

void LinkedStack::imprime_pila() {
	for (int i = size; i > 0; i--) {
		cout << array[i - 1] << "\n";
	}
}