#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "TDAPila.h"

class ArrayStack : public TDAPila {
	public:
		ArrayStack();
		~ArrayStack();
		
		virtual void anula();//vaciar
		virtual Object* tope();		
		virtual void mete(Object*);//push		
		virtual Object* saca();//pop	
		virtual bool vacia() { return size == 0; };//isempty
		virtual void imprime_pila();
		
	protected:
		Object** array;
		int capacidad; 
		int n;
};

#endif