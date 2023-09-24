#include <iostream>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "TDALista.h"
#include "ArrayList.h"
#include "LinkedList.h"
using namespace std;

int mainMenu() {
	int x;
	cout << "\nMenú Principal\n  1. Trabajar con Listas\n  2. Trabajar con Pilas\n  3. Trabajar con colas\n  4. Salir\n";
	cin >> x;
	return x;
}

int menuTipoLista() {
	int x;
	cout << "\nMenú Tipo de Lista\n  1. Trabajar con ArrayList\n  2. Trabajar con Linked List\n  3. Regresar al Menú Principal\n";
	cin >> x;
	return x;
}

int menuOpcLista() {
	int x;
	cout << "\nOpciones de Lista\n  1. Insertar Elemento\n  2. Imprimir Elementos\n  3. Buscar Elemento\n  4. Borrar Elemento\n"
		<< "  5. Ver si está vacía\n  6. Obtener Elemento por Posición\n  7. Obtener Siguiente\n  8. Obtener Anterior\n"
		<< "  9. Borrar todos los Elementos(Anula)\n  10. Regresar al Menú Anterior\n";
	cin >> x;
	return x;
}

int menuTipoPila() {
	int x;
	cout << "\nMenú Tipo Pila\n  1. Trabajar con ArrayStack\n  2. Trabajar con LinkedStack\n  3. Regresar al Menú Principal\n";
	cin >> x;
	return x;
}

int menuOpcPila() {
	int x;
	cout << "\nOperaciones de Pilas\n  1. “Empujar”(push)\n  2. “Sacar”(pop)\n  3. Ver Tope(top)\n"
		<< "  4. Verificar si está vacía\n  5. Imprimir elementos\n  6. Borrar todos los elementos\n  7. Regresar al Menú Anterior\n";
	cin >> x;
	return x;
}

int menuTipoCola() {
	int x;
	cout << "\nMenú Tipo Cola\n  1. Trabajar con ArrayQueue\n  2. Trabajar con LinkedQueue\n  3. Regresar al Menú Principal\n";
	cin >> x;
	return x;
}

int menuOpcCola() {
	int x;
	cout << "\nOperaciones de Colas\n  1. \"Encolar\"(queue)\n  2. \"Desencolar\"(dequeue)\n  3. Ver Frente(peek)\n"
		<< "  4. Verificar si está vacía\n  5. Imprimir elementos\n  6. Borrar los elementos\n  7. Regresar al Menú Anterior\n";
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

			while (inLoop) {
				tipo = menuTipoLista();
				if (tipo == 1 || tipo == 2) {
					if (tipo == 1) {
						//*TDALista lista = new ArrayList();
					}
					else {
						//*TDACola lista = new LinkedList();
					}

					int opcLista = menuOpcLista();
					while (opcLista != 10) {
						switch (opcLista) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						case 5: {
							break;
						}
						case 6: {
							break;
						}
						case 7: {
							break;
						}
						case 8: {
							break;
						}
						case 9: {
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


		//pilas
		case 2: {
			int tipo;
			bool inLoop = true;

			while (inLoop) {
				tipo = menuTipoPila();
				if (tipo == 1 || tipo == 2) {
					if (tipo == 1) {
						//*TDACola pila = new ArrayStack();
					}
					else {
						//*TDACola pila = new LinkedStack();
					}

					int opcPila = menuOpcPila();
					while (opcPila != 7) {
						switch (opcPila) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						case 5: {
							break;
						}
						case 6: {
							break;
						}
						default: {cout << "\nOpción no valida\n"; }

						}
						opcPila = menuOpcCola();
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

			while (inLoop) {
				tipo = menuTipoCola();
				if (tipo == 1 || tipo == 2) {
					if (tipo == 1) {
						//*TDACola cola = new ArrayQueue();
					}
					else {
						//*TDACola cola = new LinkedQueue();
					}

					int opcCola = menuOpcCola();
					while (opcCola != 7) {
						switch (opcCola) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						case 5: {
							break;
						}
						case 6: {
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
