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
	if (size != 0)
		delete inicio;
}

Object* LinkedStack::tope() {
	if (inicio != NULL)
		return inicio->getItem();
	else
		return NULL;
}

void LinkedStack::mete(Object* data) { //push
	Nodo* temp = NULL;
	temp->setItem(data);

	if (inicio != NULL){
		inicio->anterior = temp;
		temp->siguiente = inicio;
		inicio = temp;
	}else {
		inicio = temp;
		inicio->anterior = NULL;
		inicio->siguiente = NULL;
	}
}

Object* LinkedStack::saca() { //pop
	if (inicio != NULL) {
		Object* temp = inicio->getItem();
		inicio = inicio->siguiente;
		return temp;
	}else
		return NULL;
}

void LinkedStack::imprime_pila() {
	Nodo* temp = inicio;
	while (temp) {
		cout << temp->getItem();
		temp = temp->siguiente;
	}
}