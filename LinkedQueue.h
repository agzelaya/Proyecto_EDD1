#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "TDACola.h"

#include "Nodo.h"

class LinkedQueue : public TDACola
{
	public:
		LinkedQueue();
		~LinkedQueue();
		virtual Object* frente();
		
		virtual void imprime_cola();
		
		virtual void anula();
		
		////Dequeue
		//virtual Object* saca_de_cola(); 
		//
		//Queue
		virtual void pone_en_cola(Object*);
		
		virtual bool isEmpty();
	protected:
		Nodo* front;
		Nodo* back;
};

#endif