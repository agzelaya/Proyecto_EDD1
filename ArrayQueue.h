#pragma once

#include "TDACola.h"
#include "Alumno.h";

class ArrayQueue : public TDACola
{
	public:
		ArrayQueue();
		~ArrayQueue();
		
		virtual Object* frente();
		
		virtual void imprime_cola();
		
		virtual void anula();
		
		//Dequeue
		virtual Object* saca_de_cola(); 
		
		//Queue
		virtual void pone_en_cola(Object*);
		
		virtual bool isEmpty();

	protected:
		int front;
		int capacidad;
		int n;//size;
		int back;
		Object** array;
};
