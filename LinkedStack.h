#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "TDAPila.h"

#include "Nodo.h"

class LinkedStack : public TDAPila
{
	public:
		LinkedStack();
		~LinkedStack();
		
		//virtual void anula();		
		//virtual Object* tope();		
		//virtual void mete(Object*);//push		
		//virtual Object* saca();//pop	
		//virtual bool vacia();		
		//virtual void imprime_pila();
	protected:
		Nodo* inicio;
};

#endif