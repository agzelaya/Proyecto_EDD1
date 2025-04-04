#ifndef TDALISTA_H
#define TDALISTA_H

#include "Object.h"

class TDALista
{
	public:
		/*  
		
		*/
		virtual void anula()=0;
		
		
		/*
		 El método inserta revisa si la posición es válida
		 y si lo es, guarda el objeto del primer parámero en la 
		 posición indicada por el segundo parámetro
		*/
		virtual bool inserta(Object*,int)=0;
		virtual Object* siguiente(int)=0;
		virtual Object* anterior(int)=0;
		virtual void append(Object*)=0;
		virtual void imprimir_lista()=0;
		virtual bool suprime(int)=0;
		virtual Object* recupera(int)=0;
		virtual int localiza(Object*)=0;
		virtual Object* primero()=0;
		virtual bool vacia()=0;
		int getSize();
		
	protected:
		int size=0; 
};

#endif