#include "LinkedStack.h"

#define NULL 0

LinkedStack::LinkedStack()
{
	inicio = NULL;
}

LinkedStack::~LinkedStack()
{
	if(inicio)
		delete inicio;
}