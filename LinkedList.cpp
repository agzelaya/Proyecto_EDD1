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

void LinkedList::anula()
{
}

bool LinkedList::inserta(Object* item, int pos)
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	if (pos>=1&&pos<=n)
	{
		Nodo* newNode = NULL;
		newNode->setItem(item);
		int i = 0; 
		n++; 
		while (i!=pos_code) 
		{
			temp = temp->getNext();
			i++;
		}
		newNode->setBack(temp->getBack());
		newNode->getBack()->setNext(newNode); 
		newNode->setNext(temp); 
		temp->setBack(newNode);
		NodesDefine(temp);
		return true; 
	}
	else {
		return false;
	}
	
}

Object* LinkedList::siguiente(int)
{
	return nullptr;
}

Object* LinkedList::anterior(int)
{
	return nullptr;
}

void LinkedList::append(Object*)
{
}

void LinkedList::imprimir_lista()
{
}

bool LinkedList::suprime(int)
{
	return false;
}

Object* LinkedList::recupera(int)
{
	return nullptr;
}

int LinkedList::localiza(Object*)
{
	return 0;
}

Object* LinkedList::primero()
{
	return nullptr;
}

bool LinkedList::vacia()
{
	return false;
}

void LinkedList::NodesDefine(Nodo* nodo) {
	Nodo* temp = nodo;
	while (temp->getBack())
	{
		temp = temp->getBack();
	}
	inicio = temp; 
	while (temp->getNext())
	{
		temp = temp->getNext();
	}
	final = temp; 
	
}