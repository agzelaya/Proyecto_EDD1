#include "ArrayList.h"

#define NULL 0

ArrayList::ArrayList()
{
	n=0;
	capacidad=10000;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad; i++)
		array[i] = NULL;
	
}

ArrayList::~ArrayList()
{
	//libera el contenido de las casillas
	for(int i=0; i<n; i++){
		if(array[i]){
			delete array[i];
			array[i] =NULL;
		}
	}
	//libera el arreglo
	delete[] array;
}

