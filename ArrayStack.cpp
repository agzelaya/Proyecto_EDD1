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

}

Object* ArrayStack::tope() {

}

void ArrayStack::mete(Object*) { //push

}

Object* ArrayStack::saca() { //pop

}

bool ArrayStack::vacia() {

}

void ArrayStack::imprime_pila() {

}