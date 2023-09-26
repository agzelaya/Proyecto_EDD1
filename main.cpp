#include <iostream>
#include <windows.h>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "ArrayList.h"
#include "LinkedList.h"
#include "TDALista.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "Alumno.h"
#include "Simbolo.h"
using namespace std;

int mainMenu() {
	int x;
	cout << "\nMenú Principal\n  1. Trabajar con Listas\n  2. Trabajar con Pilas\n  3. Trabajar con colas\n  4. Salir\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int menuTipoLista() {
	int x;
	cout << "\nMenú Tipo de Lista\n  1. Trabajar con ArrayList\n  2. Trabajar con Linked List\n  3. Regresar al Menú Principal\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int menuOpcLista() {
	int x;
	cout << "\nOpciones de Lista\n  1. Insertar Elemento\n  2. Imprimir Elementos\n  3. Buscar Elemento\n  4. Borrar Elemento\n"
		<< "  5. Ver si está vacía\n  6. Obtener Elemento por Posición\n  7. Obtener Siguiente\n  8. Obtener Anterior\n"
		<< "  9. Borrar todos los Elementos(Anula)\n  10. Regresar al Menú Anterior\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int menuTipoPila() {
	int x;
	cout << "\nMenú Tipo Pila\n  1. Trabajar con ArrayStack\n  2. Trabajar con LinkedStack\n  3. Regresar al Menú Principal\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int menuOpcPila() {
	int x;
	cout << "\nOperaciones de Pilas\n  1. “Empujar”(push)\n  2. “Sacar”(pop)\n  3. Ver Tope(top)\n"
		<< "  4. Verificar si está vacía\n  5. Imprimir elementos\n  6. Borrar todos los elementos\n  7. Regresar al Menú Anterior\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int menuTipoCola() {
	int x;
	cout << "\nMenú Tipo Cola\n  1. Trabajar con ArrayQueue\n  2. Trabajar con LinkedQueue\n  3. Regresar al Menú Principal\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int menuOpcCola() {
	int x;
	cout << "\nOperaciones de Colas\n  1. \"Encolar\"(queue)\n  2. \"Desencolar\"(dequeue)\n  3. Ver Frente(peek)\n"
		<< "  4. Verificar si está vacía\n  5. Imprimir elementos\n  6. Borrar los elementos\n  7. Regresar al Menú Anterior\n Ingrese la opcion: ";
	cin >> x;
	return x;
}

