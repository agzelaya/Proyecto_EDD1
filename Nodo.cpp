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

Nodo* Nodo::getNext(){
	return siguiente;
}

void Nodo::setNext(Nodo* siguiente){
	this->siguiente = siguiente;
}

Nodo* Nodo::getBack(){
	return anterior;
}

void Nodo::setBack(Nodo* anterior){
	this->anterior = anterior;
}

Object* Nodo::getItem(){
	return item;
}

void Nodo::setItem(Object* item){
	this->item = item;
}