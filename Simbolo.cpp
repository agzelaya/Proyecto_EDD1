#include "Simbolo.h"

Simbolo::Simbolo(char data){
	this->data = data;
}

Simbolo::~Simbolo(){
	data = NULL;
}

//compara dos elementos usando dynamic cast para castearlo a símbolo y compararlo propiamente
bool Simbolo::equals(Object* objeto){
	Simbolo* temp = dynamic_cast<Simbolo*>(objeto);
	if (this->data == temp->data)
		return true;
	else
		return false;
}

string Simbolo::toString(){//convierte el atributo de char en string
	string text = "";
	text += data;
	return text;
}