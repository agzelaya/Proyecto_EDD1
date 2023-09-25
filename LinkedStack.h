#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "TDAPila.h"
#include "Nodo.h"
#include "Object.h"

class LinkedStack : public TDAPila{
	public:
		LinkedStack();
		~LinkedStack();
		
		virtual void anula();		
		virtual Object* tope();		
		virtual void mete(Object*);//push		
		virtual Object* saca();//pop	
		virtual bool isEmpty() { return size == 0; };//isempty
		virtual void imprime_pila();
		int getSize() { return size; }
	protected:
		Nodo* inicio;
};

#endif