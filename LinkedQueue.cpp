#include "LinkedQueue.h"

#define NULL 0

LinkedQueue::LinkedQueue()
{
	front = NULL;
	back = NULL;
}

//si front no es null, retorna el objeto en front
Object* LinkedQueue::frente() {
	Nodo* temp = new Nodo();
	if (front != NULL) {
		temp = front;
	}
	else {
		cout << "La cola esta vacia\n";
	}
	return temp->getItem();
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
		temp->setNext(back);
		back->setBack(temp);
		back = temp;
	}

}

//saca de cola al elemento que esta en el nodo front
Object* LinkedQueue::saca_de_cola() {
	Nodo* temp = new Nodo();
	if (front != NULL) {
		temp = front;
		front = temp->getBack();
	}
	return temp->getItem();
}

//asigna temp al nodo front, si tiene un nodo anterior, lo imprime
void LinkedQueue::imprime_cola() {
	Nodo* temp = new Nodo();
	bool hasBack = true ;
	if (front != NULL) {
		temp = front;
		while (hasBack) {
			cout << "[ " << temp->getItem()->toString() << "]" << " <= ";
			if (temp->getBack() != NULL) { temp = temp->getBack(); }
			else {
				hasBack = false;
			}
			
		}
		cout << endl;
	}
	else {
		cout << "La cola esta vacia\n";
	}
}

//elimina toda la lista debido al destructor del objeto nodo
void LinkedQueue::anula() {
	delete front;
	front = NULL;
}

//retorna si la lista esta vacia
bool LinkedQueue::isEmpty() {
	return(front==NULL);
}

LinkedQueue::~LinkedQueue()
{
	if(front) 
		delete front;
}