int main(int argc, char** argv) {
	SetConsoleOutputCP(CP_UTF8);
	//TDALista* lista = new ArrayList();
	////sin polimorfismo toma precedencia lo que está declarado
	//
	////con polimorfismo toma precedencia lo que está instanciado
	//
	//type_info(*lista).name(); 
	////usar

	//delete lista;

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
						//TDALista* lista = new LinkedList();
					}
					Alumno* alumno = NULL; 
					int opcLista = menuOpcLista();


					while (opcLista != 10) {
						switch (opcLista) {
						case 1: {//insertar elemento ? append o insertar
							string id = "";
							string nombre = "";
							int pos; 

							cout << "Ingrese el id del alumno: ";
							cin >> id;
							cout << "Ingrese el nombre del alumno: ";
							cin >> nombre;
							cout << "Ingrese la posicion a donde desea agregar elemento: ";
							cin >> pos;

							alumno = new Alumno(nombre, id); 
							bool retorno = lista->inserta(alumno, pos);
							cout << retorno<<endl;
							break;
						}
						case 2: {//imprimir elemento ? solo hay imprime lista
							lista->imprimir_lista();
							break;
						}
						case 3: {//buscar elemento -> localiza
							string id = "";
							string nombre = "";

							cout << "Ingrese el id del alumno: ";
							cin >> id;
							cout << "Ingrese el nombre del alumno: ";
							cin >> nombre;

							Alumno* alumno2 = new Alumno(nombre, id); 
							int retorno = lista->localiza(alumno2); 
							cout << retorno << endl;
							break;
						}
						case 4: {//borrar elemento -> suprime
							int pos;
							cout << "Ingrese la posicion del elemento a borrar: ";
							cin >> pos; 

							bool retorno = lista->suprime(pos); 
							cout << retorno << endl;
							break;
						}
						case 5: {//vacia
							bool retorno = lista->vacia(); 
							cout << retorno << endl;
							break;
						}
						case 6: {//obtener elemento por posicion -> recupera
							int pos;
							cout << "Ingrese la posicion del elemento: ";
							cin >> pos;

							Object* retorno = lista->recupera(pos); 
							cout << retorno->toString() << endl;
							break;
						}
						case 7: {//siguiente
							int pos;
							cout << "Ingrese la posicion del elemento: ";
							cin >> pos;

							Object* retorno = lista->siguiente(pos); 
							cout << retorno->toString() << endl;
							break;
						}
						case 8: {//anterior
							int pos;
							cout << "Ingrese la posicion del elemento: ";
							cin >> pos;
							Object* retorno = lista->anterior(pos); 
							cout << retorno->toString() << endl;
							break;
						}
						case 9: {//anula
							lista->anula();
							break;
						}
						default: {cout << "\nOpción no valida\n"; }
						}
						opcLista = menuOpcLista();
					}
				}
				else if (tipo == 3) {
					inLoop = false;
				}
				else if (tipo > 3) {
					cout << "\nOpción no valida\n";
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
					if (tipo == 1) {
						pila = new ArrayStack();
					}else {
						pila = new LinkedStack();
					}

					Simbolo* symbol = NULL;
					int opcPila = menuOpcPila();
					while (opcPila != 7) {
						switch (opcPila) {
						case 1: {//“Empujar” (push)  
							char data; 
							cout << "Ingrese el simbolo que quiere agregar: ";
							cin >> data;
							symbol->data = data;
							pila->mete(symbol);
							break;
						}
						case 2: {//“Sacar” (pop)  
							Object* element = pila->saca();
							symbol = dynamic_cast<Simbolo*>(element);

							cout << "El simbolo " << symbol->toString() << " fue removido exitosamente!\n";
							break;
						}
						case 3: {//Ver Tope (top)  
							Object* element = pila->tope();
							symbol = dynamic_cast<Simbolo*>(element);
							cout << "El tope es: " << symbol->toString() << '\n';
							break;
						}
						case 4: {//Verificar si está vacía  
							string text = "";
							pila->isEmpty() ? text = "La pila esta vacia\n" : text = "La pila esta llena\n";
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
							cout << "Los elementos han sido borrados con exito!\n";
							break;
						}
						default: {cout << "\nOpción no valida\n"; }

						}
						opcPila = menuOpcPila();
					}
				}
				else if (tipo == 3) {
					inLoop = false;
				}
				else if (tipo > 3) {
					cout << "\nOpción no valida\n";
				}
			}
			break;
		}

			  //colas
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
						//TDACola* cola = new LinkedQueue();
					}

					Alumno* alumno = NULL;
					int opcCola = menuOpcCola();
					while (opcCola != 7) {
						switch (opcCola) {
						case 1: {
							string id = "";
							string nombre = "";
							cout << "Ingrese el id del alumno: ";
							cin >> id;

							cout << "Ingrese el nombre del alumno: ";
							cin >> nombre;

							alumno = new Alumno(nombre, id);
							cola->pone_en_cola(alumno);
							break;
						}
						case 2: {
							if(!cola->isEmpty())
								cout << "Alumno " << cola->saca_de_cola()->toString() << " ha sido sacado\n";
							break;
						}
						case 3: {
							if(cola->frente())
								cout << "Alumno " << cola->frente()->toString() << " es primero en la cola\n";
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
						default: {cout << "\nOpción no valida\n"; }

						}
						opcCola = menuOpcCola();
					}

				}
				else if (tipo == 3) {
					inLoop = false;
				}
				else if (tipo > 3) {
					cout << "\nOpción no valida\n";
				}
			}
			break;
		}
		case 4: {break; }
		default: {cout << "\nOpción no valida\n"; }
		}
	}

	return 0;
}
