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
	if (size != 0) {
		delete inicio;
		size = 0;
		inicio = NULL;
	}
}

Object* LinkedStack::tope() {//retorna el primer nodo/el tope de la pila
	if (inicio)
		return inicio->getItem();
	else
		return NULL;
}

void LinkedStack::mete(Object* data) {//inserta un nuevo nodo al inicio de la pila (la izquierda)
	Nodo* temp = new Nodo();
	temp->setItem(data);

	if (inicio){
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

Object* LinkedStack::saca() { //elimina el primer nodo y lo retorna
	if (inicio) {
		size--;
		Object* temp = inicio->getItem();
		inicio = inicio->siguiente;
		return temp;
	}else
		return NULL;
}

void LinkedStack::imprime_pila() {//imprime todos los nodos de la pila (de izquierda a derecha) e indica el nodo inicial
	if (inicio) {
		Nodo* temp = inicio;
		cout << "\nPila: ";

		while (temp) {
			if (temp->siguiente != NULL)
				cout << temp->getItem()->toString() << "  ->  ";
			else
				cout << temp->getItem()->toString();
			temp = temp->siguiente;
		}

		cout << "\n      ^\n    inicio";
	}else
		cout << "\nLa pila esta vacia";
	
}