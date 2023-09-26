#pragma once
#include "TDALista.h"
#include "iostream"
using namespace std;

class ArrayList : public TDALista
{
	public:
		ArrayList();
		~ArrayList();
		//--O(n)
		virtual void anula();
		virtual bool inserta(Object*,int);
		virtual Object* siguiente(int);
		virtual Object* anterior(int);
		virtual void append(Object*);
		virtual void imprimir_lista();
		virtual bool suprime(int);
		virtual Object* recupera(int);
		virtual int localiza(Object*);
		virtual Object* primero();
		virtual bool vacia();
		
	protected:
		Object** array;
		int capacidad;//limite?
		int n;//size
};
