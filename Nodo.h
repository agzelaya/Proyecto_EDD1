#ifndef NODO_H
#define NODO_H
#include "Object.h"

class Nodo{
	public:
		Nodo* siguiente;
		Object* item;
		Nodo* anterior;

		Nodo();
		~Nodo();
		Nodo* getNext();
		void setNext(Nodo*);
		Nodo* getBack();
		void setBack(Nodo*);
		Object* getItem();
		void setItem(Object*);
};

#endif