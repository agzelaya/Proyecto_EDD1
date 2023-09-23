#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
	inicio = 0;
	final = 0;
	n = 0;
	capacidad = 10;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad; i++)
		array[i] = NULL;
}

ArrayQueue::~ArrayQueue()
{
	
	//TODO: Lógica para liberar arreglo circular
	for(int i=0; i<n; i++){
		if(array[i]){
			delete array[i];
		}
	}
	//libera el arreglo
	delete[] array;
}