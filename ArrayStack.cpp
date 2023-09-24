#include "ArrayStack.h"
#define NULL 0

ArrayStack::ArrayStack(){
	this->size=0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad;i++)
		array[i] = NULL;
}

ArrayStack::~ArrayStack(){
		//libera el contenido de las casillas
	for(int i=0; i<this->size; i++){
		if(array[i]){
			delete array[i];
		}
	}
	//libera el arreglo
	delete[] array;
}

void ArrayStack::anula() {
	for (int i = size; i > 0; i--) {
		delete array[i - 1];
	}
}

Object* ArrayStack::tope() {
	if (array.vacia() != 0)
		return array[size - 1];
	else
		return null;
}

void ArrayStack::mete(Object*) { //push
	if (size == 0)
		array[size] = data;
	else
		array[size - 1] = data;
}

Object* ArrayStack::saca() { //pop
	Object* data = array[size - 1];
	array[size - 1] = null;
	return data;
}

void ArrayStack::imprime_pila() {
	for (int i = size; i > 0; i--){
		cout << array[i - 1] << "\n";
	}
}