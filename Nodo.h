#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo{
	public:
		Nodo();
		~Nodo();
		Nodo* GetNext();
		void SetNext(Nodo*);
		Nodo* GetBack();
		void SetBack(Nodo*);
		Object* GetItem();
		void SetItem(Object*);
		
		//TODO: Hacer gets/sets
		
	protected:
		Nodo* siguiente;
		Object* item;
		Nodo* anterior;
};

#endif