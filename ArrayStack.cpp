﻿#include "ArrayStack.h"
#define NULL 0

ArrayStack::ArrayStack(){
	this->size=0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad;i++)
		array[i] = NULL;
}

ArrayStack::~ArrayStack(){//libera el contenido de las casillas
	for(int i=0; i<this->size; i++){
		if(array[i]){
			delete array[i];
		}
	}
	//libera el arreglo
	delete[] array;
}

void ArrayStack::anula() {//elimina todos los elementos de la pila
	if (size != 0){
		for (int i = size; i > 0; i--) {
			delete array[i - 1];
		}
		size = 0;
	}
}

Object* ArrayStack::tope() {//retorna el primer elemento "tope" de la pila
	if (size != 0)
		return array[size - 1];
	else
		return NULL;
}

void ArrayStack::mete(Object* data) {//inserta un nuevo elemento a la pila
	if (size!=capacidad){
		size++;
		array[size - 1] = data;
	}else {
		cout << "La pila esta llena\n";
	}
}

Object* ArrayStack::saca() {//elimina el primer elemento de la pila (o el último que se añadió) y lo devuelve
	if (size != 0) {
		Object* data = array[size - 1];
		array[size - 1] = NULL;
		size--;
		return data;
	}else
		return NULL;
}

void ArrayStack::imprime_pila() {//imprime la pila desde el último elemento que se añadió hasta el primero (LIFO)
	if (size != 0){
		cout << "\nTope-> ";
		for (int i = size - 1; i >= 0; i--) {
			if (i == 0)
				cout << array[i]->toString() << " <-Fondo";
			else
				cout << array[i]->toString() << "\n       ";
		}
	}else
		cout << "\nLa pila esta vacia";
}