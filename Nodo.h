#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo
{
	public:
		Nodo();
		~Nodo();
		
		//TODO: Hacer gets/sets
		
	protected:
		Nodo* siguiente;
		Object* item;
		Nodo* anterior;
};

#endif