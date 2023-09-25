#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "TDAPila.h"
#include "Nodo.h"i

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
	protected:
		Nodo* inicio;
};

#endif