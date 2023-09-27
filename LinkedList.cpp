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
	delete inicio; 
	n = 0;
}

bool LinkedList::inserta(Object* item, int pos)
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	if (pos_code>=0&&pos_code<=n)
	{
		Nodo* newNode = new Nodo(); 
		newNode->setItem(item);
		int i = 0;  
		while (i!=pos_code) 
		{
			temp = temp->getNext();
			i++;
		}
		if (inicio)
		{
			newNode->setBack(temp->getBack());
			newNode->setNext(temp); 
			newNode->getBack()->setNext(newNode);
			temp->setBack(newNode);
			NodesDefine(temp); 
		}
		else {
			inicio = newNode;
			final = newNode;  
		}
		
		n++;
		return true; 
	}
	else {
		return false;
	}
	
}

Object* LinkedList::siguiente(int pos)
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	int i = 0;
	while (i != pos_code)
	{
		temp = temp->getNext();
		i++;
	}
	
	return temp->getNext()->getItem();
}

Object* LinkedList::anterior(int pos)
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	int i = 0;
	while (i != pos_code)
	{
		temp = temp->getNext();
		i++;
	}

	return temp->getBack()->getItem(); 
}

void LinkedList::append(Object* item)//
{
	Nodo* temp = inicio;
	Nodo* newNode = new Nodo();
	newNode->setItem(item);
	n++;
	newNode->setBack(final);
	final->setNext(newNode);
	final = newNode; 
}

void LinkedList::imprimir_lista()
{
	Nodo* temp = inicio; 
	if (n > 0) {
		cout << "Lista: " << endl;
		while (temp->getNext()) {
			cout << "->" << temp->getItem()->toString() <<endl; 
			temp = temp->getNext();
		}
		cout << endl;
	}
	else {
		cout << "Lista esta vacia\n";
	}
	
}

bool LinkedList::suprime(int pos)
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	if (pos >= 1 && pos < n)
	{
		int i = 0;
		n--;
		while (i != pos_code)
		{
			temp = temp->getNext();
			i++;
		}
		temp->getNext()->setBack(temp->getBack());
		temp->getBack()->setNext(temp->getNext());
		temp->setBack(nullptr);
		temp->setNext(nullptr);
		NodesDefine(temp);
		return true;
	}
	else {
		return false;
	}
}

Object* LinkedList::recupera(int pos)
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	int i = 0;
	while (i != pos_code)
	{
		temp = temp->getNext();
		i++;
	}

	return temp->getItem();
}

int LinkedList::localiza(Object* item)//
{
	Nodo* temp = inicio; 
	int i = 0;
	while (temp->getNext())
	{
		if (temp->getItem()->equals(item))
		{
			return i;
		}
		temp = temp->getNext();
		i++;
	}

	return 0;
}

Object* LinkedList::primero()
{
	return inicio->getItem();
}

bool LinkedList::vacia()
{
	if (inicio)
	{
		return true;
	}else{ 
		return false; 
	}
	
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