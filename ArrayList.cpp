#include "ArrayList.h"

//#define NULL 0

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
	for(int i=0; i<=n; i++){
		if(array[i]){
			delete array[i];
			array[i] =NULL;
		}
	}
	//libera el arreglo
	delete[] array;
}

void ArrayList::anula()
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

bool ArrayList::inserta(Object* elemento, int pos_list)
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

Object* ArrayList::siguiente(int pos_list)
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

Object* ArrayList::anterior(int pos_list)
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

void ArrayList::append(Object* elemento)
{
	n++;
	size++;
	array[n] = elemento;
}

void ArrayList::imprimir_lista()
{
	if (n > 0) {
		cout << "Lista: " << endl;
		for (int i = 0; i < n; i++) {
			cout<<" -> " << array[i]->toString()<<endl; 
		}
		cout << endl;
	}
	else {
		cout << "$ La lista esta vacia\n";
	}
	
}

bool ArrayList::suprime(int pos_list)
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


Object* ArrayList::recupera(int pos_list)
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

int ArrayList::localiza(Object* elemento)
{
	bool localizado = false;
	for (int i = 0; i <= n; i++)
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

Object* ArrayList::primero()
{
	return array[0];
}

bool ArrayList::vacia()
{
	if (!array[0]) {
		return true;
	}else{ 
		return false;
	}
}

