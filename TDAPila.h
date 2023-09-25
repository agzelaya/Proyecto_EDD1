#ifndef TDAPILA_H
#define TDAPILA_H
#include "Object.h"
#include <iostream>
using namespace std;

class TDAPila {
	public:
		virtual void anula()=0;//vaciar
		virtual Object* tope()=0;//top
		virtual void mete(Object*)=0;//push
		virtual Object* saca()=0;//pop
		virtual bool isEmpty()=0 { return size == 0; };//isempty
		virtual void imprime_pila()=0;
		
	protected:
		int size;
};

#endif