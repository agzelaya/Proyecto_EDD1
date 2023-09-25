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