#include "LinkedQueue.h"

#define NULL 0

LinkedQueue::LinkedQueue()
{
	numFrente = NULL;
	final=NULL;
}

LinkedQueue::~LinkedQueue()
{
	if(final) //TODO: Revisar si se debe borrar el final o el inicial 
		delete final;
}