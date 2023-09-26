#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "TDAPila.h"
#include "Object.h"

class ArrayStack : public TDAPila {
	public:
		ArrayStack();
		~ArrayStack();
		
		virtual void anula();//vaciar
		virtual Object* tope();		
		virtual void mete(Object*);//push		
		virtual Object* saca();//pop	
		virtual bool isEmpty() { return size == 0; };//isempty
		virtual void imprime_pila();
		int getSize() { return size; }
		
	protected:
		Object** array;
		int capacidad; 
		int size;//size
};

#endif