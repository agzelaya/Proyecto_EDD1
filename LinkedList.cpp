#include "LinkedList.h"

#define NULL 0

LinkedList::LinkedList()
{
	inicio=NULL;
	final=NULL;
	n=0;
}

LinkedList::~LinkedList()
{
	if(inicio)
		delete inicio;
}