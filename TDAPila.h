#ifndef TDAPILA_H
#define TDAPILA_H
#include "ArrayStack.h"
#include "Object.h"

class TDAPila {
	public:
		virtual void anula()=0;//vaciar
		virtual Object* tope()=0;//top
		virtual void mete(Object*)=0;//push
		virtual Object* saca()=0;//pop
		virtual bool vacia()=0;//isempty
		virtual void imprime_pila()=0;
		int getSize(){ return size; }
	protected:
		int size;
};

#endif