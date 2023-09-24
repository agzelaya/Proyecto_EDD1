#include "TDAPila.h"

void TDAPila::anula(){
	for (int i = size; i > 0; i--) {
		delete array[i - 1];
	}
}

Object* TDAPila::tope(){//top
	if (array.vacia() != 0)
		return array[size - 1];
	else
		return null;
}

void TDAPila::mete(Object* data) {//push
	if (size==0)	
		array[size] = data;
	else
		array[size-1] = data;
}

Object* TDAPila::saca() {//pop
	Object* data = array[size - 1];
	array[size - 1] = null;
	return data;
}

void TDAPila::imprime_pila() {
	for (int i = size; i > 0; i--){
		cout << array[i - 1] << '\n';
	}
}