#ifndef TDACOLA_H
#define TDACOLA_H

#include "Object.h"
#include <iostream>
using namespace std;
class TDACola
{
	public:
		virtual Object* frente()=0;
		
		virtual void imprime_cola()=0;
		
		virtual void anula()=0;
		
		//Dequeue
		virtual Object* saca_de_cola()=0; 
		
		//Queue
		virtual void pone_en_cola(Object*)=0;
		
		virtual bool vacia()=0;
	protected:
};

#endif