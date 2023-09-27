#include "ArrayList.h"

//#define NULL 0

ArrayList::ArrayList()//Constructor
{
	n=0;
	capacidad=10000;
	array = new Object*[capacidad];
	for(int i=0; i<capacidad; i++)
		array[i] = NULL;
	
}

ArrayList::~ArrayList()//Desctructor
{
	//libera el contenido de las casillas
	for(int i=0; i<=n; i++){
		if(array[i]){
			delete array[i];
			array[i] =NULL;
		}
	}
	//libera el arreglo
	delete[] array;
}

void ArrayList::anula()//Libera memoria al borrar elementos de la lista
{
	for (int i = 0; i <= n; i++)
	{
		if (array[i]) {
			delete array[i];
			array[i] = NULL;
		}
	}
	n = 0;
	size=0;
}

bool ArrayList::inserta(Object* elemento, int pos_list)//Inserta los elementos a la lista
{
	
	int pos_code = pos_list - 1;
	if (pos_code<n+1)
	{
		for (int i = 0; i <= n; i++)
		{
			if (i==pos_code)
			{
				if (!array[i])
				{
					array[i] = elemento; 
					n++;
				}
				else {
					n++;
					for (int j = n; j >=i; j--)
					{
						if (j!=i)
						{
							array[j] = array[j - 1];
						}
						else {
							array[j] = elemento;
						}
						
					}
				}
				break;
			}
		}
		size++;
		return true;
	}
	else {
		return false;
	}
}

Object* ArrayList::siguiente(int pos_list)//Devuelve el elemento siguiente a la posicion dada
{
	int pos_code = pos_list - 1;
	if (array[pos_code+1]&&pos_code<n)
	{
		return array[pos_code + 1];
	}
	else {
		return nullptr;
	}
}

Object* ArrayList::anterior(int pos_list)//Devuelve el elemento anterior a la posicion dada
{
	int pos_code = pos_list - 1;
	if (pos_code>0&&pos_code<=n)
	{
		if (array[pos_code - 1])
		{
			return array[pos_code - 1];
		}
	}
	else {
		return nullptr;
	}
}

void ArrayList::append(Object* elemento)//Agrega el elemento al final de la lista
{
	n++;
	size++;
	array[n] = elemento;
}

void ArrayList::imprimir_lista()//Imprime lista en el formato dado
{
	if (n > 0) {
		cout << "Lista: " << endl;
		for (int i = 0; i < n; i++) {
			cout<<" -> " << array[i]->toString()<<endl; 
		}
	}
	else {
		cout << "$ La lista esta vacia\n";
	}
	
}

bool ArrayList::suprime(int pos_list)//Borra elementos de la lista
{
	int pos_code = pos_list - 1;
	bool deleted = false;
	if (pos_code < n)
	{
		for (int i = 0; i <= n; i++)
		{
			if (i == pos_code)
			{
				array[i] = NULL;

				if (i != n)
				{
					deleted = true;
					array[i] = array[i + 1];
				}
			}
			if (deleted && i < n)
			{
				array[i] = array[i + 1];
			}
			if (i == n)
			{
				array[i] = NULL;
			}
			
		}
		n--;
		size--;
		return true;
	}
	else {
		return false;
	}
}


Object* ArrayList::recupera(int pos_list)//Retorna un objeto de la posicion dada
{
	int pos_code = pos_list - 1;
	if (pos_code>=0)
	{
		return array[pos_code];
	}
	else {
		return nullptr;
	}
	
}

int ArrayList::localiza(Object* elemento)//Busca la posicion en la lista del objeto dado, de no ser encontrado retorna -1 
{
	bool localizado = false;
	for (int i = 0; i < n; i++)
	{
		if (array[i]->equals(elemento))
		{
			localizado = true;
			return (i + 1);
		}
	}
	if (!localizado)
	{
		return -1;
	}
	
}

Object* ArrayList::primero()//devuelve 1er elemento 
{
	return array[0];
}

bool ArrayList::vacia()//Rebisa si lista esta o no vacia
{
	if (!array[0]) {
		return true;
	}else{ 
		return false;
	}
}

