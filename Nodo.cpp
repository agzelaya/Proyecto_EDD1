#include "Nodo.h"

#define NULL 0

Nodo::Nodo(){
	siguiente = NULL;
	item = NULL;
	anterior = NULL;
	 
}

Nodo::~Nodo(){
	if(siguiente)
		delete siguiente;
		
	if(item)
		delete item;
}

Nodo* Nodo::GetNext()
{
	return siguiente;
}

void Nodo::SetNext(Nodo* siguiente)
{
	this->siguiente = siguiente;
}

Nodo* Nodo::GetBack()
{
	return anterior;
}

void Nodo::SetBack(Nodo* anterior)
{
	this->anterior = anterior;
}

Object* Nodo::GetItem()
{
	return item;
}

void Nodo::SetItem(Object* item)
{
	this->item = item;
}
