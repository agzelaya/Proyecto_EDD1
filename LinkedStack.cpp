#include "LinkedStack.h"
#define NULL 0

LinkedStack::LinkedStack(){
	inicio = NULL;
	size = 0;
}

LinkedStack::~LinkedStack(){
	if(inicio)
		delete inicio;
}

void LinkedStack::anula() {//elimina los nodos
	cout << size << "\n";
	if (size != 0) {
		delete inicio;
		size = 0;
	}
}

Object* LinkedStack::tope() {//retorna el primer nodo "el tope" de la pila
	if (inicio != NULL)
		return inicio->getItem();
	else
		return NULL;
}

void LinkedStack::mete(Object* data) {//inserta un nuevo nodo al inicio de la pila (la izquierda)
	Nodo* temp = new Nodo();
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
	size++;
}

Object* LinkedStack::saca() { //elimina el primer nodo y lo retorne
	size--;
	if (inicio != NULL) {
		Object* temp = inicio->getItem();
		inicio = inicio->siguiente;
		return temp;
	}else
		return NULL;
}

void LinkedStack::imprime_pila() {//imprime todos los nodos de la pila (de izquierda a derecha)
	cout << "\nPila: ";
	Nodo* temp = inicio;
	while (temp) {
		if (temp->siguiente!=NULL)
			cout << temp->getItem()->toString() << "  ->  ";
		else 
			cout << temp->getItem()->toString();
		temp = temp->siguiente;
	}
}