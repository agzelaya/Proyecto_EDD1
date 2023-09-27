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
	if (pos_code>=0&&pos_code<=n)
	{
		Nodo* newNode = new Nodo(); 
		newNode->setItem(item);

		if (pos_code == 0)
		{
			if (!inicio)
			{
				final = newNode; 
			}
			else {
				Nodo* temp_siguiente = inicio; 
				temp_siguiente->setBack(newNode);
				newNode->setNext(temp_siguiente); 
			}
			inicio = newNode; 
		}
		else {
			if (pos_code == n) {
				Nodo* temp_anterior = final; 
				newNode->setBack(temp_anterior);
				temp_anterior->setNext(newNode);
				final = newNode;
			}
			else {
				int i = 0; 
				Nodo* temp = inicio; 
				while (i!=pos_code) 
				{
					temp = temp->getNext();
					i++;
				}
				Nodo* anterior = temp->getBack();
				Nodo* siguiente = temp; 
				newNode->setBack(anterior);
				newNode->setNext(siguiente);
				anterior->setNext(newNode);
				siguiente->setBack(newNode);

			}
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
	Nodo* siguiente = temp->getNext();
	return siguiente->getItem();
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
	Nodo* anterior = temp->getBack();
	return anterior->getItem();
}

void LinkedList::append(Object* item)//
{
	Nodo* newNode = new Nodo();
	newNode->setItem(item);
	n++;
	Nodo* temp_anterior = final;
	newNode->setBack(temp_anterior);
	temp_anterior->setNext(newNode);
	final = newNode; 
}

void LinkedList::imprimir_lista()
{
	Nodo* temp = inicio; 
	if (n > 0) {
		cout << "Lista: " << endl;
		while (temp) {
			cout << "->" << temp->getItem()->toString() <<endl; 
			temp = temp->getNext();
		}
	}
	else {
		cout << "Lista esta vacia\n";
	}
	
}

bool LinkedList::suprime(int pos)//
{
	int pos_code = pos - 1;
	Nodo* temp = inicio;
	if (pos_code>=0 && pos_code<=n)
	{
		int i = 0;
		while (i != pos_code)
		{
			temp = temp->getNext();
			i++;
		}
		if (pos ==0)
		{
			Nodo* newInicio = temp->getNext();
			newInicio->setBack(nullptr);
			temp->setNext(nullptr);
			inicio = newInicio;
			delete temp; 
		}
		else {
			if (pos ==n)
			{
				Nodo* newFin = temp->getBack();
				newFin->setNext(nullptr);
				temp->setBack(nullptr);
				final = newFin;
				delete temp; 
			}
			else {
				Nodo* siguiente = temp->getNext();
				Nodo* anterior = temp->getBack();
				anterior->setNext(siguiente);
				siguiente->setBack(anterior);
				temp->setBack(nullptr);
				temp->setNext(nullptr);
				delete temp;
			}
		}
		n--;
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
			return (i+1);
		}
		temp = temp->getNext();
		i++;
	}

	return -1;
}

Object* LinkedList::primero()
{
	return inicio->getItem();
}

bool LinkedList::vacia()
{
	if (!inicio)
	{
		return true;
	}else{ 
		return false; 
	}
	
}