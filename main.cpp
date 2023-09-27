#include <iostream>
#include <windows.h>
#include <string>

#include "ArrayList.h"
#include "LinkedList.h"
#include "TDALista.h"
#include "TDAPila.h"
#include "TDACola.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "Alumno.h"
#include "Simbolo.h"
using namespace std;

bool validacion(int resp) {//Metodo para validar que la posicion ingresada sea mayor o igual a 1
	if (resp>=1)
	{
		return true;
	}
	else {
		cout << "! La posición debe ser un número mayor o igual a 1, intente de nuevo: ";
		return false;
	}
}
bool number(string id) {// metodo que valida que solo se ingresen numeros
	for (int i = 0; i < id.length(); i++)
	{
		char c = id[i];
		if (c<48||c>57)
		{
			cout << "! Se debe digitar un código de números";
			return false; 
		}
	}
	return true; 
}
bool validNumber(TDALista* lista, Alumno* alumno, int type) {//metodo que valida que el id de Alumno no se repita
	int i = 1; 
	if (type ==1)
	{
		while ((lista->recupera(i))) {
			Alumno* alumni = dynamic_cast<Alumno*>(lista->recupera(i));
			if ((alumni->equals(alumno)))
			{
				cout << "! El código de números debe ser único";
				return false;
			}
			i++;
		}
		return true;
	}
	else {
		if (lista->localiza(alumno)!=-1)
		{
			cout << "! El código de números debe ser único";
			return false; 
		}
		else {
			return true;
		}
	}
	
}

int mainMenu() {
	int x;
	cout << "\nMenú Principal\n  1. Trabajar con Listas\n  2. Trabajar con Pilas\n  3. Trabajar con Colas\n  4. Salir\nIngrese la opción: ";
	cin >> x;
	return x;
}

int menuTipoLista() {
	int x;
	cout << "\nMenú Tipo de Lista\n  1. Trabajar con ArrayList\n  2. Trabajar con Linked List\n  3. Regresar al Menú Principal\nIngrese la opción: ";
	cin >> x;
	return x;
}

int menuOpcLista() {
	int x;
	cout << "\nOpciones de Lista\n  1. Insertar Elemento\n  2. Imprimir Elementos\n  3. Buscar Elemento\n  4. Borrar Elemento\n"
		<< "  5. Ver si está vacía\n  6. Obtener Elemento por Posición\n  7. Obtener Siguiente\n  8. Obtener Anterior\n"
		<< "  9. Borrar todos los Elementos(Anula)\n  10. Regresar al Menú Anterior\nIngrese la opción: ";
	cin >> x;
	return x;
}

int menuTipoPila() {
	int x;
	cout << "\nMenú Tipo Pila\n  1. Trabajar con ArrayStack\n  2. Trabajar con LinkedStack\n  3. Regresar al Menú Principal\nIngrese la opción: ";
	cin >> x;
	return x;
}

int menuOpcPila() {
	int x;
	cout << "\nOperaciones de Pilas\n  1. “Empujar” (push)\n  2. “Sacar” (pop)\n  3. Ver Tope (top)\n"
		<< "  4. Verificar si está vacía\n  5. Imprimir elementos\n  6. Borrar todos los elementos\n  7. Regresar al Menú Anterior\nIngrese la opción: ";
	cin >> x;
	return x;
}

int menuTipoCola() {
	int x;
	cout << "\nMenú Tipo Cola\n  1. Trabajar con ArrayQueue\n  2. Trabajar con LinkedQueue\n  3. Regresar al Menú Principal\nIngrese la opción: ";
	cin >> x;
	return x;
}

int menuOpcCola() {
	int x;
	cout << "\nOperaciones de Colas\n  1. \"Encolar\" (queue)\n  2. \"Desencolar\" (dequeue)\n  3. Ver Frente (peek)\n"
		<< "  4. Verificar si está vacía\n  5. Imprimir elementos\n  6. Borrar los elementos\n  7. Regresar al Menú Anterior\nIngrese la opción: ";
	cin >> x;
	return x;
}

