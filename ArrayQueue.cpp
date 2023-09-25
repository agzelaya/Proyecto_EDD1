#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
	front = 0;
	back = 0;
	n = 0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad; i++)
		array[i] = NULL;
}

//retorna el objeto que este en frente de la lista
Object* ArrayQueue::frente() {
	return array[front];
}

/*imprime los objetos en orden de salida
si inicio es menor que final, los imprime de forma normal
si inicio es mayor que final, utiliza la lógica de arreglo circular*/
void ArrayQueue::imprime_cola() {
	if (front < back) {
		for (int i = front; i <= back; i++){
			cout << array[i]->toString() << " <- ";
		}
	}
	else if (front < back) {
		int cont = 0;
		for (int i = front; i < capacidad; i++) {
			cout << array[i]->toString() << " <- ";
			cont++;
		}
		for (int i = 0; i <= back; i++){
			cout << array[i]->toString() << " <- ";
		}
	}
}

//recorre todo el arreglo, borra el obj solo si hay un objeto en esa posicion
void ArrayQueue::anula() {
	for (int i = 0; i < capacidad; i++){
		if (array[i] != NULL) {
			array[i] = NULL;
		}
		n = 0;
		front = 0;
		back = 0;
	}
}

/*en el caso de que last este en la ultima posicion del array, coloca obj en frente
sino, lo coloca en la posicion last+1*/
void ArrayQueue::pone_en_cola(Object* obj) {
	if(n != capacidad){
		if (front == (capacidad - 1) && front != back) {
			array[0] = obj;
			back = 0;
			n++;
		}
		else if (back == 0 && front == 0) {
			array[0] = obj;
			n++;
		}
		else{
			array[back + 1] = obj;
			back++;
			n++;
		}
	}
	else {
		cout << "\nLa cola esta llena\n";
	}
	
}

/*Saca al obj que esta en frente(en la posicion), cambia el valor de first*/
Object* ArrayQueue::saca_de_cola() {
	Object* temp = array[front];
	array[front] = NULL;
	if (front < capacidad - 1 && front != back) {
		front++;
		n--;
	}
	else {
		front = 0;
		n--;
	}
	return temp;
}

//retorna true si el size es 0
bool ArrayQueue::isEmpty() {
	return n == 0;
}

//utiliza logica igual a la de anula para eliminar los obj del arreglo circular
ArrayQueue::~ArrayQueue(){
	for (int i = 0; i < capacidad; i++) {
		if (array[i] != NULL) {
			delete array[i];
		}
	}

	//libera el arreglo
	delete[] array;
}