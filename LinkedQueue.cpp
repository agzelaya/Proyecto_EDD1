#include "LinkedQueue.h"

#define NULL 0

LinkedQueue::LinkedQueue()
{
	front = NULL;
	back=NULL;
}

//si front no es null, retorna el objeto en front
Object* LinkedQueue::frente() {
	if (front != NULL) {
		return front->getItem();
	}
}

/*si no hay elementos, añade un nodo como front y back, si hay por lo menos
un elemento, hace un enlazamiento de nodos con los ya existentes y pone el nuevo nodo en back*/
void LinkedQueue::pone_en_cola(Object* obj) {
	Nodo* temp = new Nodo();
	temp->setItem(obj);
	if (front == NULL) {
		front = temp;
		back = temp;
	}
	else {
		temp->setNext(front);
		front->setBack(temp);
		back = temp;
	}
}

//asigna temp al nodo front, si tiene un nodo siguiente, lo imprime
void LinkedQueue::imprime_cola() {
	Nodo* temp = new Nodo();
	if (front != NULL) {
		temp = front;
		while (temp->getNext()) {
			cout << "[" << temp->getItem() << "]" << " <= ";
			temp = temp->getNext();
		}
	}
}

//??
void LinkedQueue::anula() {
	/*Nodo* temp = new Nodo();
	if (front != NULL) {
		if (temp->getNext())
			delete temp->getNext();

		if (temp->getItem())
			delete temp->getItem();
	}*/
}

//retorna si la lista esta vacia
bool LinkedQueue::isEmpty() {
	return(front==NULL);
}

LinkedQueue::~LinkedQueue()
{
	if(back) //TODO: Revisar si se debe borrar el final o el inicial 
		delete back;
}