int main(int argc, char** argv) {
	SetConsoleOutputCP(CP_UTF8);

	int opc = 0;
	while (opc != 4) {
		opc = mainMenu();

		switch (opc) {
		//Listas
		case 1: {
			int tipo;
			bool inLoop = true;
			TDALista* lista = NULL; 

			while (inLoop) {
				tipo = menuTipoLista();
				if (tipo == 1 || tipo == 2) {
					if (tipo == 1) {
						lista = new ArrayList(); 
					}
					else {
						lista = new LinkedList();
					}
					Alumno* alumno = NULL; 
					int opcLista = menuOpcLista();


					while (opcLista != 10) {
						cout << endl; 
						switch (opcLista) {
						case 1: {//insertar elemento insertar
							bool resp = true; 
							string id = "";
							string nombre = "";
							int pos; 

							do
							{
								cout << "Ingrese el ID del alumno: ";
								do
								{
									cout << endl;
									cin >> id;
									alumno = new Alumno(nombre, id); 
								} while (!(number(id)) || !(validNumber(lista, alumno, tipo)));
								cout << "Ingrese el nombre del alumno: ";
								cin.ignore();
								getline(cin, nombre);
								cout << "Ingrese la posición a donde desea agregar elemento: ";
								do {
									cin >> pos;
								} while (!(validacion(pos)));

								alumno = new Alumno(nombre, id);
								bool retorno = lista->inserta(alumno, pos);
								if (retorno)
								{
									cout << "Se agregó alumno correctamente" << endl;
								}
								else {
									cout << "! Error al agregar alumno, posición no válida" << endl;
								}

								//Respuesta de Usuario 
								cout << "\n¿Desea introducir otro elemento? [0:no/1:si]: ";
								cin >> resp;
							} while (resp);
							
							break;
						}
						case 2: {//imprime los elementos
							lista->imprimir_lista();
							break;
						}
						case 3: {//busca un elemento
							string id = "";
							string nombre = " ";

							cout << "Ingrese el ID del alumno: ";
							do
							{
								cout << endl;
								cin >> id;
							} while (!(number(id)));

							Alumno* alumno2 = new Alumno(nombre, id); 
							int retorno = lista->localiza(alumno2); 
							if (retorno!=-1)
							{
								Alumno* alumni = dynamic_cast<Alumno*>(lista->recupera(retorno)); 
								nombre = alumni->GetName();
								cout << "El alumno "<<nombre<<" fue encontrado en la posición: "<<retorno << endl;
							}
							else {
								cout << "! El alumno no fue encontrado en la lista" << endl;
							}
							break;
						}
						case 4: {//borra elemento 
							int pos;
							cout << "Ingrese la posición del elemento a borrar: ";
							do {
								cin >> pos;
							} while (!(validacion(pos))); 

							bool retorno = lista->suprime(pos); 
							if (retorno)
							{
								cout << "Se borró alumno correctamente" << endl;
							}
							else {
								cout << "! Error al borrar alumno, posición no válida" << endl;
							}
							break;
						}
						case 5: {//mira si la lista esta vacia
							bool retorno = lista->vacia(); 
							if (retorno)
							{
								cout << "La lista está vacía" << endl;
							}
							else {
								cout << "La lista tiene "<<lista->getSize()<<" elemento(s)" << endl;
							}
							break;
						}
						case 6: {//obtener elemento por posicion -> recupera
							int pos;
							cout << "Ingrese la posición del elemento: ";
							do {
								cin >> pos;
							} while (!(validacion(pos)));

							Object* retorno = lista->recupera(pos); 
							if (retorno)
							{
								
								cout<<"\nElemento:\n -> " << retorno->toString() << endl;
							}
							else {
								cout << "! Posición no válida"<<endl; 
							}
							break;
						}
						case 7: {//siguiente elemento de posicion
							int pos;
							cout << "Ingrese la posición del elemento: ";
							do {
								cin >> pos;
							} while (!(validacion(pos)));

							Object* retorno = lista->siguiente(pos); 
							if (retorno)
							{

								cout << "\nSiguiente elemento:\n -> " << retorno->toString() << endl;
							}
							else {
								cout << "! El espacio siguiente está vacío" << endl;
							}
							break;
						}
						case 8: {//elemento anterior de posicion
							int pos;
							cout << "Ingrese la posición del elemento: ";
							do {
								cin >> pos;
							} while (!(validacion(pos)));
							Object* retorno = lista->anterior(pos); 
							if (retorno)
							{

								cout << "\nElemento anterior:\n -> " << retorno->toString() << endl;
							}
							else {
								cout << "! El espacio anterior está vacío" << endl;
							}
							break;
						}
						case 9: {//eliminar elementos de la lista
							lista->anula();
							break;
						}
						default: {cout << "\nOpción no válida\n"; }
						}
						opcLista = menuOpcLista();
					}
				}
				else if (tipo == 3) {
					inLoop = false;
				}
				else if (tipo > 3) {
					cout << "\nOpción no válida\n";
				}
			}
			break;
		}

		//Pilas
		case 2: {
			int tipo;
			bool inLoop = true;

			while (inLoop) {
				tipo = menuTipoPila();
				TDAPila* pila = NULL;
				if (tipo == 1 || tipo == 2) {
					if (tipo == 1) 
						pila = new ArrayStack();
					else 
						pila = new LinkedStack();

					Simbolo* symbol = NULL;
					int opcPila = menuOpcPila();
					while (opcPila != 7) {
						switch (opcPila) {
						case 1: {//“Empujar” (push) 
							string cadena; 
							char data; 
							cout << "Ingrese el símbolo que quiere agregar: ";
							cin.ignore();
							getline(cin, cadena); 
							data = cadena[0];
							symbol = new Simbolo(data);
							pila->mete(symbol);
							cout << "\nEl símbolo '" << symbol->toString() << "' se agregó correctamente!\n";
							break;
						}
						case 2: {//“Sacar” (pop)  
							Object* element = pila->saca();
							symbol = dynamic_cast<Simbolo*>(element);
							if (symbol)
								cout << "\nEl símbolo '" << symbol->toString() << "' fue removido éxitosamente!\n";
							else
								cout << "\nNo hay elementos en la pila.\n";
							break;
						}
						case 3: {//Ver Tope (top)  
							Object* element = pila->tope();
							symbol = dynamic_cast<Simbolo*>(element);
							
							if (symbol==NULL)
								cout << "\nEl tope es nulo" << '\n';
							else
								cout << "\nEl tope es: " << symbol->toString() << '\n';
							break;
						}
						case 4: {//Verificar si está vacía  
							string text = "";
							pila->isEmpty() ? text = "\nEstá Vacía\n" : text = "\nNo Está Vacía\n";
							cout << text;
							break;
						}
						case 5: {//print
							pila->imprime_pila();
							cout << '\n';
							break;
						}
						case 6: {//borrar todos los elementos
							pila->anula();
							cout << "\nLos elementos han sido borrados con éxito!\n";
							break;
						}
						default: {cout << "\nOpción no válida\n"; }

						}
						opcPila = menuOpcPila();
					}
				}
				else if (tipo == 3) {
					inLoop = false;
				}
				else if (tipo > 3) {
					cout << "\nOpción no válida\n";
				}
			}
			break;
		}

		//Colas
		case 3: {
			int tipo;
			bool inLoop = true;
			TDACola* cola = NULL;
			while (inLoop) {
				tipo = menuTipoCola();
				if (tipo == 1 || tipo == 2) {
					if (tipo == 1) {
						cola = new ArrayQueue();
					}
					else {
						cola = new LinkedQueue();
					}

					
					int opcCola = menuOpcCola();
					while (opcCola != 7) {
						switch (opcCola) {
						case 1: {
							string id;
							cout << "Ingrese el id del alumno: ";
							do
							{
								cout << endl;
								cin >> id;
							} while (!(number(id)));

							string nombre;
							cout << "Ingrese el nombre del alumno: ";
							cin.ignore();
							getline(cin, nombre);
							
							Alumno *alumno = new Alumno(nombre, id);
							cola->pone_en_cola(alumno);
							break;
						}
						case 2: {
							if(!cola->isEmpty())
								cout << "Alumno " << cola->saca_de_cola()->toString() << " ha sido sacado\n";
							else
								cout << "La cola está vacía\n";
							break;
						}
						case 3: {
							if(cola->frente())
								cout << "Frente: " << cola->frente()->toString() << endl;
							break;
						}
						case 4: {
							if (cola->isEmpty()) {
								cout << "Está Vacía\n";
							}
							else {
								cout << "No Está Vacía\n";
							}
							break;
						}
						case 5: {
							cola->imprime_cola();
							break;
						}
						case 6: {
							cola->anula();
							cout << "La cola ha sido vaciada\n";
							break;
						}
						default: {cout << "\nOpción no válida\n"; }

						}
						opcCola = menuOpcCola();
					}

				}
				else if (tipo == 3) {
					inLoop = false;
				}
				else if (tipo > 3) {
					cout << "\nOpción no válida\n";
				}
			}
			break;
		}
		case 4: {break; }
		default: {cout << "\nOpción no válida\n"; }
		}
	}

	return 0;
}
